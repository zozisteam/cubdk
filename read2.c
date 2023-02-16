/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:08:39 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
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
				printf("Error");
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

int	ft_free(char *str)
{
	if (ft_strlen(str) == 0)
	{
		free(str);
		str = NULL;
	}
	return (1);
}

char	*read_meta_data(int fd, t_data *game, char *line1)
{
	char	*line;
	char	*tmp;
	int		z;

	line = NULL;
	tmp = NULL;
	z = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || start_one(line))
			break ;
		if (ft_strlen(line) == 0 && ft_free(line))
			continue ;
		if (z == 0)
		{
			tmp = ft_strjoin_mod(tmp, line1);
			z = 1;
		}
		line = ft_strtrim(line, " \t");
		tmp = ft_strjoin_mod(tmp, line);
		free(line);
	}
	game->first_line = line;
	return (tmp);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}
