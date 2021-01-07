/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 04:53:33 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/07 05:04:24 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *dest;

	if (n)
		dest = s;
	while (n > 0)
	{
		*dest++ = c;
		n--;
	}
	return (s);
}

void	*ft_memcpy_bd(void *dest, const void *src, size_t n, int dir)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (!dir)
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	else if (dir == 1)
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	return (ft_memcpy_bd(dest, src, n, 0));
}

void	ft_bzero(void *s, size_t n)
{
	return (void)ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*result;

	total = nmemb * size;
	result = malloc(total);
	if (result)
		ft_bzero(result, total);
	return (result);
}
