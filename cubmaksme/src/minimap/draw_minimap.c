/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 04:15:27 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/11 04:05:29 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	draw_cell(t_game *game, int color, int x, int y)
{
	int	i;
	int j;

	i = 0;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			mlx_pixel_put(game->mlx, game->window, x * CELL_SIZE + i, y * CELL_SIZE + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == '1')
				draw_cell(game, WALL_COLOR, x, y);
			else if (game->map[y][x] == ' ')
				draw_cell(game, GRID_COLOR, x, y);
			else
				draw_cell(game, FLOOR_COLOR, x, y);
			x++;
		}
		y++;
	}
	draw_player(game);
	draw_grid(game);
}