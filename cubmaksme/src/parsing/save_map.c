/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 05:02:07 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/06 04:08:25 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int		count_maps_hight(t_game *game)
{
	int	i;

	i = game->i_pars;
	while (game->map_data[i] != NULL)
		i++;
	return (i);
}

void	copy_data_into_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_data[game->i_pars] != NULL)
	{
		game->map[i] = ft_strdup(game->map_data[game->i_pars]);
		i++;
		game->i_pars++;
	}
	game->map[i] = NULL;
}

void	save_map(t_game *game)
{
	game->h = count_maps_hight(game);
	game->map = malloc(game->h * sizeof(char *));
	copy_data_into_map(game);
	map_fixer(game);
	check_map_symbols_validity(game);
	check_map_validity(game);
}