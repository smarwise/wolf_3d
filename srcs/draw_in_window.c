/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_in_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:12:21 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 11:12:23 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

float nScreenHeight = 1400;
float nScreenDepth = 1400;
float nMapWidth = 9;
float nMapHeight = 9;

void        calculate(t_points *t, t_rows d, t_env *env)
{
    t_axis      var;
    t_player    pl;
    int         nShade;

    var.x = 0;
    pl.FOV = M_PI / 4;
    pl.disttowall = 0;
    var.hitwall = false;
    pl.posx = 700;
    pl.posy = 700;
    var.columns = d.columns;
    {
        while (1)
        {
            while (var.x < 1400)
            {
                pl.rayangle = (pl.angle - pl.FOV / 2.0f) + ((float)var.x / (float)1400 * pl.FOV);
                var.x++;
                while (!var.hitwall && pl.disttowall < 9)
                {
                    pl.disttowall += 0.1f;
                    int nTestX = (int)(pl.posx + pl.eyex * pl.disttowall);
                    int nTestY = (int)(pl.posy + pl.eyey * pl.disttowall);
                    if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
				    {
				    	var.hitwall = true;
				    	pl.disttowall = 9;
			    	}
                    else
                    {
                        if (t->z == '#')
                        {
                            var.hitwall = true;
                        }
                    }
                    t = t->next;
                }
                int nCeiling = ((float)(nScreenHeight/2.0) - nScreenHeight / pl.disttowall);
			    int nFloor = nScreenHeight - nCeiling;
                for (int y = 0; y < nScreenHeight; y++)
			    {
    				if(y <= nCeiling)
                        mlx_pixel_put(env->mlx.mlx, env->mlx.win, pl.posx, pl.posy, nShade);
   // 					screen[y*1400 + x] = ' ';
    				else if(y > nCeiling && y <= nFloor)
                        mlx_pixel_put(env->mlx.mlx, env->mlx.win, pl.posx, pl.posy, nShade);
    	//				screen[y*1400 + x] = nShade;
    				else // Floor
    				{				
    					// Shade floor based on distance
    					float b = 1.0f - (((float)y -nScreenHeight/2.0f) / ((float)nScreenHeight / 2.0f));
    					if (b < 0.25)		nShade = '#';
    					else if (b < 0.5)	nShade = 'x';
    					else if (b < 0.75)	nShade = '.';
    					else if (b < 0.9)	nShade = '-';
    					else				nShade = ' ';
                        mlx_pixel_put(env->mlx.mlx, env->mlx.win, pl.posx, pl.posy, nShade);
    				//	screen[y*nScreenWidth + x] = nShade;
				}
             //   t = t->next;
			}

            }
        }
    }
}