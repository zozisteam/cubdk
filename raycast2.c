/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:53:32 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:53:35 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	init_loc(t_loc *loc, int x, int mapx, int mapy)
{
	loc->x = x;
	loc->y = 0;
	loc->map_x = mapx;
	loc->map_y = mapy;
	loc->camera_x = 0;
	loc->raydir_x = 0;
	loc->raydir_y = 0;
	loc->sidedist_x = 0;
	loc->sidedist_y = 0;
	loc->deltadist_x = 0;
	loc->deltadist_y = 0;
	loc->perpwalldist = 0;
	loc->lineheight = 0;
	loc->step_x = 0;
	loc->step_y = 0;
	loc->hit = 0;
	loc->side = 0;
	loc->wall_x = 0;
	loc->tex_x = 0;
	loc->tex_y = 0;
	loc->step = 0;
	loc->texpos = 0;
	loc->color = 0;
}

void	raycast_help(t_data *game, int x, int mapx, int mapy)
{
	t_loc	loc;

	init_loc(&loc, x, mapx, mapy);
	raycast_help1(game, &loc);
	raycast_help2(game, &loc);
	raycast_help3(game, &loc);
	raycast_help4(game, &loc);
	raycast_help5(game, &loc);
	raycast_help6(game, &loc);
}

void	put_imgs(t_data *game)
{
	int	max_size;
	int	with;
	int	skip;
	int	size;

	max_size = f_lline(game);
	with = arr_2d_len((void **)game->map);
	skip = first_space(game->map);
	size = 500 / (max_size - skip + with);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img_alpha, 0, 0);
	ft_bzero(game->minimap_addr, with * size
		* ((max_size - skip) * size) * (game->bpp_line / 8));
	minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->gun1, 450, 510);
	// draw_big_map(img);
	// mlx_put_image_to_window(game->mlx, game->win, game->bag_map, 0, 0);

}

void	raycast(t_data *game)
{
	static long	frame;
	int			x;
	int			map_x;
	int			map_y;

	map_x = 0;
	map_y = 0;
	x = 0;
	frame = 0;
	while (x < SCREENWIDTH)
	{
		raycast_help(game, x, map_x, map_y);
		x++;
	}
	put_imgs(game);
	frame++;
}
