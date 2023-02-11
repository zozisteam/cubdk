/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:10 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/11 12:50:43 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_check_rightleft(int keycode, t_data *img)
{	
	double	nextp_x;
	double	nextp_y;
	int		skip;

	nextp_x = 0;
	nextp_y = 0;
	skip = first_space(img->map);
	if (keycode == 13)
		move_up(img, nextp_x, nextp_y, skip);
	else if (keycode == 1)
		move_down(img, nextp_x, nextp_y, skip);
}

void	key_check_rotate(int keycode, t_data *img)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 124)
	{
		olddirx = img->dir_x;
		img->dir_x = img->dir_x * cos(-ROTSPEED) - img->dir_y * sin(-ROTSPEED);
		img->dir_y = olddirx * sin(-ROTSPEED) + img->dir_y * cos(-ROTSPEED);
		oldplanex = img->plane_x;
		img->plane_x = img->plane_x
			* cos(-ROTSPEED) - img->plane_y * sin(-ROTSPEED);
		img->plane_y = oldplanex * sin(-ROTSPEED) + img->plane_y * cos(-ROTSPEED);
		img->player_dir -= ROTSPEED;
	}
	else if (keycode == 123)
	{
		olddirx = img->dir_x;
		img->dir_x = img->dir_x * cos(ROTSPEED) - img->dir_y * sin(ROTSPEED);
		img->dir_y = olddirx * sin(ROTSPEED) + img->dir_y * cos(ROTSPEED);
		oldplanex = img->plane_x;
		img->plane_x = img->plane_x * cos(ROTSPEED) - img->plane_y * sin(ROTSPEED);
		img->plane_y = oldplanex * sin(ROTSPEED) + img->plane_y * cos(ROTSPEED);
				img->player_dir += ROTSPEED;
	}
}

int	key_check(int keycode, t_data *img)
{
	key_check_updown(keycode, img);
	key_check_rightleft(keycode, img);
	key_check_rotate(keycode, img);
	if (keycode == 53)
		exit(1);
	raycast (img);
	return (0);
}
