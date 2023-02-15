/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:00 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 17:08:29 by alalmazr         ###   ########.fr       */
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
		error_();
	return (fd);
}

char	*get_file_data(int fd, t_game *game)
{
	int		z;

	game->read_data_line = NULL;
	game->read_data_tmp = NULL;
	z = 0;
	while (!z)
	{
		game->read_data_line = get_next_line(fd);
		if (!game->read_data_line || start_one(game->read_data_line))
		{
			z = 1;
			break ;
		}
		if (ft_strlen(game->read_data_line) == 0)
		{
			free(game->read_data_line);
			continue ;
		}
		game->read_data_line = ft_strtrim(game->read_data_line, " \t");
		game->read_data_tmp = ft_strjoin_gnl(game->read_data_tmp,
				game->read_data_line);
		free(game->read_data_line);
	}
	game->first_line = game->read_data_line;
	return (game->read_data_tmp);
}

void	raycast(t_game *game)
{
	game->x = 0;
	while (game->x < SCREENWIDTH)
	{
		raycast_init(game);
		raycast_1(game);
		raycast_2(game);
		raycast_3(game);
		raycast_4(game);
		raycast_5(game);
		raycast_6(game);
		raycast_7(game);
		game->x++;
	}
	raycast_8(game);
}
