/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:29:34 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/16 18:26:03 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_coordinates		find_color(t_coordinates c, t_player p)
{
	if (p.side == 1)
	{
		if ((p.stepX == -1 && p.stepY == -1) || (p.stepX == 1 && p.stepY == -1))
			c.color = 0xFF0000 / 4;
		else if ((p.stepX == -1 && p.stepY == 1) || (p.stepX == 1 && p.stepY == 1))
			c.color = 0xFF80FF;
		else
			c.color = 0xFF0000 / 4;
	}
	if (p.side == 0)
	{
		if (p.stepX == -1 && p.stepY == 1)
			c.color = 0xFFF000;
		if (p.stepX == -1 && p.stepX == -1)
			c.color = 0xFFF200;
		else
			c.color = 0x00FF00;
	}
	if (p.x % 20 == 0 || p.x % 20 == 1 || p.x % 20 == 2)
		c.color = 0x0000F5;
	/*int y;
	y = drawStart;
	while (y <= p.drawEnd)
	{
		y = y + 20;
		c.color = 0x0000F5;
		c.x0 = p.x;
		c.y0 = 0;
		draw(c, screenwidth, p.drawStart, c);
	}*/
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
	int k;
	k = 0;
	new_image(&e->mlx);
	while (p->x < screenwidth && tab[p->posY][p->posX] != '#')
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
		p->drawStart = -p->lineHeight + p->h / 2.5;
		if (p->drawStart < 0)
			p->drawStart = 0;
		p->drawEnd = (p->lineHeight + p->h / 2.5) + 50;
		if (p->drawEnd >= p->h)
			p->drawEnd = (p->h - 1) + 50;
		if (k == 0)
		{
			float y;
    		y = p->drawStart;
    		while (y <= p->drawEnd)
    		{
       			 y = y + 20;
    		    c.color = 0xFF0000;
     			c.x0 = 0;
       			c.y0 = (int)y;
        		horizontal(c, screenwidth, c.y0, e->mlx);
				printf("x: %i   %i %i\n", p->x, (int)y, screenwidth);
			}
			k++;
		}
		if (tab[p->mapY][p->mapX] == '#')
		{
			c.color = 0x009090;
			c.x0 = p->x;
			c.y0 = 0;
			draw(c, p->x, p->drawStart, e->mlx);
			c = find_color(c, *p);
			c.x0 = p->x;
			c.y0 = p->drawStart;
			draw(c, p->x, p->drawEnd, e->mlx);
			c.color = 0x006080;
			c.x0 = p->x;
			c.y0 = p->drawEnd;
			draw(c, p->x, screenheight, e->mlx);
		}
		p->x++;
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.image, 0, 0);
	t->p = *p;
	t->c = c;
	t->e = *e;
	t->tab = tab;
	return (t);
}
