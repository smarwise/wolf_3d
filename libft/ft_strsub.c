/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:51:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/11 07:20:14 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;
	size_t	n;

	str = NULL;
	if (s != NULL)
	{
		i = 0;
		n = start;
		slen = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * len + 1);
		if (str == NULL)
			return (NULL);
		if (start + len > slen)
			return (NULL);
		while (n < len + start)
		{
			str[i] = s[n];
			i++;
			n++;
		}
		str[i] = '\0';
	}
	return ((char *)str);
}
