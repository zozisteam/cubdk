/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:29 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:05:04 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	max_line_len(t_game *data)
{
	int		row;
	int		col;
	int		size;
	char	*line;
	int		longest;

	row = 0;
	size = 0;
	longest = 0;
	while (data->map[row] != NULL)
	{
		col = 0;
		line = data->map[row];
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

void	draw_map(t_game *data)
{
	int		row;
	int		col;
	char	*line;
	int		skip;

	row = 0;
	skip = first_space(data->map);
	while (data->map[row] != NULL)
	{
		col = 0;
		line = data->map[row];
		while (skip > col)
		{
			col++;
		}
		while (line[col] != '\0')
		{
			if (line[col] && line[col] == '1')
				minimap_walls(data, (col - skip)
					* data->size, row * data->size, 0x00ffbff4);
			col++;
		}
		row++;
	}
}

void	draw_line(t_game *game)
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

void	minimap(t_game *data)
{
	double	p2x;
	double	p2y;

	draw_map(data);
	p2x = data->posx
		- (cos(data->player_dir) * 1);
	p2y = data->posy
		+ (sin(data->player_dir) * 1);
	data->var1 = data->posx * data->size;
	data->var2 = data->posy * data->size;
	data->var3 = p2x * data->size;
	data->var4 = max_(1, p2y * data->size);
	draw_line(data);
	minimap_player(data, data->posx * data->size,
		data->posy * data->size, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img_minimap, 0, 0);
}

int	first_space(char **line)
{
	int	i;
	int	j;
	int	max_spaces;

	i = 0;
	j = 0;
	max_spaces = 2147483647;
	while (line[i] != NULL)
	{
		j = 0;
		while (line[i][j] != '\0' && line[i][j] == ' ')
		{
			j++;
		}
		if (j < max_spaces)
			max_spaces = j;
		i++;
	}
	return (max_spaces);
}