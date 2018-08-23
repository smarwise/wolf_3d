/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 08:36:21 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/23 09:57:55 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_player	*init(t_player *p)
{
	p->posx = 12;
	p->posy = 12;
	p->diry = 0;
	p->dirx = -1;
	p->h = SCREENHEIGHT;
	p->w = SCREENWIDTH;
	p->planex = 0;
	p->planey = 0.66;
	p->rotspeed = 0.05;
	p->movespeed = 0.05;
	return (p);
}

t_player	*my_init(t_player *p, int **tab)
{
	(void)tab;
	p->mapy = (int)p->posy;
	p->mapx = (int)p->posx;
	p->camerax = 2 * p->x / (double)p->w - 1;
	p->raydirx = p->dirx + p->planex * p->camerax;
	p->raydiry = p->diry + p->planey * p->camerax;
	p->deltadistx = sqrt(1 + (p->raydiry * p->raydiry) /
			(p->raydirx * p->raydirx));
	p->deltadisty = sqrt(1 + (p->raydirx * p->raydirx) /
			(p->raydiry * p->raydiry));
	p->side = -1;
	p->hit = 0;
	p = find_intersection(p, tab);
	if (p->side == 0)
		p->perpwalldist = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->raydirx;
	else
		p->perpwalldist = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->raydiry;
	p->lineheight = (int)(p->h / p->perpwalldist);
	p->drawstart = -p->lineheight + p->h / 2.5;
	return (p);
}
