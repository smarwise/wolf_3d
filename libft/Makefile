# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarwise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 08:14:41 by smarwise          #+#    #+#              #
#    Updated: 2018/07/28 12:58:36 by smarwise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_count_words.c arraypush.c arraylen.c free_2d_array.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_isalpha.c ft_isalnum.c ft_strcpy.c ft_strcmp.c ft_tolower.c ft_toupper.c ft_strdup.c ft_putchar.c ft_putstr.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_strlen.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strncmp.c ft_memccpy.c ft_bzero.c ft_memset.c ft_atoi.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_strmap.c ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strtrim.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strsub.c ft_striteri.c ft_strsplit.c ft_strmapi.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isupper.c ft_islower.c get_next_line.c

FLAGS = -c -Wall -Wextra -Werror -I.

OFILES = ft_count_words.o arraypush.o arraylen.o free_2d_array.o ft_isdigit.o ft_isascii.o ft_isprint.o ft_isalpha.o ft_isalnum.o ft_strcpy.o ft_strcmp.o ft_tolower.o ft_toupper.o ft_strdup.o ft_putchar.o ft_putstr.o ft_memset.o ft_bzero.o ft_memccpy.o ft_strncmp.o ft_strnstr.o ft_strstr.o ft_strrchr.o ft_strchr.o ft_strlcat.o ft_strncat.o ft_strcat.o ft_strncpy.o ft_strlen.o ft_memchr.o ft_memmove.o ft_memcpy.o ft_atoi.o ft_memcmp.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_strmap.o ft_strequ.o ft_strnequ.o ft_strjoin.o ft_strtrim.o ft_putendl.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_strsub.o ft_striteri.o ft_strsplit.o ft_strmapi.o ft_itoa.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_isupper.o ft_islower.o get_next_line.o

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

all: $(NAME)

$(OFILES): %.o: %.c libft.h
	gcc -c $*.c -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
