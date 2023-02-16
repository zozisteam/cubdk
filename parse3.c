/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:04:23 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color_range(t_data *game)
{
	if (game->f_color.r > 255 || game->f_color.r < 0)
		return (0);
	if (game->f_color.g > 255 || game->f_color.g < 0)
		return (0);
	if (game->f_color.b > 255 || game->f_color.b < 0)
		return (0);
	if (game->c_color.r > 255 || game->c_color.r < 0)
		return (0);
	if (game->c_color.g > 255 || game->c_color.g < 0)
		return (0);
	if (game->c_color.b > 255 || game->c_color.b < 0)
		return (0);
	return (1);
}

int	invalid_img(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'm' || str[i - 2] != 'p'
		|| str[i - 3] != 'x' || str[i - 4] != '.')
		return (0);
	return (1);
}

int	exist_image(t_data *game)
{
	if (check_img(game->ea) == 0)
		return (0);
	if (check_img(game->so) == 0)
		return (0);
	if (check_img(game->we) == 0)
		return (0);
	if (check_img(game->no) == 0)
		return (0);
	return (1);
}

int	check_img(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check(char **data)
{
	int	i;

	i = arr_2d_len((void **)data);
	if (i != 6)
		return (0);
	return (1);
}
