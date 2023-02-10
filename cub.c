/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:31:44 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/10 14:57:25 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_name(char *str)
{
	while (*str)
	{
		if (*str == '.')
		{
			if (strcmp(str + 1, "cub"))
			{
				exit(EXIT_FAILURE);
			}
			else
				break ;
		}
		str++;
	}
}

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	return (fd);
}

char	*read_meta_data(int fd, t_data *data)
{
	char	*line;
	char	*tmp;
	int		z;

	line = NULL;
	tmp = NULL;
	z = 0;
	while (!z)
	{
		line = get_next_line(fd);
		if (!line || start_one(line))
		{
			z = 1;
			break ;
		}
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		line = ft_strtrim(line, " \t");
		tmp = ft_strjoin_mod(tmp, line);
		free(line);
	}
	data->first_line = line;
	return (tmp);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

void	raycast(t_data *img)
{
	int			x;
	int			map_x;
	int			map_y;
	static long	frame = 0;

	x = 0;
	while (x < SCREENWIDTH)
	{
		// calculate ray position and direction
		double cameraX = 2 * x / (double)(SCREENWIDTH)-1; // x-coordinate in camera space
		double rayDirX = img->dirX + +img->planeX * cameraX;
		double rayDirY = img->dirY + img->planeY * cameraX;
		// which box of the map we're in
		map_x = (int)(img->posX);
		map_y = (int)(img->posY);

		// length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		// length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;

		// what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; // was there a wall hit?
		int side;	 // was a NS or a EW wall hit?
		// calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (img->posX - map_x) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (map_x + 1.0 - img->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (img->posY - map_y) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (map_y + 1.0 - img->posY) * deltaDistY;
		}
		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				map_x += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				map_y += stepY;
				side = 1;
			}
			// Check if ray has hit a wall
			if (ft_strlen(img->s[map_x]) > (size_t)map_y)
			{
				if (img->s[map_x][map_y] == '1')
					hit = 1;
			}
		}
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		// Calculate height of line to draw on screen
		int lineHeight = (int)(SCREENHEIGHT / perpWallDist);
		// calculate lowest and highest pixel to fill in current stripe
		img->drawStart = -lineHeight / 2 + SCREENHEIGHT / 2;
		if (img->drawStart < 0)
			img->drawStart = 0;
		img->drawEnd = lineHeight / 2 + SCREENHEIGHT / 2;
		if (img->drawEnd >= SCREENHEIGHT)
			img->drawEnd = SCREENHEIGHT - 1;
		if (img->drawStart >= SCREENHEIGHT)
			img->drawStart = 0;
		// calculate value of wallX
		double wallX; // where exactly the wall was hit
		if (side == 0)
			wallX = img->posY + perpWallDist * rayDirY;
		else
			wallX = img->posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		// x coordinate on the texture
		int texX = (int)(wallX * (double)(TEXWIDTH));
		if (side == 0 && rayDirX > 0)
			texX = TEXWIDTH - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = TEXWIDTH - texX - 1;
		// give x and y sides different brightness

		// draw the pixels of the stripe as a vertical line
		double step = 1.0 * TEXHEIGHT / lineHeight;
		// Starting texture coordinate
		double texPos = (img->drawStart - SCREENHEIGHT / 2 + lineHeight / 2) * step;
		for (unsigned int y = 0; y < SCREENHEIGHT; y++)
		{
			// Cast the texture coordinate to integer, and mask with (TEXHEIGHT - 1) in case of overflow
			if (y >= img->drawStart && y <= img->drawEnd)
			{
				int texY = (int)texPos & (img->height[0] - 1);
				texPos += step;
				unsigned int color;
				if (side == 0 && rayDirX > 0)
				{
					if (hit == 1)
						color = (int)img->texture[0][(int)TEXHEIGHT * texY + texX] ;
				}
				else if (side == 0 && rayDirX < 0)
				{
					if (hit == 1)
						color = (int)img->texture[1][(int)TEXHEIGHT * texY + texX];
				}
				else if (side == 1 && rayDirY > 0)
				{
					if (hit == 1)
						color = (int)img->texture[2][(int)TEXHEIGHT * texY + texX];
				}
				else if (side == 1 && rayDirY < 0)
				{
					if (hit == 1)
						color = (int)img->texture[3][(int)TEXHEIGHT * texY + texX] ;
				}
				if (side == 1)
					color = (color >> 1) & 8355711;
				img->buffer[y][x] = color;
			}
		}
		unsigned int i = 0;
		while (i < SCREENHEIGHT)
		{
			if (i < SCREENHEIGHT / 2)
			{
				my_mlx_pixel_put1(img, x, i, make_color(0, img->c_color.r, img->c_color.g, img->c_color.b));
			}
			else if (i > SCREENHEIGHT / 2)
				my_mlx_pixel_put1(img, x, i, make_color(0, img->f_color.r, img->f_color.g, img->f_color.b));
			i++;
		}
		i = 0;
		while (i < SCREENHEIGHT)
		{
			if (i >= img->drawStart && i <= img->drawEnd)
			{
				if (get_t(img->buffer[i][x]) > 0)
				{
					my_mlx_pixel_put1(img, x, i, img->buffer[i][x]);
				}
				else
					my_mlx_pixel_put1(img, x, i, img->buffer[i][x]);
			}
			i++;
		}
		x++;
	}
	int max_size = f_lline(img);
	int with = arr_2d_len((void **)img->map);

	int skip = first_space(img->map);
	int size = 900 / (max_size + with);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	ft_bzero(img->minimap_addr, with * size * (max_size * size - skip) * (img->bpp_line / 8));
	white_box(img, img->posx * size, img->posy * size, 0x00FF0000);
	minimap(img);
	mlx_put_image_to_window(img->mlx, img->win, img->gun1, 450, 510);
	frame++;
}
