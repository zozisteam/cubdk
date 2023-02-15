/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:58 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 22:43:07 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color_range(t_game *data)
{
	if (data->f_color.r > 255 || data->f_color.r < 0)
		return (0);
	if (data->f_color.g > 255 || data->f_color.g < 0)
		return (0);
	if (data->f_color.b > 255 || data->f_color.b < 0)
		return (0);
	if (data->c_color.r > 255 || data->c_color.r < 0)
		return (0);
	if (data->c_color.g > 255 || data->c_color.g < 0)
		return (0);
	if (data->c_color.b > 255 || data->c_color.b < 0)
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

int	exist_image(t_game *data)
{
	if (check_img_exist(data->_ea) == 0)
		return (0);
	if (check_img_exist(data->_so) == 0)
		return (0);
	if (check_img_exist(data->_we) == 0)
		return (0);
	if (check_img_exist(data->_no) == 0)
		return (0);
	return (1);
}

int	check_img_exist(char *str)
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
