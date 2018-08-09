/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:13:43 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 09:10:22 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_points		*get_link(int link, t_points *head)
{
	while (--link)
		head = head->next;
	if (head)
		return (head);
	else
		return (NULL);
}

t_points		*allocate(t_axis cnt,
		t_points *lst, t_points *head)
{
	while (cnt.y < cnt.rows)
	{
		cnt.x = 0;
		while (cnt.x < cnt.columns)
		{
			lst->x = cnt.x; //- cnt.columns / 2;
			lst->y = cnt.y; //- cnt.rows / 2;
			cnt.x++;
			if (cnt.x < cnt.columns)
				lst->right = lst->next;
			else
				lst->right = NULL;
			if (cnt.y)
				lst->up = get_link((cnt.y - 1) * cnt.columns + cnt.x, head);
			else
				lst->up = NULL;
			lst->c = lst->z == '#' ? 0xeff628 : 0x28acf6;
			lst = lst->next;
		}
		cnt.y++;
	}
	return (head);
}

t_points		*coordinates(char **str, t_rows d, char **argv)
{
	t_axis		cnt;
	t_points	*lst;
	t_points	*head;
	t_axis		c;

	head = NULL;
	cnt.y = 0;
	c.y = 0;
	cnt.rows = d.rows;
	cnt.columns = d.columns;
	c.columns = d.columns;
	head = (t_points *)ft_memalloc(sizeof(t_points));
	if (head == NULL)
		return (NULL);
	lst = head;
	lst = get_height(str, d, lst, c);
	lst = head;
	while (lst)
	{
		lst->scale = cnt.rows >= 50 || cnt.columns >= 50 ? 20 : 20;
		lst->shift = cnt.rows >= 50 || cnt.columns >= 50 ? 200 : 200;
		lst = lst->next;
	}
	lst = head;
	(void)argv;
	return (allocate(cnt, lst, head));
}
