/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:00:55 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arr_2d_len(void **arr)
{
	long long	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char const *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

void	print_arr(char **arr)
{
	while (*arr)
	{
		ft_printf("%s\n", *arr);
		arr++;
	}
}

void	print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

t_list	*arr_2_list(char **arr)
{
	t_list	*list;

	list = NULL;
	while (*arr)
	{
		ft_lstadd_back(&list, ft_lstnew((void *)ft_strdup(*arr)));
		arr++;
	}
	return (list);
}
