/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:34 by alalmazr          #+#    #+#             */
/*   Updated: 2023/01/25 18:57:32 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"


void init_game(t_game *game)
{
	mlx_get_screen_size();
	mlx_get_screen_size(game->mlx, (int *)&game->img->size.x,(int *)&game->img->size.y);
	game->img->aspect = (double)game->img->size.x/game->img->size.y;
}