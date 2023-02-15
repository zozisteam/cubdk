/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlils6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:41 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:12:47 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	frame_counter(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	game->frame++;
	raycast(game);
	return (0);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}
