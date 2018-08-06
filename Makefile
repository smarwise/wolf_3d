# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarwise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 07:21:35 by smarwise          #+#    #+#              #
#    Updated: 2018/08/06 16:26:01 by smarwise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = gcc -Wall -Wextra -Werror -Wuninitialized

OBJ = obj/keys.o obj/main.o obj/size.o obj/read_from_file.o

$(NAME): $(OBJ)
		make -C libft/
		$(FLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a

all:
	make $(NAME)

$(OBJ): obj/%.o: srcs/%.c
		$(FLAGS) -c srcs/$*.c -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all
