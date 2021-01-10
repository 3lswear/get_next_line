/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 04:53:33 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/10 04:00:10 by sunderle         ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*result;

	if ((nmemb) && ((18446744073709551615UL / nmemb) < size))
		return (NULL);
	total = nmemb * size;
	result = malloc(total);
	if (result)
		ft_bzero(result, total);
	return (result);
}

void *ft_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *result;

	if (!(result = ft_calloc(nmemb, size)))
		return (NULL);
	else
	{
		ft_memcpy(result, ptr, ft_strlen(ptr));
		free(ptr);
		return (result);
	}
}
