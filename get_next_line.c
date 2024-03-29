#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dest;

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
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

int	check_buf(char *substring, char **line, ssize_t *ret, char **tmp)
{
	char	*point;

	*ret = 0;
	if (line)
		*tmp = *line;
	else
		return (-1);
	point = ft_strchr_bd(substring, '\n', 0);
	if (point)
	{
		*point++ = 0;
		*line = ft_strdup(substring);
		if (!line)
			return (-1);
		ft_strlcpy(substring, point, ft_strlen(point) + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(substring);
		if (!line)
			return (-1);
		ft_bzero(substring, ft_strlen(substring) + 1);
		return (0);
	}
}

int	copy_line(char *substring, char **line)
{
	char	*point;
	char	*tmp;
	int		res;

	res = 0;
	point = ft_strchr_bd(substring, '\n', 0);
	if (point)
	{
		*point++ = 0;
		res = 1;
	}
	tmp = *line;
	*line = ft_strjoin(*line, substring);
	if (!line)
		return (-1);
	free(tmp);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	static char	substring[BUFFER_SIZE + 1];
	ssize_t		ret;
	int			res;
	char		*tmp;

	if (fd < 0 || (BUFFER_SIZE <= 0) || (res = check_buf(&(substring
					[ft_strlen(substring) + 1]), line, &ret, &tmp)) == -1)
		return (-1);
	while (res == 0 && (ret = read(fd, substring, BUFFER_SIZE)) > 0)
	{
		substring[ret] = 0;
		if ((res = copy_line(substring, line)) == -1)
			return (-1);
	}
	if (ret == -1)
	{
		free(*line);
		*line = tmp;
		ft_bzero(substring, BUFFER_SIZE);
		return (-1);
	}
	else if (res == 1)
		return (1);
	ft_bzero(substring, BUFFER_SIZE);
	return (0);
}
