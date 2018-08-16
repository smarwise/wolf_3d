/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:48:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/16 08:58:15 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			click_set(int b, t_env *v)
{
	(void)b;
	(void)v;
	exit(0);
}

int			main(int argc, char **argv)
{
	t_env	env;
	char	**array;
	t_rows	d;
	t_fds	f;
	char	**tab;
	t_player *p;
	t_struct *t;

	p = (t_player *)malloc(sizeof(t_player));
	t = (t_struct *)malloc(sizeof(t_struct));
	env.mlx.mlx = mlx_init();
	env.mlx.win = mlx_new_window(env.mlx.mlx, screenwidth, screenheight, "wolf_3d");
	f.fd = open(argv[1], O_RDONLY);
	f.fd1 = open(argv[1], O_RDONLY);
	d = dimensions(f.fd, argc);
	check_errors(d.rows, d.columns, f.fd, argc);
	close(f.fd);
	array = read_from_file(f.fd1, d);
	close(f.fd1);
	env.points = coordinates(array, d, argv);
	free_2d_array((void**)array);
	tab = make_array(env, d);
	p = init(p);
	t = cast_rays(&env, tab, p, t);
	mlx_hook(env.mlx.win, 2, 0, move, (void *)t);
	mlx_hook(env.mlx.win, 17, 0, click_set, p);
	mlx_key_hook(env.mlx.win, key_set, env.points);
	mlx_loop(env.mlx.mlx);
	free_t_point(env.points);
	return (0);
}
