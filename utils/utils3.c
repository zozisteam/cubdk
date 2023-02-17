/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:24 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/16 22:19:53 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put1(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game ->minimap_addr
		+ (y * game->size_line + x * (game->bpp_line / 8));
	*(unsigned int *)dst = color;
}

//making the wall blocks
void	minimap_walls(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game ->size)
	{
		j = 0;
		while (j < game ->size)
		{
			my_mlx_pixel_put(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

//making player block in minimapp
// divided by 5 to make the player smaller than walls
void	minimap_player(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_max(1, game->size / 5))
	{
		j = 0;
		while (j < game->size / 5)
		{
			my_mlx_pixel_put(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
