/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 07:47:13 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/11 07:47:15 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "wolf3d.h"
#include "../includes/wolf3d.h"
#include <time.h>

#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void        press(int keycode, t_var v)
{
   //move forward if no wall in front of you
    if (keycode == 13)
    {
      if(worldMap[(int)(v.posX + v.dirX * v.moveSpeed)][(int)v.posY] == false) v.posX += v.dirX * v.moveSpeed;
      if(worldMap[(int)(v.posX)][(int)(v.posY + v.dirY * v.moveSpeed)] == false) v.posY += v.dirY * v.moveSpeed;
    }
    //move backwards if no wall behind you
    if (keycode == 1)
    {
      if(worldMap[(int)(v.posX - v.dirX * v.moveSpeed)][(int)(v.posY)] == false) v.posX -= v.dirX * v.moveSpeed;
      if(worldMap[(int)(v.posX)][(int)(v.posY - v.dirY * v.moveSpeed)] == false) v.posY -= v.dirY * v.moveSpeed;
    }
    //rotate to the right
    if (keycode == 2)
    {
      //both camera direction and camera plane must be rotated
       v.oldDirX = v.dirX;
      v.dirX = v.dirX * cos(-v.rotSpeed) - v.dirY * sin(-v.rotSpeed);
      v.dirY = v.oldDirX * sin(-v.rotSpeed) + v.dirY * cos(-v.rotSpeed);
      v.oldPlaneX = v.planeX;
      v.planeX = v.planeX * cos(-v.rotSpeed) - v.planeY * sin(-v.rotSpeed);
      v.planeY = v.oldPlaneX * sin(-v.rotSpeed) + v.planeY * cos(-v.rotSpeed);
    }
    //rotate to the left
    if (keycode == 0)
    {
      //both camera direction and camera plane must be rotated
      v.oldDirX = v.dirX;
      v.dirX = v.dirX * cos(v.rotSpeed) - v.dirY * sin(v.rotSpeed);
      v.dirY = v.oldDirX * sin(v.rotSpeed) + v.dirY * cos(v.rotSpeed);
      v.oldPlaneX = v.planeX;
      v.planeX = v.planeX * cos(v.rotSpeed) - v.planeY * sin(v.rotSpeed);
      v.planeY = v.oldPlaneX * sin(v.rotSpeed) + v.planeY * cos(v.rotSpeed);
    }
}

/*double     ft_abs(double n)
{
    return (n >= 0 ? n : -n);
}*/

/*int    done()
{
  return (0);
  return (1);  
}*/

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    t_key mlx;
    int b = 0;
    int x0;
    int y0;
    t_coordinates c;
    t_var   v;
    int w = screenwidth;
    double posX = 22, posY = 12;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    x0 =  posX;
    y0  = posY;    
    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, screenwidth, screenheight, "Raycaster");
    while(b <= 40)
    {
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
          double perpWallDist;

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
           if (worldMap[mapX][mapY] > 0) 
           {
             c.x0 = x0;
             c.y0 = y0;
             c.color = 0xFFFF90;
           //  draw(c, mapX, mapY, mlx);
             hit = 1;
           }
         }
         //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
         if (side == 0)
            perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
          else
            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

        int h = screenheight;
         //Calculate height of line to draw on screen
        int lineHeight = (int)(h / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + h / 2;
        if(drawStart < 0)drawStart = 0;
         int drawEnd = lineHeight / 2 + h / 2;
         if(drawEnd >= h)drawEnd = h - 1;

      //choose wall color
      int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = 0xFF0000;  break; //red
        case 2:  color = 0x00FF00;  break; //green
        case 3:  color = 0x0000FF;   break; //blue
        case 4:  color = 0xFFFFFF;  break; //white
        default: color = 0xFFFF90; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}
        c.color = 0xFFFFFF;
        c.x0 = x;
        c.y0 = drawStart;
      //draw the pixels of the stripe as a vertical line
//      verLine(x, drawStart, drawEnd, color);
       draw(c, x, drawEnd, mlx);
    }
    //timing for input and FPS counter
    oldTime = time;
    time = clock();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    //print(1.0 / frameTime); //FPS counter
    //redraw();
    //cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second*/
    v.posX = posX;
	  v.posY = posY;
	  v.dirY =	dirY;
	  v.dirX = dirX;
	  v.moveSpeed = moveSpeed;
	 // v.oldDirX = oldDirX;
	  //v.oldDirY = oldDirY;;
	  v.rotSpeed = rotSpeed;
    v.planeX = planeX;
    v.planeY = planeY;
    b++;
  }
  mlx_key_hook(mlx.win, press, mlx.mlx);
  mlx_key_hook(mlx.win, key_set, mlx.mlx);
  mlx_loop(mlx.mlx);
}