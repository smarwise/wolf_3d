/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 10:29:36 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/17 12:58:37 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int brk;
	int new;
	int sign;

	new = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	brk = 0;
	while (*str && ft_isdigit(*str))
	{
		new = (new * 10) + (*str++ - '0');
		if (brk >= 18)
			return (sign == -1 ? 0 : -1);
		brk++;
	}
	return (new * sign);
}
