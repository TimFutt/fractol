/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:29:10 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 15:29:12 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_put_keys_colors(t_fractol *e)
{
	mlx_string_put(e->mlx, e->win, 775, 900, 0xFF0000, "Red color = { and \"");
	mlx_string_put(e->mlx, e->win, 775, 925, 0xFF00, "Green color = P and :");
	mlx_string_put(e->mlx, e->win, 775, 950, 0xFF, "Blue color = O and L");
}

void			ft_put_keys_fractals(t_fractol *e)
{
	if (e->fractal == 1)
		mlx_string_put(e->mlx, e->win, 105, 5, 0xFFFFFF, "Mandelbrot");
	if (e->fractal == 2)
	{
		mlx_string_put(e->mlx, e->win, 105, 5, 0xFFFFFF, "Julia");
		mlx_string_put(e->mlx, e->win, 10, 850, 0x00CCCB,
			"Press space to lock or delock the mouse");
	}
	if (e->fractal == 3)
		mlx_string_put(e->mlx, e->win, 105, 5, 0xFFFFFF, "Burningship");
	if (e->fractal == 4)
		mlx_string_put(e->mlx, e->win, 105, 5, 0xFFFFFF, "Douady");
}

void			ft_put_keys(t_fractol *e)
{
	mlx_string_put(e->mlx, e->win, 10, 5, 0x318CE7, "Fractal :");
	mlx_string_put(e->mlx, e->win, 10, 900, 0x00FF00,
		"Press 1, 2, 3 or 4 to change Fractal");
	mlx_string_put(e->mlx, e->win, 10, 925, 0xFFFF00,
		"Press + to increase iterations");
	mlx_string_put(e->mlx, e->win, 10, 950, 0xFFFF00,
		"Press - to decrease iterations");
	mlx_string_put(e->mlx, e->win, 10, 975, 0xFE1B00, "Press ESC to quit");
	ft_put_keys_colors(e);
	ft_put_keys_fractals(e);
}
