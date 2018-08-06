/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:11:32 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/09 08:48:48 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i])
		i++;
	while (s2[count] && count < n)
	{
		s1[i + count] = s2[count];
		count++;
	}
	s1[i + count] = '\0';
	return (s1);
}
