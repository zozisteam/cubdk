/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:10:22 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/06 06:02:10 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	find_player(t_game *game)
{
	int	i;
	int	j;
	int c;

	i = 0;
	c = 0;
	while (i < game->h)
	{
		j = 0;
		while (j < game->w)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || 
				game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				if (c != 0)
				{
					printf("Error\nMore than 1 player possition\n");
					free_if_er(game);
				}
				game->p_x = (j * 20) + 10;
				game->p_y = (i * 20) + 10;
				game->p_pos = game->map[i][j];
				c++;
			}
			j++;
		}
		i++;
	}
}

void	check_map_symbols_validity(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (is_map_symbol(game->map[i][j]) != 1)
			{
				printf("Error\nInvalid map symbol\n");
				free_if_er(game);
			}
			j++;
		}
		i++;
	}
}

void	check_map_validity(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '1' && ft_isspace(game->map[i][j]) != 1)
				is_symbol_safe(game, i, j);
			j++;
		}
		i++;
	}
	game->h = i;
}