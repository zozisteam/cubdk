/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:29:59 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/16 22:15:55 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_init(t_data *img)
{
	img->frame = 0;
	img->camera_x = 2 * img->x / (double)(SCREENWIDTH)-1;
	img->raydir_x = img->dir_x + +img->plane_x * img->camera_x;
	img->raydir_y = img->dir_y + img->plane_y * img->camera_x;
	img->map_x = (int)(img->pos_x);
	img->map_y = (int)(img->pos_y);
	if (img->raydir_x == 0)
		img->deltadist_x = 1e30;
	else
		img->deltadist_x = fabs(1 / img->raydir_x);
	if (img->raydir_y == 0)
		img->deltadist_y = 1e30;
	else
		img->deltadist_y = fabs(1 / img->raydir_y);
	img->hit = 0;
}

void	raycast_1(t_data *img)
{
	if (img->raydir_x < 0)
	{
		img->step_x = -1;
		img->sidedist_x = (img->pos_x - img->map_x) * img->deltadist_x;
	}
	else
	{
		img->step_x = 1;
		img->sidedist_x = (img->map_x + 1.0 - img->pos_x) * img->deltadist_x;
	}
	if (img->raydir_y < 0)
	{
		img->step_y = -1;
		img->sidedist_y = (img->pos_y - img->map_y) * img->deltadist_y;
	}
	else
	{
		img->step_y = 1;
		img->sidedist_y = (img->map_y + 1.0 - img->pos_y) * img->deltadist_y;
	}
}

void	raycast_2(t_data *img)
{
	while (img->hit == 0)
	{
		if (img->sidedist_x < img->sidedist_y)
		{
			img->sidedist_x += img->deltadist_x;
			img->map_x += img->step_x;
			img->side = 0;
		}
		else
		{
			img->sidedist_y += img->deltadist_y;
			img->map_y += img->step_y;
			img->side = 1;
		}
		if (ft_strlen(img->s[img->map_x]) > (size_t)img->map_y)
		{
			if (img->s[img->map_x][img->map_y] == '1')
				img->hit = 1;
		}
	}
}

void	raycast_3(t_data *img)
{
	if (img->side == 0)
		img->perpwalldist = (img->sidedist_x - img->deltadist_x);
	else
		img->perpwalldist = (img->sidedist_y - img->deltadist_y);
	img->lineheight = (int)(SCREENHEIGHT / img->perpwalldist);
	img->draw_start = -img->lineheight / 2 + SCREENHEIGHT / 2;
	if (img->draw_start < 0)
		img->draw_start = 0;
	img->draw_end = img->lineheight / 2 + SCREENHEIGHT / 2;
	if (img->draw_end >= SCREENHEIGHT)
		img->draw_end = SCREENHEIGHT - 1;
	if (img->draw_start >= SCREENHEIGHT)
		img->draw_start = 0;
}

void	raycast_4(t_data *img)
{
	if (img->side == 0)
		img->wall_x = img->pos_y + img->perpwalldist * img->raydir_y;
	else
		img->wall_x = img->pos_x + img->perpwalldist * img->raydir_x;
	img->wall_x -= floor((img->wall_x));
	img->tex_x = (int)(img->wall_x * (double)(TEXWIDTH));
	if (img->side == 0 && img->raydir_x > 0)
		img->tex_x = TEXWIDTH - img->tex_x - 1;
	if (img->side == 1 && img->raydir_y < 0)
		img->tex_x = TEXWIDTH - img->tex_x - 1;
	img->step = 1.0 * TEXHEIGHT / img->lineheight;
	img->tex_pos = (img->draw_start - SCREENHEIGHT / 2 + img->lineheight / 2)
		* img->step;
}
