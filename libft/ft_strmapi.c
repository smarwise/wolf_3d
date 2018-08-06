/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:42:08 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/11 07:34:02 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	n;
	int				len;

	str = NULL;
	if (s != NULL && f != NULL)
	{
		i = 0;
		n = 0;
		len = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * len + 1);
		if (str == NULL)
			return (NULL);
		while (s[i])
		{
			str[n] = f(i, s[i]);
			n++;
			i++;
		}
		str[n] = '\0';
	}
	return (str);
}
