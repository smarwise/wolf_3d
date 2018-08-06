/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:33:59 by smarwise          #+#    #+#             */
/*   Updated: 2018/05/28 13:44:26 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_match_find(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			n;

	i = 0;
	n = ft_strlen(needle);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (ft_match_find(needle, &haystack[i]))
			return ((char *)haystack + i);
		else
			i++;
	}
	return (NULL);
}
