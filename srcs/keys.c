/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:05:10 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/23 10:04:30 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			move_down(t_struct *t, t_player *p)
{
	ft_putendl("down");
	if (t->tab[(int)(p->posx - p->dirx * p->movespeed)][(int)(p->posy)]
			== 0)
		p->posx -= p->dirx * p->movespeed;
	if (t->tab[(int)(p->posx)][(int)(p->posy - p->diry * p->movespeed)]
			== 0)
		p->posy -= p->diry * p->movespeed;
}

void			move_up(t_struct *t, t_player *p)
{
	ft_putendl("up");
	if (t->tab[(int)(p->posx + p->dirx * p->movespeed)][(int)(p->posy)]
			== 0)
		p->posx += p->dirx * p->movespeed;
	if (t->tab[(int)(p->posx)][(int)(p->posy + p->diry * p->movespeed)]
			== 0)
		p->posy += p->diry * p->movespeed;
}

void			move_right(t_player *p)
{
	ft_putendl("right");
	p->oldplanex = p->planex;
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(-p->rotspeed) - p->diry * sin(-p->rotspeed);
	p->diry = p->olddirx * sin(-p->rotspeed) + p->diry * cos(-p->rotspeed);
	p->planex = p->planex * cos(-p->rotspeed) - p->planey * sin(-p->rotspeed);
	p->planey = p->oldplanex * sin(-p->rotspeed) +
		p->planey * cos(-p->rotspeed);
}

void			move_left(t_player *p)
{
	ft_putendl("left");
	p->oldplanex = p->planex;
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(p->rotspeed) - p->diry * sin(p->rotspeed);
	p->diry = p->olddirx * sin(p->rotspeed) + p->diry * cos(p->rotspeed);
	p->planex = p->planex * cos(p->rotspeed) - p->planey * sin(p->rotspeed);
	p->planey = p->oldplanex * sin(p->rotspeed) +
		p->planey * cos(p->rotspeed);
}

int				move(int keycode, t_struct *t)
{
	if (keycode == 13)
		move_up(t, t->p);
	if (keycode == 1)
		move_down(t, t->p);
	if (keycode == 2)
		move_right(t->p);
	if (keycode == 0)
		move_left(t->p);
	if (keycode == 53)
	{
		mlx_destroy_window(t->e->mlx, t->e->win);
		exit(0);
	}
	mlx_clear_window(t->e->mlx, t->e->win);
	mlx_destroy_image(t->e->mlx, t->e->image);
	cast_rays(t->e, t->tab, t->p, t);
	return (0);
}
