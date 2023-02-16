/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:53:45 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:53:49 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_help1(t_data *game, t_loc *loc)
{
	loc->camera_x = 2 * loc->x / (double)(SCREENWIDTH) - 1;
	loc->raydir_x = game->dirx + game->planex * loc->camera_x;
	loc->raydir_y = game->diry + game->planey * loc->camera_x;
	loc->map_x = (int)(game->pos_x);
	loc->map_y = (int)(game->pos_y);
	if (loc->raydir_x == 0)
		loc->deltadist_x = 1e30;
	else
		loc->deltadist_x = fabs(1 / loc->raydir_x);
	if (loc->raydir_y == 0)
		loc->deltadist_y = 1e30;
	else
		loc->deltadist_y = fabs(1 / loc->raydir_y);
}

void	raycast_help2(t_data *game, t_loc *loc)
{
	if (loc->raydir_x < 0)
	{
		loc->step_x = -1;
		loc->sidedist_x = (game->pos_x - loc->map_x) * loc->deltadist_x;
	}
	else
	{
		loc->step_x = 1;
		loc->sidedist_x = (loc->map_x + 1.0 - game->pos_x) * loc->deltadist_x;
	}
	if (loc->raydir_y < 0)
	{
		loc->step_y = -1;
		loc->sidedist_y = (game->pos_y - loc->map_y) * loc->deltadist_y;
	}
	else
	{
		loc->step_y = 1;
		loc->sidedist_y = (loc->map_y + 1.0 - game->pos_y) * loc->deltadist_y;
	}
}

void	raycast_help3help(t_data *game, t_loc *loc)
{
	if (game->s[loc->map_x][loc->map_y] == '1')
		loc->hit = 1;
	else if (game->s[loc->map_x][loc->map_y] == 'C')
		loc->hit = 2;
	else if (game->s[loc->map_x][loc->map_y] == 'O')
		loc->hit = 3;
	else if (game->s[loc->map_x][loc->map_y] == 'X')
		loc->hit = 4;
}

void	raycast_help3(t_data *game, t_loc *loc)
{
	while (loc->hit == 0)
	{
		if (loc->sidedist_x < loc->sidedist_y)
		{
			loc->sidedist_x += loc->deltadist_x;
			loc->map_x += loc->step_x;
			loc->side = 0;
		}
		else
		{
			loc->sidedist_y += loc->deltadist_y;
			loc->map_y += loc->step_y;
			loc->side = 1;
		}
		if (ft_strlen(game->s[loc->map_x]) > (size_t)loc->map_y)
			raycast_help3help(game, loc);
	}
}

void	raycast_help4(t_data *game, t_loc *loc)
{
	if (loc->side == 0)
		loc->perpwalldist = loc->sidedist_x - loc->deltadist_x;
	else
		loc->perpwalldist = loc->sidedist_y - loc->deltadist_y;
	loc->lineheight = (int)(SCREENHEIGHT / loc->perpwalldist);
	game->drawstart = -loc->lineheight / 2 + SCREENHEIGHT / 2;
	game->drawend = loc->lineheight / 2 + SCREENHEIGHT / 2;
	if (game->drawend >= SCREENHEIGHT)
		game->drawend = SCREENHEIGHT - 1;
	if (game->drawstart >= SCREENHEIGHT)
		game->drawstart = 0;
	if (loc->side == 0)
		loc->wall_x = game->pos_y + loc->perpwalldist * loc->raydir_y;
	else
		loc->wall_x = game->pos_x + loc->perpwalldist * loc->raydir_x;
	loc->wall_x -= floor((loc->wall_x));
	loc->tex_x = (int)(loc->wall_x * (double)(TEXWIDTH));
	if (loc->side == 0 && loc->raydir_x > 0)
		loc->tex_x = TEXWIDTH - loc->tex_x - 1;
	if (loc->side == 1 && loc->raydir_y < 0)
		loc->tex_x = TEXWIDTH - loc->tex_x - 1;
}
