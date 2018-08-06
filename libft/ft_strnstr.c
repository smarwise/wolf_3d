/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:52:39 by smarwise          #+#    #+#             */
/*   Updated: 2018/05/29 12:54:51 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_match_find(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i] || i >= len)
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	size;
	size_t	n;
	size_t	count;

	n = 0;
	i = 0;
	size = len;
	count = 0;
	if (len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && count < len)
	{
		if (ft_match_find(needle, &haystack[i], len - i))
			return ((char *)haystack + i);
		i++;
		count++;
		size--;
	}
	return (NULL);
}
