/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 12:56:17 by smarwise          #+#    #+#             */
/*   Updated: 2018/07/30 18:52:35 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_count_words(char *str)
{
	int					i;
	int					count;

	i = 0;
	count = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if (str[i] == '\0')
		return (count);
	while (str[i])
	{
		if (str[i] == '\0')
			return (count);
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
		count++;
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	}
	return (count);
}
