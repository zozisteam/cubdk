/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 05:22:12 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/26 05:22:27 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	free_strings(t_game *game)
{
	if (game->NO_texture != NULL)
		free (game->NO_texture);
	if (game->SO_texture != NULL)
		free (game->SO_texture);
	if (game->WE_texture != NULL)
		free (game->WE_texture);
	if (game->EA_texture != NULL)
		free (game->EA_texture);
	if (game->C_color != NULL)
		free (game->C_color);
	if (game->F_color != NULL)
		free (game->F_color);
}

void	free_split(char **s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_if_er(t_game *game)
{
	free_split(game->map);
	free_split(game->map_data);
	free_strings(game);
	free(game);
	exit(0);
}
