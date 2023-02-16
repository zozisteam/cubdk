/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:30:11 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	g;
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	g = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == g)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}

// int main ()
// {
//    printf("%p", ft_memchr("Hello!", 100, 18));
// }