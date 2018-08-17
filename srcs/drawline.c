/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:34:17 by smarwise          #+#    #+#             */
/*   Updated: 2018/08/17 07:23:07 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double			ft_abs(double n)
{
	return (n > 0 ? n : (n) * -1);
}

void			new_image(t_key *m)
{
	m->image = mlx_new_image(m->mlx, screenwidth, screenheight);
	m->data = mlx_get_data_addr(m->image, &m->bpp, &m->sizeline, &m->endian);
	m->bpp /= 8;
}

void			put_pixel(t_key *mlx, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y <= screenheight && x <= screenwidth)
		*(unsigned int *)(mlx->data + (x * mlx->bpp) +
				(y * mlx->sizeline)) = color;
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
		put_pixel(&mlx, d.x, d.y, c.color);
		d.x += d.xinc;
		d.y += d.yinc;
		d.steps--;
	}
}
