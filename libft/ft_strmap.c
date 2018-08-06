/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 08:30:30 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/11 07:30:54 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		n;
	int		count;
	char	*str;

	str = NULL;
	if (s != NULL && f != NULL)
	{
		i = 0;
		count = 0;
		n = ft_strlen(s);
		n++;
		str = (char *)malloc(sizeof(char) * n);
		if (str == NULL)
			return (NULL);
		while (s[i])
		{
			str[count] = f(s[i]);
			i++;
			count++;
		}
		str[count] = '\0';
	}
	return (str);
}
