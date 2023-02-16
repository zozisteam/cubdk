/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:55:11 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	a;
	size_t	b;
	char	*m;

	m = (char *)h;
	a = 0;
	if (!*n)
		return ((char *)h);
	while (h[a] != '\0' && a < len)
	{
		b = 0;
		while (h[a + b] == n[b] && n[b] != '\0' && a + b < len)
		{
			b++;
		}
		if (b == ft_strlen(n))
			return (&m[a]);
		a++;
	}
	return (NULL);
}
