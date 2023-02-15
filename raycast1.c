/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:29:59 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:10:57 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_init(t_game *game)
{
	game->frame = 0;
	game->camera_x = 2 * game->x / (double)(SCREENWIDTH)-1;
	game->raydir_x = game->dir_x + +game->plane_x * game->camera_x;
	game->raydir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)(game->pos_x);
	game->map_y = (int)(game->pos_y);
	if (game->raydir_x == 0)
		game->deltadist_x = 1e30;
	else
		game->deltadist_x = fabs(1 / game->raydir_x);
	if (game->raydir_y == 0)
		game->deltadist_y = 1e30;
	else
		game->deltadist_y = fabs(1 / game->raydir_y);
	game->hit = 0;
}

void	raycast_1(t_game *game)
{
	if (game->raydir_x < 0)
	{
		game->step_x = -1;
		game->sidedist_x = (game->pos_x - game->map_x) * game->deltadist_x;
	}
	else
	{
		game->step_x = 1;
		game->sidedist_x = (game->map_x + 1.0 - game->pos_x) * game->deltadist_x;
	}
	if (game->raydir_y < 0)
	{
		game->step_y = -1;
		game->sidedist_y = (game->pos_y - game->map_y) * game->deltadist_y;
	}
	else
	{
		game->step_y = 1;
		game->sidedist_y = (game->map_y + 1.0 - game->pos_y) * game->deltadist_y;
	}
}

void	raycast_2(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->sidedist_x < game->sidedist_y)
		{
			game->sidedist_x += game->deltadist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->sidedist_y += game->deltadist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (ft_strlen(game->s[game->map_x]) > (size_t)game->map_y)
		{
			if (game->s[game->map_x][game->map_y] == '1')
				game->hit = 1;
		}
	}
}

void	raycast_3(t_game *game)
{
	if (game->side == 0)
		game->perpwalldist = (game->sidedist_x - game->deltadist_x);
	else
		game->perpwalldist = (game->sidedist_y - game->deltadist_y);
	game->lineheight = (int)(SCREENHEIGHT / game->perpwalldist);
	game->draw_start = -game->lineheight / 2 + SCREENHEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->lineheight / 2 + SCREENHEIGHT / 2;
	if (game->draw_end >= SCREENHEIGHT)
		game->draw_end = SCREENHEIGHT - 1;
	if (game->draw_start >= SCREENHEIGHT)
		game->draw_start = 0;
}

void	raycast_4(t_game *game)
{
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perpwalldist * game->raydir_y;
	else
		game->wall_x = game->pos_x + game->perpwalldist * game->raydir_x;
	game->wall_x -= floor((game->wall_x));
	game->tex_x = (int)(game->wall_x * (double)(TEXWIDTH));
	if (game->side == 0 && game->raydir_x > 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
	if (game->side == 1 && game->raydir_y < 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
	game->step = 1.0 * TEXHEIGHT / game->lineheight;
	game->tex_pos = (game->draw_start - SCREENHEIGHT / 2 + game->lineheight / 2)
		* game->step;
}
