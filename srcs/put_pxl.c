/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:28:42 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 15:28:45 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			put_pxl_to_image(t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	e->color = 0x000000;
	r = ((e->color & 0xFF0000) >> 16);
	g = ((e->color & 0xFF00) >> 8);
	b = (e->color & 0xFF);
	e->data[(x * 4) + (y * e->size_line)] = b;
	e->data[(x * 4) + (y * e->size_line) + 1] = g;
	e->data[(x * 4) + (y * e->size_line) + 2] = r;
}

void			put_pxl_to_image2(t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (e->i * e->colr / e->iter * 4);
	g = (e->i * e->colg / e->iter * 2);
	b = (e->i * e->colb / e->iter * 4);
	e->data[(x * 4) + (y * e->size_line)] = b;
	e->data[(x * 4) + (y * e->size_line) + 1] = g;
	e->data[(x * 4) + (y * e->size_line) + 2] = r;
}
