/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:29:34 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/23 10:07:14 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_coordinates		find_color(t_coordinates c, t_player p)
{
	if (p.side == 1)
	{
		if ((p.stepx == -1 && p.stepy == -1) || (p.stepx == 1 && p.stepy == -1))
			c.color = 0x1c85db;
		else if ((p.stepx == -1 && p.stepy == 1)
				|| (p.stepx == 1 && p.stepy == 1))
			c.color = 0x78db1c;
		else
			c.color = 0xFF0000;
	}
	else if (p.side == 0)
	{
		if (p.stepx == -1 && p.stepy == 1)
			c.color = 0xFFF200;
		if (p.stepx == -1 && p.stepx == -1)
			c.color = 0xFFF200;
		else
			c.color = 0xb8e9f2;
	}
	else
		c.color = 0xFFFF80;
	return (c);
}

void				find_steps(t_player *p)
{
	if (p->raydirx < 0)
	{
		p->stepx = -1;
		p->sidedistx = (p->posx - p->mapx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->sidedistx = (p->mapx + 1 - p->posx) * p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		p->stepy = -1;
		p->sidedisty = (p->posy - p->mapy) * p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->sidedisty = (p->mapy + 1 - p->posy) * p->deltadisty;
	}
}

t_player			*find_intersection(t_player *p, int **tab)
{
	find_steps(p);
	while (p->hit == 0)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			p->mapx += p->stepx;
			p->side = 0;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			p->mapy += p->stepy;
			p->side = 1;
		}
		if (tab[p->mapx][p->mapy] > 0)
			p->hit = 1;
	}
	return (p);
}

void				draw_wall_ceiling(t_player *p, t_coordinates c,
		int **tab, t_key *e)
{
	(void)tab;
	if (tab[p->mapx][p->mapy] == 1)
	{
		c.color = 0x009090;
		c.x0 = p->x;
		c.y0 = 0;
		draw(c, p->x, p->drawstart, *e);
		c = find_color(c, *p);
		c.x0 = p->x;
		c.y0 = p->drawstart;
		draw(c, p->x, p->drawend, *e);
		c.color = 0x006080;
		c.x0 = p->x;
		c.y0 = p->drawend;
		draw(c, p->x, SCREENHEIGHT, *e);
	}
}

t_struct			*cast_rays(t_key *e, int **tab, t_player *p, t_struct *t)
{
	t_coordinates	c;

	p->x = -1;
	new_image(e);
	while (++p->x < SCREENWIDTH)
	{
		p = my_init(p, tab);
		if (p->drawstart < 0)
			p->drawstart = 0;
		p->drawend = (p->lineheight + p->h / 2.5);
		if (p->drawend >= p->h)
			p->drawend = (p->h - 1);
		c.x0 = 0;
		draw_wall_ceiling(p, c, tab, e);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	t->tab = tab;
	return (t);
}
