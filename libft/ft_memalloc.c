/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:38:28 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/09 08:31:06 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*freshmem;

	freshmem = (void *)malloc(sizeof(void) * size);
	if (freshmem == NULL)
		return (NULL);
	ft_bzero(freshmem, size);
	return (freshmem);
}
