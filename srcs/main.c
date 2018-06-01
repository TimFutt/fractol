/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:29:16 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 15:29:18 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Init the prog
*/

void				ft_init(t_fractol *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "Fractol");
	e->x = 0;
	e->y = 0;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = 150;
	e->iter = 20;
	e->colr = 255;
	e->colg = 255;
	e->colb = 255;
	e->lock = 1;
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &(e->bits_per_pixels),
				&(e->size_line), &(e->endian));
}

void				ft_wrong_entry(int ac)
{
	if (ac > 2)
		ft_putendl("Error : too many arguments.");
	else if (ac == 2)
		ft_putendl("Error : wrong entry.");
	ft_putendl("usage: ./fractol [-julia, -mandelbrot, -burningship, -douady]");
}

int					main(int ac, char **av)
{
	t_fractol			e;

	if (ac == 2 && ((!ft_strcmp(av[1], "-mandelbrot")) ||
				(!ft_strcmp(av[1], "-julia")) ||
				(!ft_strcmp(av[1], "-burningship")) ||
				(!ft_strcmp(av[1], "-douady"))))
	{
		if (!ft_strcmp(av[1], "-mandelbrot"))
			e.fractal = 1;
		if (!ft_strcmp(av[1], "-julia"))
			e.fractal = 2;
		if (!ft_strcmp(av[1], "-burningship"))
			e.fractal = 3;
		if (!ft_strcmp(av[1], "-douady"))
			e.fractal = 4;
		ft_init(&e);
		ft_center_window(&e);
		ft_draw(&e);
		ft_set_all_window(&e);
		ft_keys(&e);
		mlx_loop(e.mlx);
	}
	else
		ft_wrong_entry(ac);
	return (FINISHED);
}
