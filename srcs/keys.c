/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:05:10 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/17 07:44:19 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				moveupdown(int keycode, t_struct *t, t_player *p)
{
	if (keycode == 13)
	{
		if (t->tab[(int)(p->posX + p->dirX *
					p->moveSpeed)][(int)(p->posY)] == '.')
			p->posX += p->dirX * p->moveSpeed;
		if (t->tab[(int)(p->posX)][(int)(p->posY + p->dirY
					* p->moveSpeed)] == '.')
			p->posY += p->dirY * p->moveSpeed;
	}
	if (keycode == 1)
	{
		if (t->tab[(int)(p->posX - p->dirX *
					p->moveSpeed)][(int)(p->posY)] == '.')
			p->posX -= p->dirX * p->moveSpeed;
		if (t->tab[(int)(p->posX)][(int)(p->posY - p->dirY
					* p->moveSpeed)] == '.')
			p->posY -= p->dirY * p->moveSpeed;
	}
	mlx_clear_window(t->e->mlx, t->e->win);
	mlx_destroy_image(t->e->mlx, t->e->image);
	cast_rays(t->e, t->tab, p, t);
	return (0);
}

void			real_move(int keycode, t_struct *t, t_player p)
{
	double		olddirx;
	double		oldplanex;

	oldplanex = p.planeX;
	if (keycode == 13 || keycode == 1)
		moveupdown(keycode, t, &p);
	if (keycode == 2)
	{
		olddirx = p.dirX;
		p.dirX = p.dirX * cos(-p.rotSpeed) - p.dirY * sin(-p.rotSpeed);
		p.dirY = olddirx * sin(-p.rotSpeed) + p.dirY * cos(-p.rotSpeed);
		p.planeX = p.planeX * cos(-p.rotSpeed) - p.planeY * sin(-p.rotSpeed);
		p.planeY = oldplanex * sin(-p.rotSpeed) + p.planeY * cos(-p.rotSpeed);
	}
	if (keycode == 0)
	{
		olddirx = p.dirX;
		p.dirX = p.dirX * cos(p.rotSpeed) - p.dirY * sin(p.rotSpeed);
		p.dirY = olddirx * sin(p.rotSpeed) + p.dirY * cos(p.rotSpeed);
		p.planeX = p.planeX * cos(p.rotSpeed) - p.planeY * sin(p.rotSpeed);
		p.planeY = oldplanex * sin(p.rotSpeed) + p.planeY * cos(p.rotSpeed);
	}
	mlx_clear_window(t->e->mlx, t->e->win);
	mlx_destroy_image(t->e->mlx, t->e->image);
	cast_rays(t->e, t->tab, &p, t);
}

int				move(int keycode, t_struct *t)
{
	if (keycode == 53)
		exit(0);
	real_move(keycode, t, t->p);
	return (0);
}
