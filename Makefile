# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunderle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 20:03:30 by sunderle          #+#    #+#              #
#    Updated: 2021/01/06 05:41:01 by sunderle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnltest

# CC = gcc
CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
	  # main.c\
	  # get_next_line.c\
	  # get_next_line.h\
	  # get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

HEADER = get_next_line.h

INCLUDES = ./

all: $(NAME)

$(OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

GREPHL = grep  --color=always -e "^" -e "Error"


norm:
	@norminette_linux -R CheckForbiddenSourceHeader $(filter-out main.c, $(SRC)) | $(GREPHL)
	@norminette_linux -R CheckForbiddenSourceHeader $(HEADER) | $(GREPHL)

.PHONY: clean fclean all re
