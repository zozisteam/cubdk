/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:31:44 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_help6(t_data *game, t_loc *loc)
{
	unsigned int	i;

	i = 0;
	while (i < SCREENHEIGHT)
	{
		if (i < SCREENHEIGHT / 2)
			my_mlx_pixel_put1(game, loc->x, i,
				make_color(0, game->c_color.r, game->c_color.g, game->c_color.b));
		else if (i > SCREENHEIGHT / 2)
			my_mlx_pixel_put1(game, loc->x, i,
				make_color(0, game->f_color.r, game->f_color.g, game->f_color.b));
		i++;
	}
	i = -1;
	while (++i < SCREENHEIGHT)
	{
		my_mlx_pixel_put_alpha(game, loc->x, i, 0xff000000);
		if (i >= game->drawstart && i <= game->drawend)
		{
			if (get_t(game->buffer[i][loc->x]) > 0)
				my_mlx_pixel_put_alpha(game, loc->x, i, game->buffer[i][loc->x]);
			else
				my_mlx_pixel_put1(game, loc->x, i, game->buffer[i][loc->x]);
		}
	}
}

void	raycast_framing_help(t_data *game, t_loc *loc, int t)
{
	if (get_t(t) == 0)
		loc->color = t;
	else
		loc->color = (int)(int)game->texture[0][(int)TEXHEIGHT
			*loc->tex_y + loc->tex_x] & 0xffffff;
}


void	raycast_f(t_data *game, t_loc *loc, int i)
{
	if (loc->hit == 1)
		loc->color = (int)game->texture[i]
		[(int)TEXHEIGHT * loc->tex_y + loc->tex_x] & 0xffffff;
}

