/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_n_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:29:01 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/11 07:40:47 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	draw_grid(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < game->w)
	{
		y = 0;
		while (y < game->h)
		{
			i = 0;
			while (i < CELL_SIZE)
			{
				mlx_pixel_put(game->mlx, game->window, x * CELL_SIZE, y * CELL_SIZE + i, GRID_COLOR);
				mlx_pixel_put(game->mlx, game->window, x * CELL_SIZE + i, y * CELL_SIZE, GRID_COLOR);
				i++;
			}
			y++;
		}
		x++;
	}
}

void	draw_player(t_game *game)
{
	int	i;
	int j;

	
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			mlx_pixel_put(game->mlx, game->window, game->p_x + i, game->p_y + j, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}

void	erase_player(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			mlx_pixel_put(game->mlx, game->window, game->p_x / 20 * CELL_SIZE + i, game->p_y / 20 * CELL_SIZE + j, FLOOR_COLOR);
			j++;
		}
		i++;
	}
}