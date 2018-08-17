# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 10:45:54 by rasingh           #+#    #+#              #
#    Updated: 2018/08/17 11:17:15 by rasingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
SOURCES = srcs/*.c
INCLUDES = includes/gnl/get_next_line.c includes/libft/*.c

$(NAME): 
	gcc -Wall -Werror -Wextra $(SOURCES) $(INCLUDES)

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all	
