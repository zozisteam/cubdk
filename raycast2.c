/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:29:56 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:11:09 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_5_helper(t_game *game)
{
	if (game->side == 0 && game->raydir_x > 0)
	{
		if (game->hit == 1)
			game->color = (int)game->texture[0][(int)TEXHEIGHT
				* game->tex_y + game->tex_x];
	}
	else if (game->side == 0 && game->raydir_x < 0)
	{
		if (game->hit == 1)
			game->color = (int)game->texture[1][(int)TEXHEIGHT
				* game->tex_y + game->tex_x];
	}
	else if (game->side == 1 && game->raydir_y > 0)
	{
		if (game->hit == 1)
			game->color = (int)game->texture[2][(int)TEXHEIGHT
				* game->tex_y + game->tex_x];
	}
	else if (game->side == 1 && game->raydir_y < 0)
	{
		if (game->hit == 1)
			game->color = (int)game->texture[3][(int)TEXHEIGHT
				* game->tex_y + game->tex_x];
	}
}

void	raycast_5(t_game *game)
{
	game->y = 0;
	while (game->y < SCREENHEIGHT)
	{
		if (game->y >= game->draw_start && game->y <= game->draw_end)
		{
			game->tex_y = (int)game->tex_pos & (game->height[0] - 1);
			game->tex_pos += game->step;
			raycast_5_helper(game);
			if (game->side == 1)
				game->color = (game->color >> 1) & 8355711;
			game->buffer[game->y][game->x] = game->color;
		}
		game->y++;
	}
}

void	raycast_6(t_game *game)
{
	game->i = 0;
	while (game->i < SCREENHEIGHT)
	{
		if (game->i < SCREENHEIGHT / 2)
		{
			my_mlx_pixel_put1(game, game->x, game->i, make_color(0, game->c_color.r,
					game->c_color.g, game->c_color.b));
		}
		else if (game->i > SCREENHEIGHT / 2)
			my_mlx_pixel_put1(game, game->x, game->i, make_color(0, game->f_color.r,
					game->f_color.g, game->f_color.b));
		game->i++;
	}
}

void	raycast_7(t_game *game)
{
	game->i = 0;
	while (game->i < SCREENHEIGHT)
	{
		if (game->i >= game->draw_start && game->i <= game->draw_end)
		{
			if (get_t(game->buffer[game->i][game->x]) > 0)
			{
				my_mlx_pixel_put1(game, game->x, game->i,
					game->buffer[game->i][game->x]);
			}
			else
				my_mlx_pixel_put1(game, game->x, game->i,
					game->buffer[game->i][game->x]);
		}
		game->i++;
	}
}

void	raycast_8(t_game *game)
{
	game->max_size = max_line_len(game);
	game->with = arr_2d_len((void **)game->map);
	game->skip = first_space(game->map);
	game->size = 500 / (game->max_size + game->with);
	mlx_put_image_to_window(game->mlx, game->win, game->game, 0, 0);
	ft_bzero(game->minimap_addr, game->with * game->size
		* (game->max_size * game->size - game->skip) * (game->bpp_line / 8));
	minimap_player(game, game->posx * game->size,
		game->posy * game->size, 0x00FF0000);
	minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->gun1, 450, 510);
	game->frame++;
}
