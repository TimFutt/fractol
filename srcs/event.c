/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:28:57 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 15:29:00 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Function to zoom with the mouse
*/

int		ft_zoom(int keycode, int x, int y, t_env *e)
{
	printf("keycode == %d\n", keycode);
	if (keycode == 5 || keycode == 1)
	{
		e->x2 = x;
		e->y2 = y;
		e->x1 = (x / e->zoom + e->x1) - ((e->zoom * 1.3) / 2);
		e->x1 += ((e->zoom * 1.3) / 2) - (x / (e->zoom * 1.3));
		e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.3) / 2);
		e->y1 += ((e->zoom * 1.3) / 2) - (y / (e->zoom * 1.3));
		e->zoom *= 1.1;
	}
	if (keycode == 4 || keycode == 2)
	{
		e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.3) / 2);
		e->x1 += ((e->zoom / 1.3) / 2) - (e->x2 / (e->zoom / 1.3));
		e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.3) / 2);
		e->y1 += ((e->zoom / 1.3) / 2) - (e->y2 / (e->zoom / 1.3));
		e->zoom /= 1.1;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (FINISHED);
}

/*
** Fucntion to change fractals
*/

int		ft_switch_fractals(int keycode, t_env *e)
{
	if (keycode == 18)
	{
		e->fractal = 1;
		ft_reset_fractal(e);
	}
	if (keycode == 19)
	{
		e->fractal = 2;
		ft_reset_fractal(e);
	}
	if (keycode == 20)
	{
		e->fractal = 3;
		ft_reset_fractal(e);
	}
	if (keycode == 21)
	{
		e->fractal = 4;
		ft_reset_fractal(e);
	}
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (FINISHED);
}

/*
** Fucntion to change colors
*/

int		ft_keys_colors(int keycode, t_env *e)
{
	if (keycode == 39)
		e->colr /= 2;
	if (keycode == 33)
		e->colr *= 2;
	if (keycode == 41)
		e->colg /= 2;
	if (keycode == 35)
		e->colg *= 2;
	if (keycode == 37)
		e->colb /= 2;
	if (keycode == 31)
		e->colb *= 2;
	if (e->fractal == 2)
		if (keycode == 49)
			e->lock *= -1;
	if (keycode == 69)
		e->iter++;
	if (keycode == 78)
		e->iter--;
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (FINISHED);
}

/*
** Function to moove the fractal
*/

int		ft_keys_moove(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(SUCCESS);
	if (keycode == 123)
		e->x1 += 30 / e->zoom;
	if (keycode == 124)
		e->x1 -= 30 / e->zoom;
	if (keycode == 125)
		e->y1 -= 30 / e->zoom;
	if (keycode == 126)
		e->y1 += 30 / e->zoom;
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (FINISHED);
}

/*
** Init events
*/

int		ft_events(int keycode, t_env *e)
{
	printf("keycode == %d\n", keycode);
	ft_switch_fractals(keycode, e);
	ft_keys_colors(keycode, e);
	ft_keys_moove(keycode, e);
	return (FINISHED);
}
