/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:29:34 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/15 15:30:05 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_coordinates		find_color(t_coordinates c, t_player p)
{
	if (p.rayDirX < 0)
		c.color = 0xFF0000;
	c.color = 0x909090 / 2;
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

t_player			*find_intersection(t_player *p, char **tab, t_coordinates c)
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
		{
			c.x0 = p->x0;
			c.y0 = p->y0;
			c.color = 0xFFFF90;
			p->hit = 1;
		}
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

int 			move(int keycode, t_struct *t)
{
	printf("%i\n", t->p.posX);
	 if (keycode == 13)
    {
	  printf("at least I got here okay🙄\n");
      if(t->tab[(int)(t->p.posX + t->p.dirX * t->p.moveSpeed)][(int)(t->p.posY)] == '.')
	  {
		 t->p.posX += t->p.dirX * t->p.moveSpeed;
		printf("at least I got here okay yall?🙄\n");
	  }
      if(t->tab[(int)(t->p.posX)][(int)(t->p.posY + t->p.dirY * t->p.moveSpeed)] == '.')
		  t->p.posY += t->p.dirY * t->p.moveSpeed;
    }
    if (keycode == 1)
    {
      if (t->tab[(int)(t->p.posX - t->p.dirX * t->p.moveSpeed)][(int)(t->p.posY)] == '.')
		  t->p.posX -= t->p.dirX * t->p.moveSpeed;
      if(t->tab[(int)(t->p.posX)][(int)(t->p.posY - t->p.dirY * t->p.moveSpeed)] == '.')
		  t->p.posY -= t->p.dirY * t->p.moveSpeed;
    }
    if (keycode == 2)
    {
      double oldDirX = t->p.dirX;
      t->p.dirX = t->p.dirX * cos(-t->p.rotSpeed) - t->p.dirY * sin(-t->p.rotSpeed);
      t->p.dirY = oldDirX * sin(-t->p.rotSpeed) + t->p.dirY * cos(-t->p.rotSpeed);
      double oldPlaneX = t->p.planeX;
      t->p.planeX = t->p.planeX * cos(-t->p.rotSpeed) - t->p.planeY * sin(-t->p.rotSpeed);
      t->p.planeY = oldPlaneX * sin(-t->p.rotSpeed) + t->p.planeY * cos(-t->p.rotSpeed);
    }
	printf("at least I got here🙄\n");
    if (keycode == 0)
    {
      double oldDirX = t->p.dirX;
      t->p.dirX = t->p.dirX * cos(t->p.rotSpeed) - t->p.dirY * sin(t->p.rotSpeed);
      t->p.dirY = oldDirX * sin(t->p.rotSpeed) + t->p.dirY * cos(t->p.rotSpeed);
      double oldPlaneX = t->p.planeX;
      t->p.planeX = t->p.planeX * cos(t->p.rotSpeed) - t->p.planeY * sin(t->p.rotSpeed);
      t->p.planeY = oldPlaneX * sin(t->p.rotSpeed) + t->p.planeY * cos(t->p.rotSpeed);
    }
	mlx_clear_window(t->e.mlx.mlx, t->e.mlx.win);
	cast_rays(&t->e, t->tab, &t->p, t);
	return (0);
}

t_struct				*cast_rays(t_env *e, char **tab, t_player *p, t_struct *t)
{
	t_coordinates	c;

	printf("at least I got here🙄\n");
	p->x = 0;
	while (p->x < screenwidth)
	{
		p->mapY = (int)p->posY;
		p->mapX = (int)p->posX;
		p->rayDirY = p->dirY + p->planeY * p->cameraX;
		p->deltaDistY = ft_abs(1 / p->rayDirY);
		p = find_intersection(p, tab, c);
		p->cameraX = 2 * p->x / (double)p->w - 1;
		if (p->side == 0)
			p->perpWallDist = (p->mapX - p->posX + (1 - p->stepX) / 2) / p->rayDirX;
		else
			p->perpWallDist = (p->mapY - p->posY + (1 - p->stepY) / 2) / p->rayDirY;
		p->lineHeight = (int)(p->h / p->perpWallDist);
		p->drawStart = -p->lineHeight / 2 + p->h / 2;
		if (p->drawStart < 0)
			p->drawStart = 0;
		p->drawEnd = p->lineHeight / 2 + p->h / 2;
		if (p->drawEnd >= p->h)
			p->drawEnd = p->h - 1;
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
