/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 06:54:00 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 09:06:23 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_points		*conclude(t_points *lst, char **c_array)
{
	lst->next = NULL;
	free_2d_array((void**)c_array);
	return (lst);
}

void			map_error(void)
{
	ft_putendl("Map reading failed");
	exit(0);
}

t_points		*get_height(char **str, t_rows d, t_points *lst, t_axis c)
{
	while (d.rows > 0)
	{
		c.x = 0;
		c.columns = d.columns;
		c.array = ft_strsplit(str[c.y], ' ');
		while (c.columns > 0)
		{
			//lst->z = ft_atoi(c.array[c.x]);
			lst->z = *c.array[c.x];
			if (!(d.rows == 1 && c.columns == 1))
				lst->next = malloc(sizeof(t_points));
			else
				conclude(lst, c.array);
			if (lst->next == NULL)
				return (NULL);
			lst = lst->next;
			lst->next = NULL;
			c.x++;
			c.columns--;
		}
		free_2d_array((void**)c.array);
		d.rows--;
		c.y++;
	}
	return (lst);
}
