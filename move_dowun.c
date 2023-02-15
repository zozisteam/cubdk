/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dowun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:57:32 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:10:29 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_down(t_game *game, double nextp_x, double nextp_y, int skip)
{
	if (game->s[(int)(game->pos_x - game->dir_x * WALKSPEED)]
			[(int)(game->pos_y)] != '\0' &&
		game->s[(int)(game->pos_x - game->dir_x * WALKSPEED)]
			[(int)(game->pos_y)] != '1' &&
		game->s[(int)(game->pos_x - game->dir_x * WALKSPEED)]
			[(int)(game->pos_y)] != 'C')
		game->pos_x -= game->dir_x * WALKSPEED;
	if (game->s[(int)(game->pos_x)]
			[(int)(game->pos_y - game->dir_y * WALKSPEED)] != '\0' &&
		game->s[(int)(game->pos_x)]
			[(int)(game->pos_y - game->dir_y * WALKSPEED)] != '1' &&
		game->s[(int)(game->pos_x)]
			[(int)(game->pos_y - game->dir_y * WALKSPEED)] != 'C')
		game->pos_y -= game->dir_y * WALKSPEED;
	nextp_x = game->posx + (cos(game->player_dir) * WALKSPEED);
	nextp_y = game->posy - (sin(game->player_dir) * WALKSPEED);
	if (game->map[(int)nextp_y][(int)game->posx + skip] != '\0' &&
		game->map[(int)nextp_y][(int)(game->posx + (skip))] != '1' &&
		game->map[(int)nextp_y][(int)(game->posx + (skip))] != 'C')
		game->posy = nextp_y;
	if (game->map[(int)game->posy][(int)nextp_x + skip] != '\0' &&
		game->map[(int)game->posy][(int)(nextp_x + (skip))] != '1' &&
		game->map[(int)game->posy][(int)(nextp_x + (skip))] != 'C')
		game->posx = nextp_x;
}
