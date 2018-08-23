/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:48:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/23 10:01:54 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				click_set(int b, t_player *v)
{
	(void)b;
	(void)v;
	sleep(60);
	exit(0);
}

void			mlx_do(t_key *mlx, t_struct *t, t_axis *ar)
{
	t->e = mlx;
	free_2d_array((void**)ar->array);
	t = cast_rays(mlx, ar->tab, t->p, t);
	mlx_hook(mlx->win, 2, 0, move, (void *)t);
	mlx_hook(mlx->win, 17, 0, click_set, t->p);
	mlx_loop(mlx->mlx);
	free((void *)t->p);
	free((void *)t);
}

int				main(int argc, char **argv)
{
	t_key		mlx;
	t_axis		ar;
	t_rows		d;
	t_fds		f;
	t_struct	*t;

	f.fd2 = open(argv[1], O_DIRECTORY);
	if (f.fd2 >= 0)
		error_message();
	t = (t_struct *)malloc(sizeof(t_struct));
	t->p = (t_player *)malloc(sizeof(t_player));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SCREENWIDTH, SCREENHEIGHT, "wolf_3d");
	f.fd = open(argv[1], O_RDONLY);
	f.fd1 = open(argv[1], O_RDONLY);
	d = dimensions(f.fd, argc);
	t->d = d;
	check_errors(d.rows, d.columns, f.fd, argc);
	close(f.fd);
	ar.array = read_from_file(f.fd1, d);
	close(f.fd1);
	ar.tab = make_array(ar.array, d);
	t->p = init(t->p);
	mlx_do(&mlx, t, &ar);
	return (0);
}
