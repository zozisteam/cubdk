/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:57:28 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/12 21:45:38 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	count;
	int	skip;

	i = 0;
	j = 0;
	count = 0;
	skip = first_space(data->map);
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				draw_player_helper(data, i, j, skip);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	creat_imgs2(t_data *img)
{
	int	i;

	i = 400;
	img->gun1 = mlx_xpm_file_to_image(img->mlx,
			"./img/gun4c.xpm", &i, &i);
	img->gun2 = mlx_xpm_file_to_image(img->mlx,
			"./img/gun4b.xpm", &i, &i);
}

//WALLS
//processing imgs and storing in textures array for each image
void	creat_imgs(t_data *img)
{
	img->ptr[0] = mlx_xpm_file_to_image(img->mlx, img->_no,
			&img->width[0], &img->height[0]);
	img->texture[0] = (unsigned int (*))mlx_get_data_addr(img->ptr[0],
			&img->bpp[0], &img->ll[0], &img->en[0]);
	img->ptr[1] = mlx_xpm_file_to_image(img->mlx, img->_so,
			&img->width[1], &img->height[1]);
	img->texture[1] = (unsigned int (*))mlx_get_data_addr(img->ptr[1],
			&img->bpp[1], &img->ll[1], &img->en[1]);
	img->ptr[2] = mlx_xpm_file_to_image(img->mlx, img->_ea,
			&img->width[2], &img->height[2]);
	img->texture[2] = (unsigned int (*))mlx_get_data_addr(img->ptr[2],
			&img->bpp[2], &img->ll[2], &img->en[2]);
	img->ptr[3] = mlx_xpm_file_to_image(img->mlx, img->_we,
			&img->width[3], &img->height[3]);
	img->texture[3] = (unsigned int (*))mlx_get_data_addr(img->ptr[3],
			&img->bpp[3],
			&img->ll[3], &img->en[3]);
	creat_imgs2(img);
}

int	mouse(int x, int y, t_data *img)
{
	mlx_mouse_hide();
	(void)y;
	if (x > SCREENWIDTH / 2)
	{
		key_check_rotate(124, img);
	}
	else
	{
		key_check_rotate(123, img);
	}
	raycast(img);
	mlx_mouse_move(img->win, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	return (0);
}
