/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:49 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:13:09 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_close_map(char **map)
{
	int		i;
	char	*str;

	i = 0;
	while (map[i])
	{
		str = ft_strtrim(map[i], " \t");
		if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		{
			free(str);
			return (0);
		}
		free(str);
		i++;
	}
	return (1);
}

int	check_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ')
		return (0);
	return (1);
}

int	invalid_map(char **map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (check_char(map[i][j]) == 0)
				return (0);
			j++;
		}
		str = ft_strtrim(map[i], " \t");
		if (ft_strlen(str) == 0)
		{
			free(str);
			return (0);
		}
		free(str);
		j = 0;
		i++;
	}
	return (1);
}

int	chek_imgs(t_game *game)
{
	if (invalid_img(game->_ea) == 0)
		return (0);
	if (invalid_img(game->_so) == 0)
		return (0);
	if (invalid_img(game->_we) == 0)
		return (0);
	if (invalid_img(game->_no) == 0)
		return (0);
	return (1);
}

int	check_dir(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}
