/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:43:04 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_color3(t_data *game, int *n, int *j)
{
	int	i;
	int	k;

	i = *j;
	k = *n;
	if (game->data[i][k] == 'F')
	{
		k += 2;
		while (game->data[i][k] == ' ' || game->data[i][k] == '\t')
			k++;
		game->f_color.f = ft_strdup(game->data[i] + k);
	}
	if (game->data[i][k] == 'C')
	{
		k += 2;
		while (game->data[i][k] == ' ' || game->data[i][k] == '\t')
			k++;
		game->c_color.c = ft_strdup(game->data[i] + k);
	}
}

int	cheack_colore4(t_data *game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (game->f_color.f[i + 1] == '\0')
		return (0);
	while (game->f_color.f[i] != '\0')
	{
		if (ft_isdigit(game->f_color.f[i]) == 0 && game->f_color.f[i] != ',')
			return (0);
		if (game->f_color.f[i] == ',')
			k++;
		i++;
	}
	if (k != 2)
	{
		ft_putstr_fd("Error\nthe color is not valid", 2);
		return (0);
	}
	return (1);
}

int	fill_data(t_data *game)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (game->data[i])
	{
		check_color1(game, &k, &i);
		check_color2(game, &k, &i);
		check_color3(game, &k, &i);
		i++;
		k = 0;
	}
	return (1);
}

void	fill_the_colore2(t_data *game)
{
	char	**tmp;

	tmp = ft_split(game->f_color.f, ',');
	if (tmp[2] == NULL)
		ft_error();
	game->f_color.r = ft_atoi(tmp[0]);
	game->f_color.g = ft_atoi(tmp[1]);
	game->f_color.b = ft_atoi(tmp[2]);
	free_arr((void **)tmp);
	tmp = ft_split(game->c_color.c, ',');
	if (tmp[1] == NULL)
		ft_error();
	if (tmp[0] == NULL)
		ft_error();
	game->c_color.r = ft_atoi(tmp[0]);
	game->c_color.g = ft_atoi(tmp[1]);
	if (tmp[2] == NULL)
		ft_error();
	game->c_color.b = ft_atoi(tmp[2]);
	free_arr((void **)tmp);
}

int	color_fill(t_data *game)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (cheack_colore4(game) == 0)
		return (0);
	while (game->c_color.c[i])
	{
		if (ft_isdigit(game->c_color.c[i]) == 0 && game->c_color.c[i] != ',')
			return (0);
		if (game->c_color.c[i] == ',')
			k++;
		i++;
	}
	if (k != 2)
	{
		ft_putstr_fd("Error\nthe color is not valid", 2);
		return (0);
	}
	fill_the_colore2(game);
	return (1);
}
