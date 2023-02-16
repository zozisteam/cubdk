/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:53:55 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:04 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_first_line(int fd)
{
	char	*line;
	char	*free_line;

	line = get_next_line(fd);
	if (line == NULL)
		ft_error();
	free_line = line;
	line = ft_strtrim(free_line, " \t");
	free(free_line);
	return (line);
}

char	*remove_empty_lines(char *line, int fd)
{
	char	*free_line;

	while (ft_strlen(line) == 0)
	{
		free(line);
		free_line = get_next_line(fd);
		line = ft_strtrim(free_line, " \t");
		free(free_line);
	}
	return (line);
}

t_list	*get_lines(int fd, t_data *game)
{
	t_list	*list;
	char	*line;
	t_list	*el;

	list = NULL;
	line = game->first_line;
	while (line != NULL)
	{
		el = ft_lstnew(line);
		if (el == NULL)
			exit(1);
		ft_lstadd_back(&list, el);
		line = get_next_line(fd);
	}
	return (list);
}

void	make_map(t_list *list, t_data *game)
{
	char	**tmp4;
	char	**tmp3;

	tmp4 = lst_2_arr(list);
	tmp3 = ft_remove_new_line(tmp4);
	print_arr(tmp3);
	game->map = tmp3;
	free_arr((void **)tmp4);
	ft_lstclear(&list, free);
}

void	read_map(char *str, t_data *game)
{
	int		fd;
	char	*line;
	char	*meta_data;
	char	**x;

	game->first_line = NULL;
	fd = open_file(str);
	line = read_first_line(fd);
	line = remove_empty_lines(line, fd);
	meta_data = read_meta_data(fd, game, line);
	x = ft_split(meta_data, '\n');
	game->data = rotate_arr(x);
	free(meta_data);
	make_map(get_lines(fd, game), game);
}
