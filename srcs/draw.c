/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:28:50 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 15:28:53 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				ft_draw(t_env *e)
{
	ft_bzero(e->data, e->size_line * 1000);
	e->image_x = (e->x2 - e->x1) * e->zoom;
	e->image_y = (e->y2 - e->y1) * e->zoom;
	e->x = 0;
	while (e->x++ < e->image_x)
	{
		e->y = 0;
		while (e->y++ < e->image_y)
		{
			if (e->fractal == 1)
				ft_mandelbrot(e);
			if (e->fractal == 2)
				ft_julia(e);
			if (e->fractal == 3)
				ft_burningship(e);
			if (e->fractal == 4)
				ft_douady(e);
			if (e->y >= 1000)
				break ;
		}
		if (e->x >= 1000)
			break ;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_put_keys(e);
	ft_put_keys_colors(e);
	ft_put_keys_fractals(e);
}
