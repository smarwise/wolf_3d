# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarwise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 07:21:35 by smarwise          #+#    #+#              #
#    Updated: 2018/08/23 09:56:05 by smarwise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = gcc -Wall -Wextra -Werror -Wuninitialized

OBJ = obj/error.o obj/init.o obj/atoc.o\
	  obj/dimensions.o  obj/main.o obj/drawline.o \
	  obj/read_from_file.o obj/int_array.o obj/raycast.o obj/keys.o\

$(NAME): $(OBJ)
		make -C libft/
		$(FLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a

all:
	make $(NAME)

$(OBJ): obj/%.o: srcs/%.c
		$(FLAGS) -c srcs/$*.c -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)
	
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	
re: fclean all
