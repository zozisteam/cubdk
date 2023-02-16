/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:29:29 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 14:00:30 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_lline(t_data *game)
{
	int		row;
	int		col;
	int		size;
	char	*line;
	int		longest;

	row = 0;
	size = 0;
	longest = 0;
	while (game->map[row] != NULL)
	{
		col = 0;
		line = game->map[row];
		while (line[col] != '\0')
		{
			size++;
			col++;
		}
		if (size > longest)
			longest = size;
		size = 0;
		row++;
	}
	return (longest);
}

void	draw_map(t_data *game)
{
	int		row;
	int		col;
	char	*line;
	int		skip;

	row = 0;
	skip = first_space(game->map);
	while (game->map[row] != NULL)
	{
		col = 0;
		line = game->map[row];
		while (skip > col)
		{
			col++;
		}
		while (line[col] != '\0')
		{
			if (line[col] && line[col] == '1')
				white_box1(game, (col - skip)
					* game->size, row * game->size, 0x00008B);
			if (line[col] && line[col] == 'O')
				white_box1(game, (col - skip)
					* game->size, row * game->size, 0x00FF00);
			if (line[col] && line[col] == 'C')
				white_box1(game, (col - skip)
					* game->size, row * game->size, 0x8B0000);
			if (line[col] && line[col] == '0')
				white_box1(game, (col - skip)
					* game->size, row * game->size, 0x964B00);
			if (line[col] && line[col] == 'X')
				white_box1(game, (col - skip)
					* game->size, row * game->size, 0xCEC9C9);
			col++;
		}
		row++;
	}
}
// void	draw_big_map(t_data *game)
// {
// 	int		row;
// 	int		col;
// 	char	*line;
// 	int		skip;

// 	row = 0;
// 	skip = first_space(game->map);
// 	while (game->map[row] != NULL)
// 	{
// 		col = 0;
// 		line = game->map[row];
// 		while (skip > col)
// 		{
// 			col++;
// 		}
// 		while (line[col] != '\0')
// 		{
// 			if (line[col] && line[col] == '1')
// 				white_box2(data, (col - skip)
// 					* game->size, row * game->size, 0x00008B);
// 			if (line[col] && line[col] == 'O')
// 				white_box1(data, (col - skip)
// 					* game->size, row * game->size, 0x00FF00);
// 			if (line[col] && line[col] == 'C')
// 				white_box1(data, (col - skip)
// 					* game->size, row * game->size, 0x8B0000);
// 			if (line[col] && line[col] == '0')
// 				white_box1(data, (col - skip)
// 					* game->size, row * game->size, 0x964B00);
// 			if (line[col] && line[col] == 'X')
// 				white_box1(data, (col - skip)
// 					* game->size, row * game->size, 0xCEC9C9);
// 			col++;
// 		}
// 		row++;
// 	}
// }

void	draw_line(t_data *game)
{
	float	step;
	float	x;
	float	y;
	float	i;

	game->dx = (game->var3 - game->var1);
	game->dy = (game->var4 - game->var2);
	if (fabs(game->dx) >= fabs(game->dy))
		step = fabs(game->dx);
	else
		step = fabs(game->dy);
	game->dx = game->dx / step;
	game->dy = game->dy / step;
	x = game->var1;
	y = game->var2;
	i = 1;
	while (i <= step)
	{
		my_mlx_pixel_put(game, x, y, 0x00FF0000);
		x = x + game->dx;
		y = y + game->dy;
		i = i + 1;
	}
}

void	minimap(t_data *game)
{
	double	p2x;
	double	p2y;

	draw_map(game);
	p2x = game->posx
		- (cos(game->player_dir) * 1);
	p2y = game->posy
		+ (sin(game->player_dir) * 1);
	game->var1 = game->posx * game->size;
	game->var2 = game->posy * game->size;
	game->var3 = p2x * game->size;
	game->var4 = ft_max(1, p2y * game->size);
	draw_line(game);
	minimap_walls(game, game->posx * game->size,
		game->posy * game->size, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win, game->img_minimap, 0, 0);
}

int	first_space(char **line)
{
	int	i;
	int	j;
	int	max_space;

	i = 0;
	j = 0;
	max_space = 2147483647;
	while (line[i] != NULL)
	{
		j = 0;
		while (line[i][j] != '\0' && line[i][j] == ' ')
		{
			j++;
		}
		if (j < max_space)
			max_space = j;
		i++;
	}
	return (max_space);
}
