/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:47:03 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color1(t_data *game, int *n, int *j)
{
	int	i;
	int	k;

	i = *j;
	k = *n;
	while (game->data[i][k] == ' ' || game->data[i][k] == '\t')
			k++;
	if (game->data[i][k] == 'E' && game->data[i][k + 1] == 'A')
	{
		k += 3;
		while (game->data[i][k] == ' ' || game->data[i][k] == '\t')
			k++;
		game->ea = ft_strdup(game->data[i] + k);
	}
	else if (game->data[i][k] == 'S' && game->data[i][k + 1] == 'O')
	{
		k += 3;
		while (game->data[i][k] == ' ' || game->data[i][k] == '\t')
		{
			k++;
		}
		game->so = ft_strdup(game->data[i] + k);
	}
	return (1);
}

void	check_color2(t_data *game, int *n, int *j)
{
	int	i;
	int	k;

	i = *j;
	k = *n;
	if (game->data[i][k] == 'W' && game->data[i][k + 1] == 'E')
	{
		k += 3;
		while (game->data[i][k] == ' ' || game->data[i][k] == '\t')
			k++;
		game->we = ft_strdup(game->data[i] + k);
	}
	else if (game->data[i][k] == 'N' && game->data[i][k + 1] == 'O')
	{
		k += 3;
		while (game->data[i][k] == ' ' || game->data[i][k] == '\t')
			k++;
		game->no = ft_strdup(game->data[i] + k);
	}
}

int	cheack_zero_helper(char **map, int *i, int *j)
{
	int	n;
	int	m;

	n = *i;
	m = *j;
	if (map[n][m] == '0' || map[n][m] == 'W'
			|| map[n][m] == 'S' || map[n][m] == 'E'
			|| map[n][m] == 'N' || map[n][m] == 'X'
			|| map[n][m] == 'C' || map[n][m] == 'O')
	{
		if (n > 0 && m > 0 && (n < arr_2d_len((void **)map) - 1)
			&& (m < (int)ft_strlen(map[n]) - 1))
		{
			if ((m > (int)ft_strlen(map[n - 1]) - 1
					&& (m > (int)ft_strlen(map[n + 1])) - 1))
				return (0);
			if (map[n + 1][m] == ' ' || map[n - 1][m] == ' '
				|| (map[n][m + 1] != '\0' && map[n][m + 1] == ' ')
					|| map[n][m - 1] == ' ')
				return (0);
		}
	}
	return (1);
}

int	check_zeros(t_data *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (cheack_zero_helper(map, &i, &j) == 0)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	*arrtostr(char **arr)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (arr[i])
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = 0;
	len = 0;
	while (arr[i])
	{
		ft_strcpy(&str[len], arr[i]);
		len += ft_strlen(arr[i]);
		i++;
	}
	return (str);
}
