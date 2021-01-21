/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 04:53:33 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/21 14:32:33 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char *dest;

	if (n)
		dest = s;
	while (n > 0)
	{
		*dest++ = 0;
		n--;
	}
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

char	*ft_strchr_bd(const char *s, int c, int dir)
{
	char	*retval;
	size_t	i;

	retval = NULL;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if ((unsigned char)c == s[i])
			retval = (char *)&s[i];
		if ((dir == 0) && (retval))
			return (retval);
		i++;
	}
	return (retval);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	i = 0;
	if (size)
	{
		while ((i < size - 1) && (i < src_len))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(src) + 1;
	dest = (char *)malloc(size * sizeof(char));
	if (dest)
		ft_strlcpy(dest, src, size);
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	result;

	i = ft_strlen(dest);
	if (ft_strlen(dest) < size)
		result = i + ft_strlen(src);
	else
		result = size + ft_strlen(src);
	while ((i < size - 1) && (*src) && (size > 0))
		dest[i++] = *(src++);
	dest[i] = 0;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result)
	{
		ft_strlcpy(result, (char *)s1, ft_strlen(s1) + 1);
		ft_strlcat(result, (char *)s2, len + 1);
	}
	return (result);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
		if (((unsigned char *)s)[i - 1] == (unsigned char)c)
			return (&((unsigned char *)s)[i - 1]);
	return (NULL);
}
