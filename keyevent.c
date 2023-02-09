/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:16 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/04 09:50:49 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *img, double nextp_x, double nextp_y, int skip)
{
	if (img->s[(int)(img->posX + img->planeX * WALKSPEED)][(int)(img->posY)]
			&& img->s[(int)(img->posX + img->planeX * WALKSPEED)]
			[(int)(img->posY)] != '1'
				&& img->s[(int)(img->posX + img->planeX * WALKSPEED)]
				[(int)(img->posY)] != 'C' )
			img->posX += img->planeX * WALKSPEED;
	if (img->s[(int)(img->posX)][(int)(img->posY + img->planeY * WALKSPEED)]
			&& img->s[(int)(img->posX)]
			[(int)(img->posY + img->planeY * WALKSPEED)] != '1'
				&& img->s[(int)(img->posX)]
				[(int)(img->posY + img->planeY * WALKSPEED)] != 'C')
			img->posY += img->planeY * WALKSPEED;
		nextp_x = img->posx
		- (cos(img->player_dir - (M_PI / 2)) * WALKSPEED / 1.5);
		nextp_y = img->posy
		+ (sin(img->player_dir - (M_PI / 2)) * WALKSPEED / 1.5);
	if (img->map[(int)nextp_y][(int)img->posx + skip] != '\0'
			&& img->map[(int)nextp_y]
				[(int)(img->posx + (skip))] != '1'
					&& img->map[(int)nextp_y][(int)(img->posx + (skip))] != 'C')
			img->posy = nextp_y;
	if (img->map[(int)img->posy][(int)nextp_x + skip] != '\0'
			&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != '1'
				&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != 'C')
			img->posx = nextp_x;
}

void	move_left_helper(t_data *img)
{
	if (img->s[(int)(img->posX - img->planeX * WALKSPEED)]
			[(int)(img->posY)]
			&& img->s[(int)(img->posX - img->planeX * WALKSPEED)]
			[(int)(img->posY)] != '1'
			&& img->s[(int)(img->posX - img->planeX * WALKSPEED)]
				[(int)(img->posY)] != 'C')
			img->posX -= img->planeX * WALKSPEED;
}

void	move_left(t_data *img, double nextp_x, double nextp_y, int skip)
{
	move_left_helper(img);
	if (img->s[(int)(img->posX)][(int)(img->posY - img->planeY * WALKSPEED)]
			&& img->s[(int)(img->posX)]
				[(int)(img->posY - img->planeY * WALKSPEED)] != '1'
				&& img->s[(int)(img->posX)]
					[(int)(img->posY - img->planeY * WALKSPEED)] != 'C')
			img->posY -= img->planeY * WALKSPEED;
		nextp_y = img->posy
		+ (sin(img->player_dir + (M_PI / 2)) * WALKSPEED / 1.5);
		nextp_x = img->posx
		- (cos(img->player_dir + (M_PI / 2)) * WALKSPEED / 1.5);
	if (img->map[(int)nextp_y][(int)img->posx + skip]
			&& img->map[(int)nextp_y]
			[(int)(img->posx + (skip))] != '1'
				&& img->map[(int)nextp_y]
				[(int)(img->posx + (skip))] != 'C')
			img->posy = nextp_y;
	if (img->map[(int)img->posy][(int)nextp_x + skip]
			&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != '1'
				&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != 'C')
			img->posx = nextp_x;
}

void	key_check_updown(int keycode, t_data *img)
{	
	int		skip;
	double	nextp_x;
	double	nextp_y;

	nextp_x = 0.0;
	nextp_y = 0.0;
	skip = first_space(img->map);
	if (keycode == 2)
		move_right(img, nextp_x, nextp_y, skip);
	else if (keycode == 0)
		move_left(img, nextp_x, nextp_y, skip);
}

void	move_up(t_data *img, double nextp_x, double nextp_y, int skip)
{
	if (img->s[(int)(img->posX + img->dirX * WALKSPEED)]
	[(int)(img->posY)] != '\0'
		&& img->s[(int)(img->posX + img->dirX * WALKSPEED)]
		[(int)(img->posY)] != '1' &&
			img->s[(int)(img->posX + img->dirX * WALKSPEED)]
			[(int)(img->posY)] != 'C' )
		img->posX += img->dirX * WALKSPEED;
	if (img->s[(int)(img->posX)]
		[(int)(img->posY + img->dirY * WALKSPEED)] != '\0'
			&& img->s[(int)(img->posX)]
			[(int)(img->posY + img->dirY * WALKSPEED)] != '1'
			&& img->s[(int)(img->posX)]
			[(int)(img->posY + img->dirY * WALKSPEED)] != 'C')
		img->posY += img->dirY * WALKSPEED;
	nextp_x = img->posx - (cos(img->player_dir) * WALKSPEED);
	nextp_y = img->posy + (sin(img->player_dir) * WALKSPEED);
	if (img->map[(int)nextp_y][(int)img->posx + skip] != '\0'
		&& img->map[(int)nextp_y]
			[(int)(img->posx + (skip))] != '1'
			&& img->map[(int)nextp_y][(int)(img->posx + (skip))] != 'C')
		img->posy = nextp_y;
	if (img->map[(int)img->posy][(int)nextp_x + skip] != '\0'
		&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != '1'
			&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != 'C')
		img->posx = nextp_x;
}
