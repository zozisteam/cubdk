/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:00 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/13 16:58:01 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_name(char *str)
{
	while (*str)
	{
		if (*str == '.')
		{
			if (strcmp(str + 1, "cub"))
			{
				exit(EXIT_FAILURE);
			}
			else
				break ;
		}
		str++;
	}
}

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	return (fd);
}

char	*read_meta_data(int fd, t_data *data)
{
	int		z;

	data->read_data_line = NULL;
	data->read_data_tmp = NULL;
	z = 0;
	while (!z)
	{
		data->read_data_line = get_next_line(fd);
		if (!data->read_data_line || start_one(data->read_data_line))
		{
			z = 1;
			break ;
		}
		if (ft_strlen(data->read_data_line) == 0)
		{
			free(data->read_data_line);
			continue ;
		}
		data->read_data_line = ft_strtrim(data->read_data_line, " \t");
		data->read_data_tmp = ft_strjoin_gnl(data->read_data_tmp,
				data->read_data_line);
		free(data->read_data_line);
	}
	data->first_line = data->read_data_line;
	return (data->read_data_tmp);
}

void	raycast(t_data *img)
{
	img->x = 0;
	while (img->x < SCREENWIDTH)
	{
		raycast_init(img);
		raycast_1(img);
		raycast_2(img);
		raycast_3(img);
		raycast_4(img);
		raycast_5(img);
		raycast_6(img);
		raycast_7(img);
		img->x++;
	}
	raycast_8(img);
}
