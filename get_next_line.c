/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/12 03:26:00 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	size_t pos; //position where we are seeking in fd
	static size_t linebreak; //previous line break position
	char buf[BUFFER_SIZE + 1];
	ssize_t ret;

	/* buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)); */

	*line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!linebreak)
	{
		ft_bzero(buf, BUFFER_SIZE);
		pos = linebreak;
	}
	else
		pos = linebreak + 1;
	while (1)
	{
		if ((pos % BUFFER_SIZE) == 0)
		//if reached end of buffer, get a new one
		{
			if (!(ret = read(fd, buf, BUFFER_SIZE)))
				break;
			/* pos++; */
		}
		/* printf("the buffer is =>[%s]\n", buf); */
		while (buf[pos % BUFFER_SIZE] != '\n')
		{
			*line = ft_reallocarray(*line, sizeof(char), pos + 1 - linebreak);
			pos++;
			if ((pos % BUFFER_SIZE) == 0)
				break;
		}
		if (buf[pos % BUFFER_SIZE] == '\n') //found newline
		{
			if ((pos / BUFFER_SIZE) - 1 == (linebreak / BUFFER_SIZE)) //last break in this buffer
				ft_memcpy(&(*line)[ft_strlen(*line)], &(buf[linebreak % BUFFER_SIZE]), pos % BUFFER_SIZE);
			else
				ft_memcpy(&(*line)[ft_strlen(*line)], buf, pos % BUFFER_SIZE);
			linebreak = pos;
			break;
		}
		else //reached end of the buffer, no newline
			if ((pos / BUFFER_SIZE) - 1 == (linebreak / BUFFER_SIZE)) //last break in this buffer
				ft_memcpy(&(*line)[ft_strlen(*line)],
						&(buf[(linebreak) % BUFFER_SIZE]),
						BUFFER_SIZE - ((linebreak) % BUFFER_SIZE));
			else
				ft_memcpy(&(*line)[ft_strlen(*line)], buf, BUFFER_SIZE);

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
