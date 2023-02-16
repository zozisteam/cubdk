/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dowun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:24:08 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_down(t_data *game, double nextp_x, double nextp_y, int skip)
{
	if (game->s[(int)(game->pos_x - game->dirx * WALKSPEED)]
	[(int)(game->pos_y)] != '\0'
		&& game->s[(int)(game->pos_x - game->dirx * WALKSPEED)]
		[(int)(game->pos_y)] != '1' &&
			game->s[(int)(game->pos_x - game->dirx * WALKSPEED)]
			[(int)(game->pos_y)] != 'C' )
		game->pos_x -= game->dirx * WALKSPEED;
	if (game->s[(int)(game->pos_x)]
[(int)(game->pos_y - game->diry * WALKSPEED)] != '\0' && game->s[(int)(game->pos_x)]
[(int)(game->pos_y - game->diry * WALKSPEED)] != '1' && game->s[(int)(game->pos_x)]
			[(int)(game->pos_y - game->diry * WALKSPEED)] != 'C')
		game->pos_y -= game->diry * WALKSPEED;
	nextp_x = game->posx + (cos(game->player_dir) * WALKSPEED);
	nextp_y = game->posy - (sin(game->player_dir) * WALKSPEED);
	if (game->map[(int)nextp_y][(int)game->posx + skip] != '\0'
		&& game->map[(int)nextp_y]
			[(int)(game->posx + (skip))] != '1'
			&& game->map[(int)nextp_y][(int)(game->posx + (skip))] != 'C')
		game->posy = nextp_y;
	if (game->map[(int)game->posy][(int)nextp_x + skip] != '\0'
		&& game->map[(int)game->posy][(int)(nextp_x + (skip))] != '1'
			&& game->map[(int)game->posy][(int)(nextp_x + (skip))] != 'C')
		game->posx = nextp_x;
}
