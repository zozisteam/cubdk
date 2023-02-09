/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:30:56 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/09 19:55:03 by alalmazr         ###   ########.fr       */
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
		img->dirX = 1;
		img->planeY = -0.66;
	}
	else if (img->s[j][k] == 'E')
	{
		img->dirY = 1;
		img->planeX = 0.66;
	}
	else if (img->s[j][k] == 'W')
	{
		img->dirY = -1;
		img->planeX = -0.66;
	}
	else
	{
		img->dirX = -1;
		img->planeY = 0.66;
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
	cheack_error(&img);
	max_size = f_lline(&img);
	with = ft_2dlen((void **)img.map);
	init(&img);
	img.size = 900 / (max_size + with);
	img.frame = 0;
	img.posX = img.posx;
	img.posY = img.posy;
	set_pos(&img);
	img.drawStart = 0;
	img.drawEnd = 0;
	creat_imgs(&img);
	minimap(&img);
	raycast(&img);
	mlx_hook(img.win, 2, 0, key_check, &img);
	mlx_hook(img.win, 6, 1L << 6, mouse, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_loop_hook(img.mlx, &frame_conter, &img);
	mlx_loop(img.mlx);
}
