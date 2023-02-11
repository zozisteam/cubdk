/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dowun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:24:08 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/11 12:50:24 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_down(t_data *img, double nextp_x, double nextp_y, int skip)
{
	if (img->s[(int)(img->pos_x - img->dir_x * WALKSPEED)]
			[(int)(img->pos_y)] != '\0' &&
		img->s[(int)(img->pos_x - img->dir_x * WALKSPEED)]
			[(int)(img->pos_y)] != '1' &&
		img->s[(int)(img->pos_x - img->dir_x * WALKSPEED)]
			[(int)(img->pos_y)] != 'C')
		img->pos_x -= img->dir_x * WALKSPEED;
	if (img->s[(int)(img->pos_x)]
			[(int)(img->pos_y - img->dir_y * WALKSPEED)] != '\0' &&
		img->s[(int)(img->pos_x)]
			[(int)(img->pos_y - img->dir_y * WALKSPEED)] != '1' &&
		img->s[(int)(img->pos_x)]
			[(int)(img->pos_y - img->dir_y * WALKSPEED)] != 'C')
		img->pos_y -= img->dir_y * WALKSPEED;
	nextp_x = img->posx + (cos(img->player_dir) * WALKSPEED);
	nextp_y = img->posy - (sin(img->player_dir) * WALKSPEED);
	if (img->map[(int)nextp_y][(int)img->posx + skip] != '\0' &&
		img->map[(int)nextp_y][(int)(img->posx + (skip))] != '1' &&
		img->map[(int)nextp_y][(int)(img->posx + (skip))] != 'C')
		img->posy = nextp_y;
	if (img->map[(int)img->posy][(int)nextp_x + skip] != '\0' &&
		img->map[(int)img->posy][(int)(nextp_x + (skip))] != '1' &&
		img->map[(int)img->posy][(int)(nextp_x + (skip))] != 'C')
		img->posx = nextp_x;
}
