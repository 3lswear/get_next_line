/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 05:37:12 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/07 05:08:15 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static size_t pos;
	size_t read_pos;
	char c;
	char *buf;
	ssize_t ret;

	buf = (char *)malloc(BUFFER_SIZE);

	pos = 0;
	while ((ret = read(fd, buf, 1)) && (buf[0] != '\n'))
	{
		pos++;
	}
	line = (char **)malloc(sizeof(char *));
	line[0] = (char *)ft_calloc(sizeof(char), pos + 1);
	read_pos = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		ft_memcpy(&(line[0][read_pos]), buf, ret);
		read_pos += ret;
	}

	return (1);
}
