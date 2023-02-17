/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:59:11 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/13 16:59:13 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(void)
{
	exit(1);
	return (0);
}

char	**roted_array(char **arr)
{
	int		i;
	int		j;
	int		k;
	char	**new_arr;

	i = 0;
	j = 0;
	k = 0;
	new_arr = (char **)malloc(sizeof(char *) * (arr_2d_len((void **)arr) + 1));
	while (arr[i])
	{
		new_arr[i] = (char *)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1));
		while (arr[i][j])
		{
			if (arr[i][j] != '\n')
				new_arr[i][k++] = arr[i][j];
			j++;
		}
		new_arr[i][k] = '\0';
		k = 0;
		j = 0;
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

char	**ft_remove_new_line(char **arr)
{
	int		i;
	int		j;
	int		k;
	char	**new_arr;

	i = 0;
	j = 0;
	k = 0;
	new_arr = (char **)malloc(sizeof(char *) * (arr_2d_len((void **)arr) + 1));
	while (arr[i])
	{
		new_arr[i] = (char *)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1));
		while (arr[i][j])
		{
			if (arr[i][j] != '\n')
				new_arr[i][k++] = arr[i][j];
			j++;
		}
		new_arr[i][k] = '\0';
		k = 0;
		j = 0;
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

int	make_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	start_one(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			break ;
		i++;
	}
	return (str[i] == '1');
}
