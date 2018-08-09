/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:45:20 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 08:58:51 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			free_t_point(t_points *head)
{
	t_points	*trav;

	trav = head;
	while (trav)
	{
		trav = trav->next;
		free(head);
		head = trav;
	}
}
