/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:29:00 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/03 01:52:30 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	check_file_existence(t_game *game, char *s)
{
	int	fd;

	fd = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		printf("File: %s does not exist\n", s);
		free_if_er(game);
	}
}

void	set_rgb(t_game *game, char **rgb, int top_down)
{
	if(top_down == 1)
	{
		game->C.r = ft_atoi(rgb[0]);
		game->C.g = ft_atoi(rgb[1]);
		game->C.b = ft_atoi(rgb[2]);
	}
	else
	{
		game->F.r = ft_atoi(rgb[0]);
		game->F.g = ft_atoi(rgb[1]);
		game->F.b = ft_atoi(rgb[2]);
	}
}

int		check_rgb_validity(t_game *game, char *s, int top_down)
{
	char	**rgb;
	int		i;

	i = 0;
	rgb = ft_split(s, ',');
	if (rgb == NULL)
		return (1);
	while (rgb[i] != NULL)
		i++;
	if (i != 3)
		return (1);
	i = 0;
	while (rgb[i] != NULL)
	{
		if (ft_strlen(rgb[i]) > 3)
			return (1);
		i++;
	}
	set_rgb(game, rgb, top_down);
	return (0);
}

void	check_map_config(t_game *game)
{
	int err;

	err = 0;
    check_file_existence(game, game->NO_texture);
	check_file_existence(game, game->SO_texture);
	check_file_existence(game, game->WE_texture);
	check_file_existence(game, game->EA_texture);
	err += check_rgb_validity(game, game->C_color, 1);
	err += check_rgb_validity(game, game->F_color, 2);
	if (err != 0)
	{
		printf("invalid rgb config\n");
		free_if_er(game);
	}
}