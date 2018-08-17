/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:53:19 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 08:58:02 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		check_errors(int rows, int columns, int fd, int argc)
{
	if (rows == 0 || columns == 0 || fd < 0)
	{
		ft_putendl("Invalid Map");
		exit(0);
	}
	if (argc > 4)
	{
		ft_putendl("Too many arguments");
		exit(0);
	}
	if (fd < 0)
	{
		ft_putendl("Invalid Map");
		exit(0);
	}
}
