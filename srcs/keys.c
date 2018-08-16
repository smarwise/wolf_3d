/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:05:10 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/16 17:40:33 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int             real_move(int keycode, t_struct *t, t_player p)
{
    if (keycode == 13)
    {
      if(t->tab[(int)(p.posX + p.dirX * p.moveSpeed)][(int)(p.posY)] == '.')
          p.posX += p.dirX * p.moveSpeed;
      if(t->tab[(int)(p.posX)][(int)(p.posY + p.dirY * p.moveSpeed)] == '.')
          p.posY += p.dirY * p.moveSpeed;
    }
    if (keycode == 1)
    {
      if (t->tab[(int)(p.posX - p.dirX * p.moveSpeed)][(int)(p.posY)] == '.')
          p.posX -= p.dirX * p.moveSpeed;
      if(t->tab[(int)(p.posX)][(int)(p.posY - p.dirY * p.moveSpeed)] == '.')
          p.posY -= p.dirY * p.moveSpeed;
    }
    if (keycode == 2)
    {
      double oldDirX = p.dirX;
      p.dirX = p.dirX * cos(-p.rotSpeed) - p.dirY * sin(-p.rotSpeed);
      p.dirY = oldDirX * sin(-p.rotSpeed) + p.dirY * cos(-p.rotSpeed);
      double oldPlaneX = p.planeX;
      p.planeX = p.planeX * cos(-p.rotSpeed) - p.planeY * sin(-p.rotSpeed);
      p.planeY = oldPlaneX * sin(-p.rotSpeed) + p.planeY * cos(-p.rotSpeed);
    }
    if (keycode == 0)
    {
      double oldDirX = p.dirX;
      p.dirX = p.dirX * cos(p.rotSpeed) - p.dirY * sin(p.rotSpeed);
      p.dirY = oldDirX * sin(p.rotSpeed) + p.dirY * cos(p.rotSpeed);
      double oldPlaneX = p.planeX;
      p.planeX = p.planeX * cos(p.rotSpeed) - p.planeY * sin(p.rotSpeed);
      p.planeY = oldPlaneX * sin(p.rotSpeed) + p.planeY * cos(p.rotSpeed);
    }
    mlx_clear_window(t->e.mlx.mlx, t->e.mlx.win);
	mlx_destroy_image(t->e.mlx.mlx, t->e.mlx.image);
    cast_rays(&t->e, t->tab, &p, t);
    return (0);
}

int		move(int keycode, t_struct *t)
{
	real_move(keycode, t, t->p);
	return (0);
}
