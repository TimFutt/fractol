#include "../includes/fractol.h"

void			ft_calc(t_env *e)
{
	e->x1 = -2.05;
	e->x2 = 2;
	e->y1 = -1.3;
	e->y2 = 2;
}

void			put_pxl_to_image(t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	e->color = 0x000000;
	r = ((e->color & 0xFF0000) >> 16);
	g = ((e->color & 0xFF00) >> 8);
	b = (e->color & 0xFF);
	e->data[(x * 4) + (y * e->size_l)] = b;
	e->data[(x * 4) + (y * e->size_l) + 1] = g;
	e->data[(x * 4) + (y * e->size_l) + 2] = r;
}

void			put_pxl_to_image2(t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (e->i * e->colr / e->iter_max * 4);
	g = (e->i * e->colg / e->iter_max * 2);
	b = (e->i * e->colb / e->iter_max * 4);
	e->data[(x * 4) + (y * e->size_l)] = b;
	e->data[(x * 4) + (y * e->size_l) + 1] = g;
	e->data[(x * 4) + (y * e->size_l) + 2] = r;
}

void			ft_event(t_env *e)
{
	mlx_key_hook(e->win, my_key_ft, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, 0, mouse_julia, e);
}

void			ft_string_put(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 5, 0xFF00FF, "FRACTOL");
	mlx_string_put(e->mlx, e->win, 10, 25, 0xFF00FF, "Fractal :");
	mlx_string_put(e->mlx, e->win, 10, 900, 0xFF00FF, "Press =, /, *, -,\
			+, 0 to change colors");
	mlx_string_put(e->mlx, e->win, 10, 925, 0xFF00FF, "Press 1, 2, 3 or\
			4 to change Fractal");
	mlx_string_put(e->mlx, e->win, 10, 950, 0xFF00FF, "Press i to increase\
			iterations");
	mlx_string_put(e->mlx, e->win, 10, 975, 0xFF00FF, "Press ESC to quit");
	if (e->fractal == 4)
		mlx_string_put(e->mlx, e->win, 105, 25, 0xFF00FF, "Douady");
	else if (e->fractal == 3)
		mlx_string_put(e->mlx, e->win, 105, 25, 0xFF00FF, "Burningshit");
	else if (e->fractal == 2)
	{
		mlx_string_put(e->mlx, e->win, 105, 25, 0xFF00FF, "Julia");
		mlx_string_put(e->mlx, e->win, 10, 850, 0xFF00FF, "Press enter\
				to start mouse move");
		mlx_string_put(e->mlx, e->win, 10, 875, 0xFF00FF, "Press . to stop\
				mouse move");
	}
	else if (e->fractal == 1)
		mlx_string_put(e->mlx, e->win, 105, 25, 0xFF00FF, "Mandelbrot");
}
