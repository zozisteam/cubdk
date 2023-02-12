/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:01:22 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/12 21:54:16 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_error(t_data *img)
{
	fill_data(img);
	if (check(img->data) == 0)
		ft_error();
	if (fill_color(img) == 0)
		ft_error();
	if (check_color_range(img) == 0)
		ft_error();
	if (exist_image(img) == 0)
		ft_error();
	if (chek_imgs(img) == 0)
		ft_error();
	if (invalid_map(img->map) == 0)
		ft_error();
	if (cheack_if_dirc(img->map) == 0)
		ft_error();
	if (check_zeros(img) == 0)
		ft_error();
	if (check_close_map(img->map) == 0)
		ft_error();
	return (1);
}

void	init(t_data	*img)
{
	int	max_size;
	int	with;
	int	size;
	int	skip;

	img->mlx = mlx_init();
	max_size = max_line_len(img);
	with = arr_2d_len((void **)img->map);
	size = 500 / (max_size + with);
	skip = first_space(img->map);
	img->img_minimap = mlx_new_image(img->mlx, size
			* (max_size - skip), with * size);
	img->minimap_addr = mlx_get_data_addr(img->img_minimap,
			&img->bpp_line, &img->size_line, &img->endian);
	img->s = roted_array(img->map);
	img->win = mlx_new_window(img->mlx,
			SCREENWIDTH, SCREENHEIGHT, "game for ***s");
	img->img = mlx_new_image(img->mlx, SCREENWIDTH, SCREENHEIGHT);
	img->img_alpha = mlx_new_image(img->mlx, SCREENWIDTH, SCREENHEIGHT);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->addr_alpha = mlx_get_data_addr(img->img_alpha,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	draw_player(img);
}

void	ftset_player_dir(t_data *img, int j, int k)
{
	if (img->s[j][k] == 'S')
	{
		img->dir_x = 1;
		img->plane_y = -0.66;
	}
	else if (img->s[j][k] == 'E')
	{
		img->dir_y = 1;
		img->plane_x = 0.66;
	}
	else if (img->s[j][k] == 'W')
	{
		img->dir_y = -1;
		img->plane_x = -0.66;
	}
	else
	{
		img->dir_x = -1;
		img->plane_y = 0.66;
	}
}

//set player position
void	set_pos(t_data *img)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (img->s[j])
	{
		k = 0;
		while (img->s[j][k])
		{
			if (img->s[j][k] == 'W' || img->s[j][k] == 'N'
			|| img->s[j][k] == 'S' || img->s[j][k] == 'E')
			{
				img->pos_x = j + 0.5;
				img->pos_y = k + 0.5;
				if (img->s[j][k] == 'S')
				{
					img->dir_x = 1;
					img->plane_y = -0.66;
				}
				else if (img->s[j][k] == 'E')
				{
					img->dir_y = 1;
					img->plane_x = 0.66;
				}
				else if (img->s[j][k] == 'W')
				{
					img->dir_y = -1;
					img->plane_x = -0.66;
				}
				else
				{
					img->dir_x = -1;
					img->plane_y = 0.66;
				}
				break ;
			}
			k++;
		}
		j++;
	}
}
