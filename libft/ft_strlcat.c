/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:49:11 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/08 14:36:45 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	slen;
	size_t	dlen;
	size_t	count;

	count = 0;
	n = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = ft_strlen((const char *)dst);
	if (i + 1 > dstsize)
		return (dstsize + slen);
	while (src[n] && n < dstsize - i - 1)
	{
		dst[i + n] = src[n];
		n++;
	}
	dst[i + n] = '\0';
	return (slen + dlen);
}
