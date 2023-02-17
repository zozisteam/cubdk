/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:57:39 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/16 22:13:11 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_player_dir(t_data *game, int j, int k)
{
	if (game->s[j][k] == 'S')
	{
		game->dir_x = 1;
		game->plane_y = -0.66;
	}
	else if (game->s[j][k] == 'E')
	{
		game->dir_y = 1;
		game->plane_x = 0.66;
	}
	else if (game->s[j][k] == 'W')
	{
		game->dir_y = -1;
		game->plane_x = -0.66;
	}
	else
	{
		game->dir_x = -1;
		game->plane_y = 0.66;
	}
}

void	ft_put_player(t_data *game)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (game->s[j])
	{
		k = 0;
		while (game->s[j][k])
		{
			if (game->s[j][k] == 'W' || game->s[j][k] == 'N'
				|| game->s[j][k] == 'S' || game->s[j][k] == 'E')
			{
				game->posx = j + 0.5;
				game->posy = k + 0.5;
				ft_set_player_dir(game, j, k);
				break ;
			}
			k++;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	t_data	game;
	int		max_size;
	int		with;

	if (ac != 2)
		exit(1);
	read_map(av[1], &game);
	check_error(&game);
	max_size = max_line_len(&game);
	with = arr_2d_len((void **)game.map);
	init(&game);
	game.size = 500 / (max_size + with);
	game.frame = 0;
	game.pos_x = game.posx;
	game.pos_y = game.posy;
	set_pos(&game);
	game.draw_start = 0;
	game.draw_end = 0;
	creat_imgs(&game);
	minimap(&game);
	raycast(&game);
	mlx_hook(game.win, 2, 0, key_check, &game);
	mlx_hook(game.win, 6, 1L << 6, mouse, &game);
	mlx_loop_hook(game.mlx, &frame_counter, &game);
	mlx_loop(game.mlx);
}
