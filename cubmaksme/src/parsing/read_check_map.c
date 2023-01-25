/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:31:05 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/11 07:14:19 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	skip_spaces_till_map_starts(t_game *game)
{
	int i;

	while (game->map_data[game->i_pars] != NULL)
	{
		i = 0;
		while (game->map_data[game->i_pars][i] != '\0')
		{
			if (ft_isspace(game->map_data[game->i_pars][i]) != 1)
				return ;
			i++;
		}
		game->i_pars++;
	}
}

int	call_checkers(char *s, t_game *game)
{
	int	err;

	err = 0;
	if (s == NULL)
		return (-1);
	game->map_data = ft_split(s, '\n');
    save_map_config(game);
	check_map_config(game);
	skip_spaces_till_map_starts(game);
	save_map(game);
	return (err);
}

int	read_map(char *file, t_game *game)
{
	int		fd_error;
	char	*temp;
	char	*s;

	fd_error = open(file, O_RDONLY);
	s = NULL;
	temp = get_next_line(fd_error);
	while (temp != NULL)
	{
		s = ft_strjoin_gnl(s, temp);
		temp = get_next_line(fd_error);
		if (ft_strlen(temp) == 1 && temp[0] == '\n')
		{
			free(temp);
			temp = ft_strdup(" \n");
		}
	}
	free(temp);
	fd_error = call_checkers(s, game);
	return (fd_error);
}

void	read_check_map(char *s, t_game *game)
{
	int	err;
	
	err = read_map(s, game);
	if (err == -1)
	{
		ft_printf("Error\nEmpty/Wrong file\n");
		free_if_er(game);
	}
	if (err != 0)
	{
		ft_printf("Error\nMap Error\n");
		free_if_er(game);
	}
	find_player(game);
}