/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/21 00:48:35 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int check(char *substring, char **line)
{
	char *point;

	if (substring)
	{
		if ((point = ft_strchr_bd(substring, '\n', 0)))
		{
			*point = 0;
			if (!(*line = ft_strdup(substring)))
				return (-1);
			point++;
			ft_strlcpy(substring, point, ft_strlen(substring) + ft_strlen(point) + 1);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(substring)))
				return (-1);
			ft_bzero(substring, sizeof(substring));
		}
	}
	else
		*line = ft_calloc(sizeof(char), 1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *substring;
	ssize_t ret;
	int rp;
	char *point;
	char *tmp;

	ft_bzero(buf, BUFFER_SIZE + 1);
	if (!line)
		return (-1);
	if ((rp = check(substring, line)) == -1)
		return (-1);
	while (rp == 0 && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = 0;
		if ((point = ft_strchr_bd(buf, '\n', 0)))
		{
			*point++ = 0;
			if (!(substring = ft_strdup(point)))
				return (-1);
			rp = 1;
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(tmp);
	}
	if (rp == 0 && ret == 0)
		return (0);
	else
		return (1);
}
