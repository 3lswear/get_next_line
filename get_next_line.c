/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/22 00:03:36 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

ssize_t	check_buf(char *substring, char **line, ssize_t ret)
{
	char *point;
	char *tmp;

	if ((point = ft_strchr_bd(substring, '\n', 0))) //found a newline
	{
		*point++ = 0;
		if (!ret)
		{
			if (!(*line = ft_strdup(substring)))
				return (-1);
			ft_strlcpy(substring, point, ft_strlen(point) + 1);
		}
		else
		{
			tmp = *line;
			if (!(*line = ft_strjoin(*line, substring)))
				return (-1);
			free(tmp);
		}
		return (1); //copied a line to *line
	}
	else //no newline in substring
	{
		if (!ret)
		{
			*line = ft_strdup(substring);
		}
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, substring);
			free(tmp);
		}
		ft_bzero(substring, ft_strlen(substring) + 1);
		if (!(*line))
			return (-1);
		return (0); // no newline in substring, or no substring at all
	}
}

int		get_next_line(int fd, char **line)
{
	static char	substring[BUFFER_SIZE + 1];
	ssize_t		ret;
	ssize_t		res;
	/* char		*point; */
	/* char		*tmp; */

	ret = 0;
	if (!line || (!BUFFER_SIZE) || (res = check_buf(&(substring
		[ft_strlen(substring) + 1]), line, ret)) == -1 || fd < 0)
		return (-1);
	while (res == 0 && (ret = read(fd, substring, BUFFER_SIZE)) > 0)
	{
		substring[ret] = 0;
		/* printf("\033[0;31m[%s]:%lu\n\033[0m", substring, ft_strlen(substring)); */
		if ((res = check_buf(substring, line, ret)) == -1)
			return (-1);
	}
	if (res == 0 && ret == 0)
	{
		return (0);
	}
	else if (ret == -1)
		return (-1);
	else
		return (1);
}
