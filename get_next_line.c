/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/12 18:04:07 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	size_t pos; //position where we are seeking in fd
	static size_t linebreak; //previous line break position + 1
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
		pos = linebreak;
	while (1)
	{
		if ((pos % BUFFER_SIZE) == 0)
		//if reached end of buffer, get a new one
		{
			if (!(ret = read(fd, buf, BUFFER_SIZE)))
				break;
		}
		printf("\033[0;31m%2lu:[%s]\n\033[0m", pos / BUFFER_SIZE, buf);
		while (buf[pos % BUFFER_SIZE] != '\n')
		{
			*line = ft_reallocarray(*line, sizeof(char), pos + 1 - linebreak);
			pos++;
			if ((pos % BUFFER_SIZE) == 0)
				break;
		}
		if ((pos % BUFFER_SIZE) && (buf[pos % BUFFER_SIZE] == '\n')) //found newline
		{
			if (((pos - 1) / BUFFER_SIZE) == (linebreak / BUFFER_SIZE)) //check if last newline in this buffer
				ft_memcpy(&(*line)[ft_strlen(*line)],
						&(buf[(linebreak) % BUFFER_SIZE]),
						(pos - linebreak));
			else
				ft_memcpy(&(*line)[ft_strlen(*line)], buf, pos % BUFFER_SIZE);
			linebreak = pos + 1;
			break;
		}
		else //reached end of the buffer, no newline
			if (((pos - 1) / BUFFER_SIZE) == (linebreak / BUFFER_SIZE)) //check if last newline in this buffer
				ft_memcpy(&(*line)[ft_strlen(*line)],
						&(buf[(linebreak) % BUFFER_SIZE]),
						BUFFER_SIZE - ((linebreak) % BUFFER_SIZE));
			else
				ft_memcpy(&(*line)[ft_strlen(*line)], buf, BUFFER_SIZE);

	}

	return (1);
}
