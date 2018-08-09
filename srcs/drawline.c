/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 07:39:59 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/07 08:58:35 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double			ft_abs(double n)
{
	return (n > 0 ? n : (n) * -1);
}

void			draw(t_coordinates c, int x1, int y1, t_key mlx)
{
	t_draw		d;

	d.dx = x1 - c.x0;
	d.dy = y1 - c.y0;
	d.steps = ft_abs(d.dx) > ft_abs(d.dy) ? ft_abs(d.dx) : ft_abs(d.dy);
	d.xinc = d.dx / d.steps;
	d.yinc = d.dy / d.steps;
	d.x = c.x0;
	d.y = c.y0;
	while (d.steps)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, d.x, d.y, c.color);
		d.x += d.xinc;
		d.y += d.yinc;
		d.steps--;
	}
}
