/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 09:37:12 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/11 08:24:42 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_allocate(char const *s1, char *newstring, int indexnew)
{
	while (*s1)
	{
		newstring[indexnew] = *s1;
		s1++;
		indexnew++;
	}
	return (newstring);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstring;
	int			i;
	int			n;
	int			indexnew;

	newstring = NULL;
	indexnew = 0;
	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strlen(s1);
		n = ft_strlen(s2);
		newstring = (char *)malloc(sizeof(char) * (i + n + 1));
		if (newstring == NULL)
			return (NULL);
		newstring = ft_allocate(s1, newstring, indexnew);
		indexnew = indexnew + i;
		newstring = ft_allocate(s2, newstring, indexnew);
		indexnew = indexnew + n;
		newstring[indexnew] = '\0';
	}
	return (newstring);
}
