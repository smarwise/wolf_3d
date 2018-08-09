/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:51:11 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 15:40:15 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
#include <stdbool.h>
# define screenheight 800
# define screenwidth 800

typedef struct					s_key
{
	void						*mlx;
	void						*win;
}								t_key;

typedef struct					s_points
{
	double						x;
	double						y;
	char						z;
	int							c;
	int							scale;
	int							shift;
	struct s_points				*next;
	struct s_points				*right;
	struct s_points				*up;
}								t_points;

void							free_t_point(t_points *head);

typedef struct					s_player
{
	int						posx;
	int						posy;
	float						angle;
	float						disttowall;
	float						FOV;
	float						rayangle;
	float						eyex;
	float						eyey;
	char						wall;

}								t_player;

typedef struct					s_axis
{
	int							x;
	int							y;
	int							rows;
	int							columns;
	float						start;
	float						end;
	int							n;
	int							i;
	int							r;
	int							c;
	bool						hitwall;
	char						**array;
}								t_axis;

typedef struct					s_env
{
	t_key						mlx;
	t_points					*points;
}								t_env;

typedef struct					s_draw
{
	double						dx;
	double						dy;
	double						x;
	double						y;
	double						steps;
	double						xinc;
	double						yinc;
}								t_draw;

typedef struct					s_coordinates
{
	int							x0;
	int							y0;
	int							color;
}								t_coordinates;

typedef struct					s_rows
{
	int							rows;
	int							columns;
}								t_rows;

typedef struct					s_fds
{
	int							fd;
	int							fd1;
}								t_fds;

char							**read_from_file(int fd, t_rows d);
int								print_map(t_env *env);
t_points						*get_height(char **str, t_rows d,
								t_points *lst, t_axis c);
char							**read_file(int fd, t_rows d);
int								key_set(int keycode);
t_points						*coordinates(char **str, t_rows d, char **argv);
void							draw(t_coordinates c, int x1,
								int y1, t_key mlx);
t_rows							dimensions(int fd, int argc);
void							check_errors(int rows,
		int columns, int fd, int argc);
double							ft_abs(double n);
char							*create_file_content(char *curr,
								char *to_add, size_t rsize);
void							calculate(t_points *t, t_rows d, t_env *env);
void							check(t_env *e, char **tab);
char							**make_int_array(t_env env, t_rows d);
#endif
