/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:57:50 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:07:17 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_check_rightleft(int keycode, t_game *game)
{	
	double	nextp_x;
	double	nextp_y;
	int		skip;

	nextp_x = 0;
	nextp_y = 0;
	skip = first_space(game->map);
	if (keycode == 13)
		move_up(game, nextp_x, nextp_y, skip);
	else if (keycode == 1)
		move_down(game, nextp_x, nextp_y, skip);
}

void	key_rotate_event(int keycode, t_game *game)
{
	if (keycode == 124)
	{
		game->olddir = game->dir_x;
		game->dir_x = game->dir_x * cos(-ROTSPEED) - game->dir_y * sin(-ROTSPEED);
		game->dir_y = game->olddir * sin(-ROTSPEED) + game->dir_y * cos(-ROTSPEED);
		game->oldplane = game->plane_x;
		game->plane_x = game->plane_x
			* cos(-ROTSPEED) - game->plane_y * sin(-ROTSPEED);
		game->plane_y = game->oldplane * sin(-ROTSPEED)
			+ game->plane_y * cos(-ROTSPEED);
		game->player_dir -= ROTSPEED;
	}
	else if (keycode == 123)
	{
		game->olddir = game->dir_x;
		game->dir_x = game->dir_x * cos(ROTSPEED) - game->dir_y * sin(ROTSPEED);
		game->dir_y = game->olddir * sin(ROTSPEED) + game->dir_y * cos(ROTSPEED);
		game->oldplane = game->plane_x;
		game->plane_x = game->plane_x * cos(ROTSPEED)
			- game->plane_y * sin(ROTSPEED);
		game->plane_y = game->oldplane * sin(ROTSPEED)
			+ game->plane_y * cos(ROTSPEED);
				game->player_dir += ROTSPEED;
	}
}

int	key_event(int keycode, t_game *game)
{
	key_check_updown(keycode, game);
	key_check_rightleft(keycode, game);
	key_rotate_event(keycode, game);
	if (keycode == 53)
		exit(1);
	raycast (game);
	return (0);
}
