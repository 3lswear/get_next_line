/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/20 03:34:53 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

ssize_t get_a_buf(int fd, char **buf)
{
	ssize_t ret;

	return ((ret = read(fd, *buf, BUFFER_SIZE)));
}

void eob_no_newline(size_t pos, size_t linebreak, char *buf, char **line)
//reached end of the buffer, no newline
{
	if (((pos - 1) / BUFFER_SIZE) == (linebreak / BUFFER_SIZE)) //check if last newline in this buffer
		ft_memcpy(&(*line)[ft_strlen(*line)],
				&(buf[(linebreak) % BUFFER_SIZE]),
				BUFFER_SIZE - ((linebreak) % BUFFER_SIZE));
	else
		ft_memcpy(&(*line)[ft_strlen(*line)], buf, BUFFER_SIZE);
	return;
}

size_t copy_line(size_t pos, size_t linebreak, char *buf, char **line)
//found newline & we're not in the start of buf
{
	if (((pos - 1) / BUFFER_SIZE) == (linebreak / BUFFER_SIZE)) //check if last newline in this buffer
		ft_memcpy(&(*line)[ft_strlen(*line)],
				&(buf[(linebreak) % BUFFER_SIZE]),
				(pos - linebreak));
	else
		ft_memcpy(&(*line)[ft_strlen(*line)], buf, pos % BUFFER_SIZE);
	linebreak = pos + 1;
	return (linebreak);
}

int	get_next_line(int fd, char **line)
{
	size_t pos; //position where we are seeking in fd
	static size_t linebreak; //previous line break position + 1
	static char buf[BUFFER_SIZE + 1];
	ssize_t ret;

	*line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!linebreak)
		ft_bzero(buf, BUFFER_SIZE);
	pos = linebreak;
	if ((pos % BUFFER_SIZE) == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		/* ret = get_a_buf(fd, (char **)(&buf)); */
		if ((ret == 0) || (ret == -1))
			return (ret);
		printf("\033[0;31m%2lu:[%s]:%lu\n\033[0m", pos / BUFFER_SIZE, buf, ft_strlen(buf));
	}
	while (1)
	{
		if (pos - linebreak > BUFFER_SIZE)
			*line = ft_reallocarray(*line, sizeof(char), pos + 2 - linebreak);
		if (buf[pos % BUFFER_SIZE] == '\n')
		{
			linebreak = copy_line(pos, linebreak, buf, line);
			if (!buf[(pos % BUFFER_SIZE) + 1]) //if no more lines in buf, reset linebreak
				/* linebreak = BUFFER_SIZE * (pos / BUFFER_SIZE); */
				linebreak = 0;
			return (1);
		}
		else
		{
			pos++;
			if ((pos % BUFFER_SIZE) == 0) //reached end of buffer, no newline
			{
				eob_no_newline(pos, linebreak, buf, line);
				ret = read(fd, buf, BUFFER_SIZE);
				/* get_a_buf(ret, &(buf[0])); */
				if ((ret == 0) || (ret == -1))
					return (ret);
				printf("\033[0;31m%2lu:[%s]:%lu\n\033[0m", pos / BUFFER_SIZE, buf, ft_strlen(buf));

			}
		}
	}

	return (1);
}
