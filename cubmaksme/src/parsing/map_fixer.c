/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fixer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:53:05 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/06 04:03:31 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

char  *insertString(char* destination, int pos, char* seed)
{
	char	*str;
	char	*temp;

	str = (char*)malloc(ft_strlen(destination) + ft_strlen(seed) + 1);
	temp = ft_substr(destination, 0, pos);
	str = ft_strjoin(temp, seed);
	free(temp);
	if (pos != 0)
		temp = ft_strjoin(str, destination + pos + 2);
	else
		temp = ft_strjoin(str, destination + pos);
	free(destination);
	free(str);
	return (temp);
}

void	add_spaces_to_map_smaller_lines(t_game *game)
{
	int		line_length;
	int		i;
	char	*temp;
	
	temp = NULL;
	line_length = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		while (ft_strlen_gnl(game->map[i]) < game->w)
		{
			if (temp != NULL)
				free(temp);
			temp = ft_strjoin(game->map[i], " ");
			free(game->map[i]);
			game->map[i] = ft_strdup(temp);
		}
		i++;
	}
}

void	find_biggest_map_line(t_game *game)
{
	int	line_length;
	int	i;

	line_length = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		line_length = ft_strlen(game->map[i]);
		if (line_length > game->w)
			game->w = line_length;
		i++;
	}
}

void	replace_tabulations_to_spaces(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '\t')
				game->map[i] = insertString(game->map[i], j, "    ");
			j++;
		}
		i++;
	}
}

void	map_fixer(t_game *game)
{
	replace_tabulations_to_spaces(game);
	find_biggest_map_line(game);
	add_spaces_to_map_smaller_lines(game);
}