#include "../includes/fractol.h"

void				ft_draw_mandelbrot(t_env *e)
{
	float			tmp;

	e->c_r = e->x / e->zoom + e->x1;
	e->c_i = e->y / e->zoom + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->iter_max)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}

void				ft_draw_julia(t_env *e)
{
	float			tmp;

	e->c_r = e->julx;
	e->c_i = e->july;
	e->z_r = e->x / e->zoom + e->x1;
	e->z_i = e->y / e->zoom + e->y1;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->iter_max)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}

void				ft_draw_burningship(t_env *e)
{
	double			tmp;

	e->c_r = e->x / e->zoom + e->x1;
	e->c_i = e->y / e->zoom + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * fabs(e->z_i * tmp) + e->c_i;
		e->i++;
	}
	if (e->i == e->iter_max)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}

void				ft_draw_douady(t_env *e)
{
	double			tmp;

	e->z_r = e->x / e->zoom + e->x1;
	e->z_i = e->y / e->zoom + e->y1;
	e->c_r = -0.12;
	e->c_i = 0.75;
	e->i = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
	{
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->iter_max)
		put_pxl_to_image(e, e->x, e->y);
	else
		put_pxl_to_image2(e, e->x, e->y);
}

void				ft_draw(t_env *e)
{
	ft_bzero(e->data, e->size_l * 1000);
	e->image_x = (e->x2 - e->x1) * e->zoom;
	e->image_y = (e->y2 - e->y1) * e->zoom;
	e->x = 0;
	while (e->x++ < e->image_x)
	{
		e->y = 0;
		while (e->y++ < e->image_y)
		{
			if (e->fractal == 1)
				ft_draw_mandelbrot(e);
			if (e->fractal == 2)
				ft_draw_julia(e);
			if (e->fractal == 3)
				ft_draw_burningship(e);
			if (e->fractal == 4)
				ft_draw_douady(e);
			if (e->y >= 1000)
				break ;
		}
		if (e->x >= 1000)
			break ;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_string_put(e);
}
