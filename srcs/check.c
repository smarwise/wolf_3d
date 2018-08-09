/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:35:59 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 15:36:06 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void        check(t_env *e, char **tab)
{
    int i = 0;
    t_player p;
    t_coordinates c;

    p.posx = 2;
    p.posy = 7;
    p.wall = '#';
    while (e->points)
    {
        //printf("%i\n", i);
        if (e->points->z == '.' && (!(e->points->x == 2 && e->points->y == 7)))
            mlx_pixel_put(e->mlx.mlx, e->mlx.win, (e->points->x * e->points->scale) + e->points->shift, (e->points->y * e->points->scale) + e->points->shift, 0xFFFFFF);
        else if (e->points->z == '.' && e->points->x == 2 && e->points->y == 7)
            mlx_pixel_put(e->mlx.mlx, e->mlx.win, (e->points->x * e->points->scale) + e->points->shift, (e->points->y * e->points->scale) + e->points->shift, 0xF000FF);
        else
            mlx_pixel_put(e->mlx.mlx, e->mlx.win, (e->points->x * e->points->scale) + e->points->shift, (e->points->y * e->points->scale) + e->points->shift, 0xFF0060);
        e->points = e->points->next;
        i++;
    }
    while (p.posx >= 0 && p.posy >= 0) //&& (tab[p.posy][p.posx] != p.wall))
    {
        printf("%i", p.posx);
        if (tab[p.posy - 1][p.posx + 1] != p.wall)
        {
            c.x0 = (p.posx * e->points->scale) + e->points->shift;
            c.y0 = (p.posy * e->points->scale) + e->points->shift;
            c.color = 0xF000FF;
            draw(c, ((p.posx + 1) * e->points->scale) + e->points->shift, ((p.posy - 1) * e->points->scale) + e->points->shift, e->mlx);
        }
        else
        {
           c.x0 = (p.posx * e->points->scale) + e->points->shift;
           c.y0 = (p.posy * e->points->scale) + e->points->shift;
           c.color = 0xF000FF;
           draw(c, ((p.posx + 1) * e->points->scale) + e->points->shift, ((p.posy - 1) * e->points->scale) + e->points->shift, e->mlx);
           break; 
        }
        p.posx++;
        p.posy--;
    }
}