/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:29:34 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/16 07:14:02 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_coordinates		find_color(t_coordinates c, t_player p)
{
	if (p.side == 1)
	{
		if (p.stepX == -1 && p.stepY == -1)
			c.color = 0xFF0000;
		else if (p.stepX == -1 && p.stepY == 1)
			c.color = 0xFFFFFF;
		else
			c.color = 0xFF0000;
	}
	if (p.side == 0)
	{
		if (p.stepX == -1 && p.stepY == 1)
			c.color = 0xFFF000;
		if (p.stepX == -1 && p.stepX == -1)
			c.color = 0xFFF000;
		else
			c.color = 0x00FF00;
	}
	if (p.side == 1)
		c.color = c.color / 4;
	return (c);
}

t_player			*find_steps(t_player *p)
{
	if (p->rayDirX < 0)
	{
		p->stepX = -1;
		p->sideDistX = (p->posX - p->mapX) * p->deltaDistX;
	}
	else
	{
		p->stepX = 1;
		p->sideDistX = (p->mapX + 1.0 - p->posX) * p->deltaDistX;
	}
	if (p->rayDirY < 0)
	{
		p->stepY = -1;
		p->sideDistY = (p->posY - p->mapY) * p->deltaDistY;
	}
	else
	{
		p->stepY = 1;
		p->sideDistY = (p->mapY + 1.0 - p->posY) * p->deltaDistY;
	}
	return (p);
}

t_player			*find_intersection(t_player *p, char **tab)
{
	p->hit = 0;
	p = find_steps(p);
	while (p->hit == 0)
	{
		if (p->sideDistX < p->sideDistY)
		{
			p->sideDistX += p->deltaDistX;
			p->mapX += p->stepX;
			p->side = 0;
		}
		else
		{
			p->sideDistY += p->deltaDistY;
			p->mapY += p->stepY;
			p->side = 1;
		}
		if (tab[p->mapY][p->mapX] == '#')
			p->hit = 1;
	}
	return (p);
}

t_player			*init(t_player *p)
{
	p->posX = 22;
	p->posY = 12;
	p->dirY = 0;
	p->dirX = -1;
	p->h = screenheight;
	p->w = screenwidth;
	p->planeX = 0;
	p->planeY = 0.66;
	p->rayDirX = p->dirX + p->planeX * p->cameraX;
	p->deltaDistX = ft_abs(1 / p->rayDirX);
	p->rotSpeed = 6 * M_PI / 180;
	p->moveSpeed = 1;
	return (p);
}

t_struct				*cast_rays(t_env *e, char **tab, t_player *p, t_struct *t)
{
	t_coordinates	c;

	p->x = 0;
	while (p->x < screenwidth)
	{
		p->mapY = (int)p->posY;
		p->mapX = (int)p->posX;
		p->rayDirY = p->dirY + p->planeY * p->cameraX;
		p->deltaDistY = ft_abs(1 / p->rayDirY);
		p = find_intersection(p, tab);
		p->cameraX = 2 * p->x / (double)p->w - 1;
		if (p->side == 0)
			p->perpWallDist = (p->mapX - p->posX + (1 - p->stepX) / 2) / p->rayDirX;
		else
			p->perpWallDist = (p->mapY - p->posY + (1 - p->stepY) / 2) / p->rayDirY;
		p->lineHeight = (int)(p->h / p->perpWallDist);
		p->drawStart = -p->lineHeight / 2 + p->h / 2;
		if (p->drawStart < 0)
			p->drawStart = 0;
		p->drawEnd = (p->lineHeight / 2 + p->h / 2) + 50;
		if (p->drawEnd >= p->h)
			p->drawEnd = (p->h - 1) + 50;
		if (tab[p->mapY][p->mapX] == '#')
		{
			c = find_color(c, *p);
			c.x0 = p->x;
			c.y0 = p->drawStart;
			draw(c, p->x, p->drawEnd, e->mlx);
		}
		p->x++;
	}
	t->p = *p;
	t->c = c;
	t->e = *e;
	t->tab = tab;
	return (t);
}
