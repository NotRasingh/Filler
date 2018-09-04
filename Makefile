# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 10:45:54 by rasingh           #+#    #+#              #
#    Updated: 2018/08/22 11:35:28 by rasingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
SOURCES = srcs/*.c
INCLUDES = includes/gnl/get_next_line.c includes/libft/libft.a

$(NAME): 
	@make -C includes/libft
	@gcc -Wall -Werror -Wextra $(SOURCES) $(INCLUDES) -o filler
	@echo "\033[1;32;4mCOMPILING SUCCESSFUL"

all: $(NAME)

clean:
	@rm -f includes/libft/libft.a includes/libft/*.o
	@rm -f $(NAME)
	@echo "\033[1;34;4mCLEAN SUCCESSFUL\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all	
