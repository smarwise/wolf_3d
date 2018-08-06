/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:04:51 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/11 08:42:35 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		numlen(int n)
{
	size_t			numblen;

	numblen = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		numblen++;
	}
	return (numblen);
}

static char			*ft_allocate(char *str, int nlen, int n, int sign)
{
	while (nlen >= 0)
	{
		str[nlen] = (n % 10) + '0';
		n = n / 10;
		nlen--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				nlen;
	int				sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nlen = numlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	else if (n > 0)
		sign = 0;
	else
	{
		sign = 1;
		n = n * -1;
	}
	str = (char *)malloc(sizeof(char) * (numlen(n) + 1 + sign));
	if (str == NULL)
		return (NULL);
	nlen = nlen + sign;
	str[nlen] = '\0';
	nlen--;
	return (ft_allocate(str, nlen, n, sign));
}
