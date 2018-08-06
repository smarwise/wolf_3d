/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:36:30 by smarwise          #+#    #+#             */
/*   Updated: 2018/06/15 13:23:26 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int i;
	int n;

	i = 0;
	if (!s)
		return ;
	n = ft_strlen(s);
	write(fd, &s[i++], n);
	write(fd, "\n", 1);
}
