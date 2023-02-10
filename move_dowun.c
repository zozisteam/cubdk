/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dowun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:24:08 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/10 14:53:14 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_down(t_data *img, double nextp_x, double nextp_y, int skip)
{
	if (img->s[(int)(img->posX - img->dirX * WALKSPEED)]
			[(int)(img->posY)] != '\0' &&
		img->s[(int)(img->posX - img->dirX * WALKSPEED)]
			[(int)(img->posY)] != '1' &&
		img->s[(int)(img->posX - img->dirX * WALKSPEED)]
			[(int)(img->posY)] != 'C')
		img->posX -= img->dirX * WALKSPEED;
	if (img->s[(int)(img->posX)]
			[(int)(img->posY - img->dirY * WALKSPEED)] != '\0' &&
		img->s[(int)(img->posX)]
			[(int)(img->posY - img->dirY * WALKSPEED)] != '1' &&
		img->s[(int)(img->posX)]
			[(int)(img->posY - img->dirY * WALKSPEED)] != 'C')
		img->posY -= img->dirY * WALKSPEED;
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
