/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:30:56 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/12 21:54:16 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_helper(t_data *data, int i, int j, int skip)
{
	data->posx = j - skip + 0.5;
	data->posy = i + 0.5;
	if (data->map[i][j] == 'S')
		data->player_dir = M_PI / 2;
	else if (data->map[i][j] == 'N')
		data->player_dir = 3 / 2.0 * M_PI;
	else if (data->map[i][j] == 'W')
		data->player_dir = 2 * M_PI;
	else if (data->map[i][j] == 'E')
		data->player_dir = M_PI;
	data->map[i][j] = '0';
}

void	ft_set_player_dir(t_data *img, int j, int k)
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

void	ft_put_player(t_data *img)
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
				img->posx = j + 0.5;
				img->posy = k + 0.5;
				ft_set_player_dir(img, j, k);
				break ;
			}
			k++;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	t_data	img;
	int		max_size;
	int		with;

	if (ac != 2)
		exit(1);
	read_map(av[1], &img);
	check_error(&img);
	max_size = max_line_len(&img);//max line length in map
	with = arr_2d_len((void **)img.map);
	init(&img);
	img.size = 500 / (max_size + with);
	img.frame = 0;
	img.pos_x = img.posx;
	img.pos_y = img.posy;
	set_pos(&img);
	img.draw_start = 0;
	img.draw_end = 0;
	creat_imgs(&img);
	minimap(&img);
	raycast(&img);
	mlx_hook(img.win, 2, 0, key_check, &img);
	mlx_hook(img.win, 6, 1L << 6, mouse, &img);
	mlx_loop_hook(img.mlx, &frame_counter, &img);
	mlx_loop(img.mlx);
}
