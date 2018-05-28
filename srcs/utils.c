/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:29:22 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 15:29:24 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Function to reset when we change the fractal
*/

void			ft_reset_fractal(t_env *e)
{
	e->zoom = 150;
	e->iter = 20;
	e->colr = 255;
	e->colg = 255;
	e->colb = 255;
}

/*
** Function to center the window at the begining
*/

void				ft_center_window(t_env *e)
{
	int		i;

	i = -1;
	while (++i != 6)
		e->x1 -= 30 / e->zoom;
	i = -1;
	while (++i != 6)
		e->y1 -= 30 / e->zoom;
}

/*
** Function to moove Julia
*/

int				ft_mouse_julia(int x, int y, t_env *e)
{
	if (e->lock > 0)
	{
		e->julx = (double)x / (double)(e->zoom / 2) - 1;
		e->july = (double)y / (double)(e->zoom / 2) - 1;
	}
	ft_draw(e);
	return (FINISHED);
}
