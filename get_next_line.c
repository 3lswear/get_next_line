/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/10 04:02:47 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static size_t pos;
	char *buf;
	ssize_t ret;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	pos = 0;
	*line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		printf("the buffer is =>[%s]\n", buf);
		while (buf[pos % BUFFER_SIZE] != '\n')
		{
			*line = ft_reallocarray(*line, sizeof(char), pos + 1);
			pos++;
		}
		if (buf[pos % BUFFER_SIZE] == '\n')
			break;
	}
	ft_memcpy(*line, buf, pos % BUFFER_SIZE);

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
