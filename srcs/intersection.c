/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:44:29 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/10 13:45:59 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void        intersection(t_env *e, char **tab)
{
    t_coordinates c;
    t_points          *points;

    (void)tab;
    points = e->points;
    double posX = 2, posY = 7;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
    double sideDistX = 0.0;
    double sideDistY = 0.0;

 //   double time = 0; //time of current frame
   // double oldTime = 0; //time of previous frame
    int w = 0;
    c.x0 = posX;
    c.y0 = posY;
    c.color = 0xFF000F;
//  screen(512, 384, 0, "Raycaster");
    while (points)
	{
		c.color = points->c;
		if (points->right)
		{
			c.x0 = points->x * 25 + 250;
			c.y0 = points->y * 25 + 250;
			draw(c, points->right->x * 25 + 250,
					points->right->y * 25 + 250, e->mlx);
		}
		if (points->up)
		{
			c.x0 = points->x * 25 + 250;
			c.y0 = points->y * 25 + 250;
			draw(c, points->up->x * 25 + 250,
					points->up->y * 25 + 250, e->mlx);
		}
//		printf("x : %i y : %i z : %c\n", c.x0, c.y0, points->z);
		points = points->next;
	}
    int t = 0;
    mlx_pixel_put(e->mlx.mlx, e->mlx.win, posX * 25 + 250, posY * 25 + 250, 0xFF0000);
     while(sideDistX >= 0 && sideDistY >= 0 && t < 100)
     {
         printf()
       for(int x = 0; x < w; x++)
       {
         //calculate ray position and direction
         double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
         double rayDirX = dirX + planeX * cameraX;
         double rayDirY = dirY + planeY * cameraX;
         //which box of the map we're in
         int mapX = (int)posX;
         int mapY = (int)posY;

          //length of ray from current position to next x or y-side
          double sideDistX;
          double sideDistY;

          //length of ray from one x or y-side to next x or y-side
           double deltaDistX = ft_abs(1 / rayDirX);
          double deltaDistY = ft_abs(1 / rayDirY);
       //   double perpWallDist;

          //what direction to step in x or y-direction (either +1 or -1)
          int stepX;
          int stepY;

          int hit = 0; //was there a wall hit?
          int side; //was a NS or a EW wall hit?
          //calculate step and initial sideDist
          if (rayDirX < 0)
          {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
          }
          else
          {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
          }
          if (rayDirY < 0)
          {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
          }
          else
          {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
          }
          //perform DDA
          while (hit == 0)
          {
            //jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY)
            {
              sideDistX += deltaDistX;
              mapX += stepX;
              side = 0;
            }
            else
            {
              sideDistY += deltaDistY;
              mapY += stepY;
              side = 1;
            }
            //Check if ray has hit a wall
          //  if (worldMap[mapX][mapY] > 0) hit = 1;
          while (tab[(int)posY][(int)posX] != '#')
          {
              posX += stepX;
              posY += sideDistY;
          }
          draw(c, posX, posY, e->mlx);
          }
       }
       t++;
      }
}