/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:01:22 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_err(t_data *game)
{
	fill_data(game);
	if (check(game->data) == 0)
		ft_error();
	if (color_fill(game) == 0)
		ft_error();
	if (check_color_range(game) == 0)
		ft_error();
	if (exist_image(game) == 0)
		ft_error();
	if (check_all_imgs(game) == 0)
		ft_error();
	if (invalid_map(game->map) == 0)
		ft_error();
	if (check_p_pos(game->map) == 0)
		ft_error();
	if (check_zeros(game) == 0)
		ft_error();
	if (check_close_map(game->map) == 0)
		ft_error();
	return (1);
}

void	init(t_data *game)
{
	int	max_size;
	int	with;
	int	size;
	int	skip;

	game->mlx = mlx_init();
	max_size = f_lline(game);
	with = arr_2d_len((void **)game->map);
	size = 500 / ((max_size - first_space(game->map)) + with);
	skip = first_space(game->map);
	game->img_minimap = mlx_new_image(game->mlx, size
			* (max_size - skip), (with + 1) * size);
	game->minimap_addr = mlx_get_data_addr(game->img_minimap,
			&game->bpp_line, &game->size_line, &game->endian);
	game->s = rotate_arr(game->map);
	game->win = mlx_new_window(game->mlx,
			SCREENWIDTH, SCREENHEIGHT, "Hello world!");
	game->img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	game->bag_map = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	game->img_alpha = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	game->addr = mlx_get_data_addr(game->img,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	game->add_bag_map = mlx_get_data_addr(game->bag_map,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	game->addr_alpha = mlx_get_data_addr(game->img_alpha,
			&game->bits_per_pixel, &game->line_length, &game->endian);
	draw_player(game);
}

void	set_direction(t_data *game, int j, int k)
{
	if (game->s[j][k] == 'S')
	{
		game->dirx = 1;
		game->planey = -0.66;
	}
	else if (game->s[j][k] == 'E')
	{
		game->diry = 1;
		game->planex = 0.66;
	}
	else if (game->s[j][k] == 'W')
	{
		game->diry = -1;
		game->planex = -0.66;
	}
	else
	{
		game->dirx = -1;
		game->planey = 0.66;
	}
}

void	set_pos(t_data *game)
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
				set_direction(game, j, k);
				break ;
			}
			k++;
		}
		j++;
	}
}
