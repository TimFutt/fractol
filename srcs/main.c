#include "../includes/fractol.h"

void				ft_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "Fractol");
	e->x = 0;
	e->y = 0;
	e->zoom = 250;
	e->iter_max = 10;
	e->colr = 255;
	e->colg = 255;
	e->colb = 255;
	e->on = 1;
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_l), &(e->endian));
}

void				wrong_entry(int ac)
{
	if (ac > 2)
		ft_putendl("Error : too many arguments.");
	else if (ac == 2)
		ft_putendl("Error : wrong entry.");
	ft_putendl("usage: ./fractol [-julia, -mandelbrot, -burningship, -douady]");
}

int					main(int ac, char **av)
{
	t_env			e;

	if (ac == 2 && ((!ft_strcmp(av[1], "-mandelbrot")) ||
				(!ft_strcmp(av[1], "-julia")) ||
				(!ft_strcmp(av[1], "-burningship")) ||
				(!ft_strcmp(av[1], "-douady"))))
	{
		if(!ft_strcmp(av[1], "-mandelbrot"))
			e.fractal = 1;
		if (!ft_strcmp(av[1], "-julia"))
			e.fractal = 2;
		if(!ft_strcmp(av[1], "-burningship"))
			e.fractal = 3;
		if(!ft_strcmp(av[1], "-douady"))
			e.fractal = 4;
		ft_init(&e);
		ft_calc(&e);
		ft_draw(&e);
		ft_event(&e);
		mlx_loop(e.mlx);
	}
	else
		wrong_entry(ac);
	return (0);
}
