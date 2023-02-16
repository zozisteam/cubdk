/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:57:28 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *game)
{
	int	i;
	int	j;
	int	count;
	int	skip;

	i = 0;
	j = 0;
	count = 0;
	skip = first_space(game->map);
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				draw_player_helper(game, i, j, skip);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	create_img2(t_data *game)
{
	int	i;

	i = 400;
	game->gun1 = mlx_xpm_file_to_image(game->mlx,
			"./img/gun4c.xpm", &i, &i);
	game->gun2 = mlx_xpm_file_to_image(game->mlx,
			"./img/gun4b.xpm", &i, &i);
}

void	create_img1(t_data *game)
{
	game->ptr[0] = mlx_xpm_file_to_image(game->mlx, game->no,
			&game->width[0], &game->height[0]);
	game->texture[0] = (unsigned int (*))mlx_get_data_addr(game->ptr[0],
			&game->bpp[0], &game->ll[0], &game->en[0]);
	game->ptr[1] = mlx_xpm_file_to_image(game->mlx, game->so,
			&game->width[1], &game->height[1]);
	game->texture[1] = (unsigned int (*))mlx_get_data_addr(game->ptr[1],
			&game->bpp[1], &game->ll[1], &game->en[1]);
	game->ptr[2] = mlx_xpm_file_to_image(game->mlx, game->ea,
			&game->width[2], &game->height[2]);
	game->texture[2] = (unsigned int (*))mlx_get_data_addr(game->ptr[2],
			&game->bpp[2], &game->ll[2], &game->en[2]);
	game->ptr[3] = mlx_xpm_file_to_image(game->mlx, game->we,
			&game->width[3], &game->height[3]);
	game->texture[3] = (unsigned int (*))mlx_get_data_addr(game->ptr[3],
			&game->bpp[3],
			&game->ll[3], &game->en[3]);
	create_img2(game);
}

int	mouse(int x, int y, t_data *game)
{
	(void)y;
	mlx_mouse_hide();
	if (x > SCREENWIDTH / 2)
	{
		key_check_rotate(124, game);
	}
	else
	{
		key_check_rotate(123, game);
	}
	raycast(game);
	mlx_mouse_move(game->win, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	return (0);
}
