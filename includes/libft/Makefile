# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 08:38:55 by rasingh           #+#    #+#              #
#    Updated: 2018/06/22 13:18:06 by rasingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
cc = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -c
FUNCS = ft_atoi \
ft_bzero \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_itoa \
ft_memalloc \
ft_memccpy \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memdel \
ft_memmove \
ft_memset \
ft_putchar \
ft_putchar_fd \
ft_putendl \
ft_putnbr \
ft_putstr \
ft_putstr_fd \
ft_strcat \
ft_strchr \
ft_strclr \
ft_strcmp \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strequ \
ft_striter \
ft_striteri \
ft_strjoin \
ft_strlcat \
ft_strlen \
ft_strmap \
ft_strmapi \
ft_strncat \
ft_strncmp \
ft_strncpy \
ft_strnequ \
ft_strnew \
ft_strnstr \
ft_strrchr \
ft_strsplit \
ft_strstr \
ft_strsub \
ft_strtrim \
ft_tolower \
ft_toupper \
ft_putendl_fd \
ft_putnbr_fd \
ft_intlen \

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean 
	/bin/rm -f $(NAME)

re: fclean all
