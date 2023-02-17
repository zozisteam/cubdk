/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:29:56 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/16 21:18:30 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_5_helper(t_data *img)
{
	if (img->side == 0 && img->raydir_x > 0)
	{
		if (img->hit == 1)
			img->color = (int)img->texture[0][(int)TEXHEIGHT
				* img->tex_y + img->tex_x];
	}
	else if (img->side == 0 && img->raydir_x < 0)
	{
		if (img->hit == 1)
			img->color = (int)img->texture[1][(int)TEXHEIGHT
				* img->tex_y + img->tex_x];
	}
	else if (img->side == 1 && img->raydir_y > 0)
	{
		if (img->hit == 1)
			img->color = (int)img->texture[2][(int)TEXHEIGHT
				* img->tex_y + img->tex_x];
	}
	else if (img->side == 1 && img->raydir_y < 0)
	{
		if (img->hit == 1)
			img->color = (int)img->texture[3][(int)TEXHEIGHT
				* img->tex_y + img->tex_x];
	}
}

void	raycast_5(t_data *img)
{
	img->y = 0;
	while (img->y < SCREENHEIGHT)
	{
		if (img->y >= img->draw_start && img->y <= img->draw_end)
		{
			img->tex_y = (int)img->tex_pos & (img->height[0] - 1);
			img->tex_pos += img->step;
			raycast_5_helper(img);
			if (img->side == 1)
				img->color = (img->color >> 1) & 8355711;
			img->buffer[img->y][img->x] = img->color;
		}
		img->y++;
	}
}

void	raycast_6(t_data *img)
{
	img->i = 0;
	while (img->i < SCREENHEIGHT)
	{
		if (img->i < SCREENHEIGHT / 2)
		{
			my_mlx_pixel_put1(img, img->x, img->i, make_color(0, img->c_color.r,
					img->c_color.g, img->c_color.b));
		}
		else if (img->i > SCREENHEIGHT / 2)
			my_mlx_pixel_put1(img, img->x, img->i, make_color(0, img->f_color.r,
					img->f_color.g, img->f_color.b));
		img->i++;
	}
}

void	raycast_7(t_data *img)
{
	img->i = 0;
	while (img->i < SCREENHEIGHT)
	{
		if (img->i >= img->draw_start && img->i <= img->draw_end)
		{
			if (get_t(img->buffer[img->i][img->x]) > 0)
			{
				my_mlx_pixel_put1(img, img->x, img->i,
					img->buffer[img->i][img->x]);
			}
			else
				my_mlx_pixel_put1(img, img->x, img->i,
					img->buffer[img->i][img->x]);
		}
		img->i++;
	}
}

void	raycast_8(t_data *img)
{
	img->max_size = max_line_len(img);
	img->with = arr_2d_len((void **)img->map);
	img->skip = first_space(img->map);
	img->size = 500 / (img->max_size + img->with);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	ft_bzero(img->minimap_addr, img->with * img->size
		* (img->max_size * img->size - img->skip) * (img->bpp_line / 8));
	minimap_player(img, img->posx * img->size,
		img->posy * img->size, 0x00FF0000);
	minimap(img);
	mlx_put_image_to_window(img->mlx, img->win, img->gun1, 450, 510);
	img->frame++;
}
