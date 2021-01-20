/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunderle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:55:03 by sunderle          #+#    #+#             */
/*   Updated: 2021/01/21 00:53:08 by sunderle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
/* #  define BUFFER_SIZE 32 */
/* #  define BUFFER_SIZE 99999 */
/* #  define BUFFER_SIZE 10000000 */ 
# endif

# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
/* # include <sys/types.h> */
/* # include <sys/stat.h> */

int get_next_line(int fd, char **line);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
void *ft_reallocarray(void *ptr, size_t nmemb, size_t size);
char	*ft_strchr_bd(const char *s, int c, int dir);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
