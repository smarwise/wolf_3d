/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraypush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:04:21 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/30 18:53:00 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**arraypush(char **array, char *str)
{
	char	**newarr;
	int		i;

	i = 0;
	if (array == NULL)
	{
		newarr = (char**)malloc(sizeof(char *) * 2);
		newarr[0] = ft_strdup(str);
		newarr[1] = NULL;
	}
	else
	{
		newarr = (char**)malloc(sizeof(char*) * (arraylen(array) + 2));
		while (array[i])
		{
			newarr[i] = ft_strdup(array[i]);
			i++;
		}
		newarr[i] = ft_strdup(str);
		newarr[++i] = NULL;
	}
	return (newarr);
}
