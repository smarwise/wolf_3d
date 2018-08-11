# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarwise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 07:21:35 by smarwise          #+#    #+#              #
#    Updated: 2018/08/11 09:47:51 by smarwise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = gcc -Wall -Wextra -Werror -Wuninitialized

OBJ = obj/coordinates.o  obj/error.o obj/key_set.o obj/free_t_points.o\
	  obj/dimensions.o obj/get_height.o obj/main.o obj/drawline.o \
	  obj/read_from_file.o obj/check.o obj/int_array.o\
	  obj/intersection.o\

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
