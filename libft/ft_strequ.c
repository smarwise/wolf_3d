/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 08:54:44 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/09 15:26:24 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strequ(char const *s1, char const *s2)
{
	int					i;
	int					n;
	unsigned char const	*str1;
	unsigned char const	*str2;

	i = 0;
	n = 0;
	str1 = (unsigned char const *)s1;
	str2 = (unsigned char const *)s2;
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (str1[i] && str2[n])
	{
		if (str1[i] != str2[n])
			return (0);
		else
		{
			i++;
			n++;
		}
	}
	return (str1[i] == str2[n] ? 1 : 0);
}
