/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:53 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:18:29 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_error(t_game *game)
{
	fill_data(game);
	if (check(game->data) == 0)
		error_();
	if (fill_color(game) == 0)
		error_();
	if (check_color_range(game) == 0)
		error_();
	if (exist_image(game) == 0)
		error_();
	if (chek_imgs(game) == 0)
		error_();
	if (invalid_map(game->map) == 0)
		error_();
	if (check_dir(game->map) == 0)
		error_();
	if (check_zeros(game) == 0)
		error_();
	if (check_close_map(game->map) == 0)
		error_();
	return (1);
}

void	init(t_game	*game)
{
	int	max_size;
	int	with;
	int	size;
	int	skip;

	game->mlx = mlx_init();
	max_size = max_line_len(game);
	with = arr_2d_len((void **)game->map);
	size = 500 / (max_size + with);
	skip = first_space(game->map);
	game->img_minimap = mlx_new_image(game->mlx, size
			* (max_size - skip), with * size);
	game->minimap_addr = mlx_get_data_addr(game->img_minimap,
			&game->bpp_line, &game->size_line, &game->endian);
	game->s = rotate_arr(game->map);
	game->win = mlx_new_window(game->mlx,
			SCREENWIDTH, SCREENHEIGHT, "game for ***s");
	game->game = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	game->img_alpha = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	game->addr = mlx_get_data_addr(game->game,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	game->addr_alpha = mlx_get_data_addr(game->img_alpha,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	draw_player(game);
}

void	ftset_player_dir(t_game *game, int j, int k)
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

void	set_pos_helper(t_game *game, int j, int k)
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

void	set_pos(t_game *game)
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
				game->pos_x = j + 0.5;
				game->pos_y = k + 0.5;
				set_pos_helper(game, j, k);
				break ;
			}
			k++;
		}
		j++;
	}
}
