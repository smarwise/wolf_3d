/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:05:10 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/17 09:07:42 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				moveupdown(int keycode, t_struct *t, t_player *p)
{
	if (keycode == 13)
	{
		if (t->tab[(int)(p->posx + p->dirx *
					p->movespeed)][(int)(p->posy)] == '.')
			p->posx += p->dirx * p->movespeed;
		if (t->tab[(int)(p->posx)][(int)(p->posy + p->diry
					* p->movespeed)] == '.')
			p->posy += p->diry * p->movespeed;
	}
	if (keycode == 1)
	{
		if (t->tab[(int)(p->posx - p->dirx *
					p->movespeed)][(int)(p->posy)] == '.')
			p->posx -= p->dirx * p->movespeed;
		if (t->tab[(int)(p->posx)][(int)(p->posy - p->diry
					* p->movespeed)] == '.')
			p->posy -= p->diry * p->movespeed;
	}
	mlx_clear_window(t->e->mlx, t->e->win);
	mlx_destroy_image(t->e->mlx, t->e->image);
	cast_rays(t->e, t->tab, p, t);
	return (0);
}

void			real_move(int keycode, t_struct *t, t_player *p)
{
	p->oldplanex = p->planex;
	if (keycode == 13 || keycode == 1)
		moveupdown(keycode, t, p);
	if (keycode == 2)
	{
		p->olddirx = p->dirx;
		p->dirx = p->dirx * cos(-p->rotspeed) - p->diry * sin(-p->rotspeed);
		p->diry = p->olddirx * sin(-p->rotspeed) + p->diry * cos(-p->rotspeed);
		p->planex = p->planex * cos(-p->rotspeed)
			- p->planey * sin(-p->rotspeed);
		p->planey = p->oldplanex * sin(-p->rotspeed)
			+ p->planey * cos(-p->rotspeed);
	}
	if (keycode == 0)
	{
		p->olddirx = p->dirx;
		p->dirx = p->dirx * cos(p->rotspeed) - p->diry * sin(p->rotspeed);
		p->diry = p->olddirx * sin(p->rotspeed) + p->diry * cos(p->rotspeed);
		p->planex = p->planex * cos(p->rotspeed) - p->planey * sin(p->rotspeed);
		p->planey = p->oldplanex *
			sin(p->rotspeed) + p->planey * cos(p->rotspeed);
	}
	mlx_clear_window(t->e->mlx, t->e->win);
	mlx_destroy_image(t->e->mlx, t->e->image);
	cast_rays(t->e, t->tab, p, t);
}

int				move(int keycode, t_struct *t)
{
	if (keycode == 53)
		exit(0);
	real_move(keycode, t, t->p);
	return (0);
}
