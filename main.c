/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:30:56 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:55:05 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_helper(t_data *game, int i, int j, int skip)
{
	game->posx = j - skip + 0.5;
	game->posy = i + 0.5;
	if (game->map[i][j] == 'S')
		game->player_dir = M_PI / 2;
	else if (game->map[i][j] == 'N')
		game->player_dir = (3 * M_PI) / 2.0 ;
	else if (game->map[i][j] == 'W')
		game->player_dir = 2 * M_PI;
	else if (game->map[i][j] == 'E')
		game->player_dir = M_PI;
	game->map[i][j] = '0';
}

void	init2(t_data *game)
{
	int		max_size;
	int		with;

	max_size = f_lline(game);
	with = arr_2d_len((void **)game->map);
	game->size = 500 / ((max_size - first_space(game->map)) + with);
	game->frame = 0;
	game->pos_x = game->posx;
	game->pos_y = game->posy;
	game->drawstart = 0;
	game->drawend = 0;
	game->planex = 0;
	game->planey = 0;
	game->dirx = 0;
	game->diry = 0;
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac != 2)
	{
		printf("Error");
		return (0);
	}
	check_name(av[1]);
	read_map(av[1], &img);
	// img.walkspeed = 0.1;
	print_arr(img.data);
	check_err(&img);
	init(&img);
	init2(&img);
	set_pos(&img);
	create_img1(&img);
	minimap(&img);
	raycast(&img);
	mlx_hook(img.win, 2, 0, key_event, &img);
	mlx_hook(img.win, 6, 1L << 6, mouse, &img);
	// mlx_mouse_hook(img.win, mouse_hook, &img);
	// mlx_loop_hook(img.mlx, &frame_conter, &img);
	mlx_loop(img.mlx);
}
