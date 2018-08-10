/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:48:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 18:01:18 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			main(int argc, char **argv)
{
	t_env	env;
	char	**array;
	t_rows	d;
	t_fds	f;
	char	**tab;

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
	//int i = 0;
	//int n = 0;
	/*int j = 0;
	while (env.points && n < 10)
	{
		i = 0;
		while (i < 10)
		{
			printf("%i : %f, %f, %c\n", j, env.points->x, env.points->y, env.points->z);
			env.points = env.points->next;
			i++;
			j++;
		}
	//	printf("\n");
		n++;
	}*/
	tab = make_int_array(env, d);
	/*while (n < d.rows)
	{
		i = 0;
		while (i < d.columns)
		{
			printf("%c ", tab[n][i]);
			i++;
		}
		printf("\n");
		n++;
	}*/
	intersection(&env, tab);
	//calculate(env.points, d, &env);
	mlx_key_hook(env.mlx.win, key_set, env.points);
	mlx_loop(env.mlx.mlx);
	free_t_point(env.points);
	return (0);
}
