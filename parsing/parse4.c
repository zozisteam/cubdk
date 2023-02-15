/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:59:03 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 22:59:23 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_color3(t_game *data, int *n, int *j)
{
	int	i;
	int	k;

	i = *j;
	k = *n;
	if (data->data[i][k] == 'F')
	{
		k += 2;
		while (data->data[i][k] == ' ' || data->data[i][k] == '\t')
			k++;
		data->f_color.f = ft_strdup(data->data[i] + k);
	}
	if (data->data[i][k] == 'C')
	{
		k += 2;
		while (data->data[i][k] == ' ' || data->data[i][k] == '\t')
			k++;
		data->c_color.c = ft_strdup(data->data[i] + k);
	}
}

int	cheack_colore4(t_game *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (data->f_color.f[i + 1] == '\0')
		return (0);
	while (data->f_color.f[i] != '\0')
	{
		if (ft_isdigit(data->f_color.f[i]) == 0 && data->f_color.f[i] != ',')
			return (0);
		if (data->f_color.f[i] == ',')
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

int	fill_data(t_game *data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (data->data[i])
	{
		check_color(data, &k, &i);
		check_color2(data, &k, &i);
		check_color3(data, &k, &i);
		i++;
		k = 0;
	}
	return (1);
}

void	fill_the_colore2(t_game *data)
{
	char	**tmp;

	tmp = ft_split(data->f_color.f, ',');
	if (tmp[2] == NULL)
		error_();
	data->f_color.r = ft_atoi(tmp[0]);
	data->f_color.g = ft_atoi(tmp[1]);
	data->f_color.b = ft_atoi(tmp[2]);
	ft_freearray((void **)tmp);
	tmp = ft_split(data->c_color.c, ',');
	if (tmp[1] == NULL)
		error_();
	if (tmp[0] == NULL)
		error_();
	data->c_color.r = ft_atoi(tmp[0]);
	data->c_color.g = ft_atoi(tmp[1]);
	if (tmp[2] == NULL)
		error_();
	data->c_color.b = ft_atoi(tmp[2]);
	ft_freearray((void **)tmp);
}

int	fill_color(t_game *data)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (cheack_colore4(data) == 0)
		return (0);
	while (data->c_color.c[i])
	{
		if (ft_isdigit(data->c_color.c[i]) == 0 && data->c_color.c[i] != ',')
			return (0);
		if (data->c_color.c[i] == ',')
			k++;
		i++;
	}
	if (k != 2)
	{
		ft_putstr_fd("Error\nthe color is not valid", 2);
		return (0);
	}
	fill_the_colore2(data);
	return (1);
}
