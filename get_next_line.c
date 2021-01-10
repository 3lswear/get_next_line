/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/10 04:45:16 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	size_t pos;
	static size_t linebreak;
	char *buf;
	ssize_t ret;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	*line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	pos = linebreak;
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		printf("the buffer is =>[%s]\n", buf);
		while (buf[pos % BUFFER_SIZE] != '\n')
		{
			*line = ft_reallocarray(*line, sizeof(char), pos + 1 - linebreak);
			pos++;
			if ((pos % BUFFER_SIZE) == 0)
				break;
		}
		if (buf[pos % BUFFER_SIZE] == '\n')
		{
			ft_memcpy(&(*line)[ft_strlen(*line)], buf, pos % BUFFER_SIZE);
			linebreak = pos;
			break;
		}
		else
		{
			ft_memcpy(*line, buf, BUFFER_SIZE);
		}
	}

	/* *line = (char *)ft_calloc(sizeof(char), pos + 1); */

	/* read_pos = 0; */
	/* while ((read_pos < pos) && (ret = read(fd, buf, BUFFER_SIZE))) */
	/* { */
	/* 	printf("read a buffer\n"); */
	/* 	ft_memcpy(&((*line)[read_pos]), buf, ret); */
	/* 	read_pos += ret; */
	/* } */

	return (1);
}
