/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:42:31 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/18 00:22:56 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char		**make_array(char **tab, t_rows d)
{
	char	**array;
	char	**temp;
	int		i;
	int		n;

	n = 0;
	array = (char **)malloc(sizeof(char *) * (d.rows + 1));
	while (n < d.rows)
	{
		i = 0;
		array[n] = (char *)malloc(sizeof(char) * (d.columns + 1));
		temp = ft_strsplit(tab[n], ' ');
		while (i < d.columns)
		{
			array[n][i] = atoc(temp[i]);
			i++;
		}
		array[n][i] = '\0';
		if (array[n][0] != '.' && array[n][0] != '#')
			error_message();
		free_2d_array((void**)temp);
		n++;
	}
	array[n] = NULL;
	return (array);
}
