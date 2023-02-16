/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlils6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:07:45 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:41 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	frame_conter(void *data)
// {
// 	t_data *game;

// 	game = (t_data *)data;
// 	game->frame++;
// 	raycast(game);
// 	return (0);
// }

// int	mouse_hook(int keycode, int x, int y, t_data *game)
// {
// 	(void)x;
// 	(void)y;
// 	(void)game;
// 	if (keycode == 1)
// 		mlx_put_image_to_window(game->mlx, game->win, game->gun2, 450, 510);
// 	return (0);
// }

void	raycast_help5(t_data *game, t_loc *loc)
{
	loc->y = 0;
	loc->step = 1.0 * TEXHEIGHT / loc->lineheight;
		loc->texpos = (game->drawstart
			- SCREENHEIGHT / 2 + loc->lineheight / 2) * loc->step;
	while (loc->y < SCREENHEIGHT)
	{
		if (loc->y >= game->drawstart && loc->y <= game->drawend)
		{
			loc->tex_y = (int)loc->texpos & (game->height[0] - 1);
			loc->texpos += loc->step;
			if (loc->side == 0 && loc->raydir_x > 0)
				raycast_f(game, loc, 0);
			else if (loc->side == 0 && loc->raydir_x < 0)
				raycast_f(game, loc, 1);
			else if (loc->side == 1 && loc->raydir_y > 0)
				raycast_f(game, loc, 2);
			else if (loc->side == 1 && loc->raydir_y < 0)
				raycast_f(game, loc, 3);
			if (loc->side == 1)
				loc->color = (loc->color >> 1) & 8355711;
			game->buffer[loc->y][loc->x] = loc->color;
		}
		loc->y++;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
