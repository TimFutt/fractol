/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:29:04 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 15:29:06 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				ft_mandelbrot(t_fractol *e)
{
	float			tmp;

	e->c_r = e->x / e->zoom + e->x1;
	e->c_i = e->y / e->zoom + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->iter)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}

void				ft_julia(t_fractol *e)
{
	float			tmp;

	e->c_r = e->julx;
	e->c_i = e->july;
	e->z_r = e->x / e->zoom + e->x1;
	e->z_i = e->y / e->zoom + e->y1;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->iter)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}

void				ft_burningship(t_fractol *e)
{
	double			tmp;

	e->c_r = e->x / e->zoom + e->x1;
	e->c_i = e->y / e->zoom + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * fabs(e->z_i * tmp) + e->c_i;
		e->i++;
	}
	if (e->i == e->iter)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}

void				ft_douady(t_fractol *e)
{
	double			tmp;

	e->z_r = e->x / e->zoom + e->x1;
	e->z_i = e->y / e->zoom + e->y1;
	e->c_r = -0.12;
	e->c_i = 0.75;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->iter)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}
