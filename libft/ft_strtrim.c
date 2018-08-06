/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:21:54 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/08 15:32:15 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_allocate(char *str, const char *s, size_t i, size_t n)
{
	size_t			index;

	index = 0;
	while (s[i] && i <= n)
	{
		str[index] = s[i];
		i++;
		index++;
	}
	str[index] = '\0';
	return (str);
}

char				*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			n;
	size_t			index;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	n--;
	index = 0;
	while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
		n--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(1));
	if ((str = (char *)malloc(sizeof(char) * (n - i + 2))) == NULL)
		return (NULL);
	return (ft_allocate(str, s, i, n));
}
