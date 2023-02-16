/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:10 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_check_rightleft(int keycode, t_data *game)
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

void	key_check_rotate(int keycode, t_data *game)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 124)
	{
		olddirx = game->dirx;
		game->dirx = game->dirx * cos(-ROTSPEED) - game->diry * sin(-ROTSPEED);
		game->diry = olddirx * sin(-ROTSPEED) + game->diry * cos(-ROTSPEED);
		oldplanex = game->planex;
		game->planex = game->planex
			* cos(-ROTSPEED) - game->planey * sin(-ROTSPEED);
		game->planey = oldplanex * sin(-ROTSPEED) + game->planey * cos(-ROTSPEED);
		game->player_dir -= ROTSPEED;
	}
	else if (keycode == 123)
	{
		olddirx = game->dirx;
		game->dirx = game->dirx * cos(ROTSPEED) - game->diry * sin(ROTSPEED);
		game->diry = olddirx * sin(ROTSPEED) + game->diry * cos(ROTSPEED);
		oldplanex = game->planex;
		game->planex = game->planex * cos(ROTSPEED) - game->planey * sin(ROTSPEED);
		game->planey = oldplanex * sin(ROTSPEED) + game->planey * cos(ROTSPEED);
				game->player_dir += ROTSPEED;
	}
}

int	key_event(int keycode, t_data *game)
{

	key_check_updown(keycode, game);
	key_check_rightleft(keycode, game);
	key_check_rotate(keycode, game);
	if (keycode == 53)
	{
		exit(1);
	}
	// if (keycode == 3)
	// {
	// 	draw_big_map(game);
	// 	mlx_put_image_to_window(game->mlx, game->win, game->bag_map, 0, 0);
	// 	sleep(3);
	// 	// return (0);
	// }
	change_speed(keycode, game);
	raycast (game);
	return (0);
}
