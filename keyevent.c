/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:16 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *game, double nextp_x, double nextp_y, int skip)
{
	if (game->s[(int)(game->pos_x + game->planex * WALKSPEED)][(int)(game->pos_y)]
			&& game->s[(int)(game->pos_x + game->planex * WALKSPEED)]
			[(int)(game->pos_y)] != '1'
				&& game->s[(int)(game->pos_x + game->planex * WALKSPEED)]
				[(int)(game->pos_y)] != 'C' )
			game->pos_x += game->planex * WALKSPEED;
	if (game->s[(int)(game->pos_x)][(int)(game->pos_y + game->planey * WALKSPEED)]
			&& game->s[(int)(game->pos_x)]
			[(int)(game->pos_y + game->planey * WALKSPEED)] != '1'
				&& game->s[(int)(game->pos_x)]
				[(int)(game->pos_y + game->planey * WALKSPEED)] != 'C')
			game->pos_y += game->planey * WALKSPEED;
		nextp_x = game->posx
		- (cos(game->player_dir - (M_PI / 2)) * WALKSPEED / 1.5);
		nextp_y = game->posy
		+ (sin(game->player_dir - (M_PI / 2)) * WALKSPEED / 1.5);
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

void	move_left_helper(t_data *game)
{
	if (game->s[(int)(game->pos_x - game->planex * WALKSPEED)]
			[(int)(game->pos_y)]
			&& game->s[(int)(game->pos_x - game->planex * WALKSPEED)]
			[(int)(game->pos_y)] != '1'
			&& game->s[(int)(game->pos_x - game->planex * WALKSPEED)]
				[(int)(game->pos_y)] != 'C')
			game->pos_x -= game->planex * WALKSPEED;
}

void	move_left(t_data *game, double nextp_x, double nextp_y, int skip)
{
	move_left_helper(game);
	if (game->s[(int)(game->pos_x)][(int)(game->pos_y - game->planey * WALKSPEED)]
			&& game->s[(int)(game->pos_x)]
				[(int)(game->pos_y - game->planey * WALKSPEED)] != '1'
				&& game->s[(int)(game->pos_x)]
					[(int)(game->pos_y - game->planey * WALKSPEED)] != 'C')
			game->pos_y -= game->planey * WALKSPEED;
		nextp_y = game->posy
		+ (sin(game->player_dir + (M_PI / 2)) * WALKSPEED / 1.5);
		nextp_x = game->posx
		- (cos(game->player_dir + (M_PI / 2)) * WALKSPEED / 1.5);
	if (game->map[(int)nextp_y][(int)game->posx + skip]
			&& game->map[(int)nextp_y]
			[(int)(game->posx + (skip))] != '1'
				&& game->map[(int)nextp_y]
				[(int)(game->posx + (skip))] != 'C')
			game->posy = nextp_y;
	if (game->map[(int)game->posy][(int)nextp_x + skip]
			&& game->map[(int)game->posy][(int)(nextp_x + (skip))] != '1'
				&& game->map[(int)game->posy][(int)(nextp_x + (skip))] != 'C')
			game->posx = nextp_x;
}

void	key_check_updown(int keycode, t_data *game)
{	
	int		skip;
	double	nextp_x;
	double	nextp_y;

	nextp_x = 0.0;
	nextp_y = 0.0;
	skip = first_space(game->map);
	if (keycode == 2)
		move_right(game, nextp_x, nextp_y, skip);
	else if (keycode == 0)
		move_left(game, nextp_x, nextp_y, skip);
}

void	move_up(t_data *game, double nextp_x, double nextp_y, int skip)
{
	if (game->s[(int)(game->pos_x + game->dirx * WALKSPEED)]
	[(int)(game->pos_y)] != '\0'
		&& game->s[(int)(game->pos_x + game->dirx * WALKSPEED)]
		[(int)(game->pos_y)] != '1' &&
			game->s[(int)(game->pos_x + game->dirx * WALKSPEED)]
			[(int)(game->pos_y)] != 'C' )
		game->pos_x += game->dirx * WALKSPEED;
	if (game->s[(int)(game->pos_x)]
		[(int)(game->pos_y + game->diry * WALKSPEED)] != '\0'
			&& game->s[(int)(game->pos_x)]
			[(int)(game->pos_y + game->diry * WALKSPEED)] != '1'
			&& game->s[(int)(game->pos_x)]
			[(int)(game->pos_y + game->diry * WALKSPEED)] != 'C')
		game->pos_y += game->diry * WALKSPEED;
	nextp_x = game->posx - (cos(game->player_dir) * WALKSPEED);
	nextp_y = game->posy + (sin(game->player_dir) * WALKSPEED);
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
