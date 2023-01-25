/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:48:00 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/26 05:18:18 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int		check_if_all_config_saved(t_game *game)
{
	int	c;

	c = 0;
	if (game->NO_texture != NULL)
		c++;
	if (game->SO_texture != NULL)
		c++;
	if (game->WE_texture != NULL)
		c++;
	if (game->EA_texture != NULL)
		c++;
	if (game->C_color != NULL)
		c++;
	if (game->F_color != NULL)
		c++;
	if (c == 6)
		return (1);
	return (0);
}


void	save_config(t_game *game, char *config, char *str)
{
	if (ft_strcmp("NO", config) == 0)
		game->NO_texture = ft_strdup(str);
	else if (ft_strcmp("SO", config) == 0)
		game->SO_texture = ft_strdup(str);
	else if (ft_strcmp("WE", config) == 0)
		game->WE_texture = ft_strdup(str);
	else if (ft_strcmp("EA", config) == 0)
		game->EA_texture = ft_strdup(str);
	else if (ft_strcmp("C", config) == 0)
		game->C_color = ft_strdup(str);
	else if (ft_strcmp("F", config) == 0)
		game->F_color = ft_strdup(str);
}

void	set_config(char *line, t_game *game, char *config)
{
	int		i;
	char	*str;

	i = 0;
	while (ft_isspace(line[i]) == 1 && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return ;
	if (ft_strncmp(&line[i], config, ft_strlen(config)) != 0)
		return ;
	i += ft_strlen(config);
	while (ft_isspace(line[i]) == 1 && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return ;
	str = ft_strdup(&line[i]);
	save_config(game, config, str);
	free(str);
}

void		save_map_config(t_game *game)
{
	while(game->map_data[game->i_pars] != NULL)
	{
		set_config(game->map_data[game->i_pars], game, "NO");
		set_config(game->map_data[game->i_pars], game, "SO");
		set_config(game->map_data[game->i_pars], game, "WE");
		set_config(game->map_data[game->i_pars], game, "EA");
		set_config(game->map_data[game->i_pars], game, "C");
		set_config(game->map_data[game->i_pars], game, "F");
		game->i_pars++;
		if (check_if_all_config_saved(game) == 1)
			break;
	}
	if (check_if_all_config_saved(game) != 1)
	{
		printf("Invalid config\n");
		free_if_er(game);
	}
}