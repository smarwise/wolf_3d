/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:42:31 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/17 06:40:14 by smarwise         ###   ########.fr       */
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
	array = (char **)malloc(sizeof(char *) * (d.columns + 1));
	while (n < d.rows)
	{
		i = 0;
		array[n] = (char *)malloc(sizeof(char) * (d.rows + 1));
		temp = ft_strsplit(tab[n], ' ');
		while (i < d.rows)
		{
			array[n][i] = *temp[i];
			i++;
		}
		array[n][i] = '\0';
		n++;
	}
	array[n] = NULL;
	return (array);
}
