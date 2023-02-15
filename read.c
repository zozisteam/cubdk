/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:56:35 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 23:22:29 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_first_line(int fd)
{
	char	*line;
	char	*free_line;

	line = get_next_line(fd);
	if (line == NULL)
		error_();
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

t_list	*get_lines(int fd, t_game *game)
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

void	make_map(t_list *list, t_game *game)
{
	char	**tmp4;
	char	**tmp3;

	tmp4 = ft_lsttoarr(list);
	tmp3 = ft_remove_new_line(tmp4);
	printarr(tmp3);
	game->map = tmp3;
	ft_freearray((void **)tmp4);
	ft_lstclear(&list, free);
}

void	read_map(char *str, t_game *game)
{
	int		fd;
	char	*line;
	char	*meta_data;
	char	**x;

	game->first_line = NULL;
	fd = open_file(str);
	line = read_first_line(fd);
	line = remove_empty_lines(line, fd);
	meta_data = get_file_data(fd, game);
	x = ft_split(meta_data, '\n');
	game->game = rotate_arr(x);
	free(meta_data);
	make_map(get_lines(fd, game), game);
}

// void	read_map(char *str, t_game *game)
// {
// 	int		fd;
// 	char	*next_line;
// 	char	*s;

// 	s = NULL;
// 	fd = open(str, O_RDONLY);
// 	next_line = get_next_line(fd);
// 	while (next_line)
// 	{
// 		s = ft_strjoin_gnl(s, next_line);
// 		free(next_line);
// 		next_line = get_next_line(fd);
// 	}
// 	game->data = ft_split(s, '\n');
// 	for (int i = 0; game->data[i] != NULL; i++)
// 		printf("%s\n", game->data[i]);
// 	free(s);
// 	free(next_line);
// 	close(fd);
// }