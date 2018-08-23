/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:42:31 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/23 10:00:33 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			**make_array(char **tab, t_rows d)
{
	int		**array;
	char	**temp;
	int		i;
	int		n;

	n = 0;
	array = (int **)malloc(sizeof(int *) * (d.rows + 1));
	while (n < d.rows)
	{
		i = 0;
		array[n] = (int *)malloc(sizeof(int) * (d.columns + 1));
		temp = ft_strsplit(tab[n], ' ');
		while (i < d.columns)
		{
			array[n][i] = ft_atoi(temp[i]);
			if (array[n][i] != 0 && array[n][i] != 1)
				error_message();
			i++;
		}
		array[n][i] = '\0';
		free_2d_array((void**)temp);
		n++;
	}
	array[n] = NULL;
	return (array);
}
