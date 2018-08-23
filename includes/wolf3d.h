/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:51:11 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/23 14:35:12 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# define SCREENHEIGHT 500
# define SCREENWIDTH 650

typedef struct					s_key
{
	void						*mlx;
	void						*win;
	void						*image;
	void						*data;
	int							bpp;
	int							sizeline;
	int							endian;
}								t_key;

typedef struct					s_player
{
	double						posx;
	double						posy;
	float						fov;
	double						camerax;
	double						raydirx;
	double						raydiry;
	int							mapx;
	int							mapy;
	double						sidedistx;
	double						sidedisty;
	double						deltadistx;
	double						deltadisty;
	double						perpwalldist;
	int							stepx;
	int							stepy;
	int							hit;
	int							side;
	double						dirx;
	double						diry;
	double						planex;
	double						planey;
	int							x0;
	int							y0;
	int							x;
	int							w;
	int							h;
	double						lineheight;
	int							drawstart;
	int							drawend;
	float						rotspeed;
	double						movespeed;
	double						olddirx;
	double						oldplanex;
	double						raydist;

}								t_player;

typedef struct					s_axis
{
	int							**tab;
	char						**array;
}								t_axis;

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
	int							fd2;
}								t_fds;

typedef struct					s_var
{
	double						posx;
	double						posy;
	double						diry;
	double						dirx;
	double						movespeed;
	double						olddirx;
	double						olddiry;
	double						rotspeed;
	double						planex;
	double						planey;
	double						oldplanex;
	double						oldplaney;
}								t_var;

typedef struct					s_struct
{
	t_player					*p;
	t_coordinates				c;
	t_key						*e;
	t_rows						d;
	int							**tab;
}								t_struct;

char							**read_from_file(int fd, t_rows d);
char							**read_file(int fd, t_rows d);
int								key_set(int keycode);
void							draw(t_coordinates c, int x1,
								int y1, t_key mlx);
t_rows							dimensions(int fd, int argc);
void							check_errors(int rows,
								int columns, int fd, int argc);
double							ft_abs(double n);
char							*create_file_content(char *curr,
								char *to_add, size_t rsize);
int								**make_array(char **tab, t_rows d);
t_struct						*cast_rays(t_key *e, int **tab,
								t_player *p, t_struct *t);
int								move(int keycode, t_struct *t);
t_player						*init(t_player *p);
void							new_image(t_key *m);
t_player						*my_init(t_player *p, int **tab);
t_player						*find_intersection(t_player *p, int **tab);
char							atoc(char *str);
void							error_message(void);
int								key_move(int keycode, t_struct *t);
int								key_hook(int keycode, t_struct *t);
int								key_press(int keycode, t_struct *t);

#endif
