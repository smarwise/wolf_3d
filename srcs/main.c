/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 07:07:43 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/06 16:27:12 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf_3d.h"
#define mapWidth 24
#define mapHeight 24

int			click_set(int b, t_env *v)
{
	(void)b;
	(void)v;
	exit(0);
}

int			main(int argc, char **argv)
{
	t_env	e;
	int		fd;
	t_rows	s;
	t_variables v;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	s = size(fd);
	printf("%i, %i\n", s.rows, s.columns);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	v.array = read_from_file(fd);
	e.mlx = mlx_init();
	e.window = mlx_new_window(e.mlx, 1500, 900, "wolf_3d");
	mlx_key_hook(e.window, keys, e.mlx);
	mlx_loop(e.mlx);
}
