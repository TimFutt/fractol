#include "../includes/fractol.h"

int				mouse_hook(int button, int x, int y, t_env *e)
{
	printf("keycode == %d\n", button);
	if (button == 5 || button == 1)
	{
		e->x2 = x;
		e->y2 = y;
		e->x1 = (x / e->zoom + e->x1) - ((e->zoom * 1.3) / 2);
		e->x1 += ((e->zoom * 1.3) / 2) - (x / (e->zoom * 1.3));
		e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.3) / 2);
		e->y1 += ((e->zoom * 1.3) / 2) - (y / (e->zoom * 1.3));
		e->zoom *= 1.1;
		e->iter_max++;
	}
	if (button == 4 || button == 2)
	{
		e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.3) / 2);
		e->x1 += ((e->zoom / 1.3) / 2) - (e->x2 / (e->zoom / 1.3));
		e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.3) / 2);
		e->y1 += ((e->zoom / 1.3) / 2) - (e->y2 / (e->zoom / 1.3));
		e->zoom /= 1.1;
		e->iter_max--;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (1);
}

static int		my_key_ft_swich(int keycode, t_env *e)
{
	if (keycode == 18 || keycode == 83)
	{
		e->fractal = 1;
		e->zoom = 250;
		e->iter_max = 10;
	}
	if (keycode == 19 || keycode == 84)
	{
		e->fractal = 2;
		e->zoom = 250;
		e->iter_max = 10;
	}
	if (keycode == 20 || keycode == 85)
	{
		e->fractal = 3;
		e->zoom = 250;
		e->iter_max = 10;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (1);
}

static int		my_key_ft_color(int keycode, t_env *e)
{
	if (keycode == 69)
		e->colr /= 2;
	if (keycode == 78)
		e->colr *= 2;
	if (keycode == 75)
		e->colg /= 2;
	if (keycode == 67)
		e->colg *= 2;
	if (keycode == 82)
		e->colb /= 2;
	if (keycode == 81)
		e->colb *= 2;
	if (keycode == 76 || keycode == 36)
		e->on = 1;
	if (keycode == 65)
		e->on = 0;
	if (keycode == 34)
		e->iter_max += 5;
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (1);
}

int				my_key_ft(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 123)
		e->x1 += 30 / e->zoom;
	if (keycode == 124)
		e->x1 -= 30 / e->zoom;
	if (keycode == 125)
		e->y1 -= 30 / e->zoom;
	if (keycode == 126)
		e->y1 += 20 / e->zoom;
	if (keycode == 86 || keycode == 21)
	{
		e->fractal = 4;
		e->zoom = 300;
		e->iter_max = 50;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	my_key_ft_color(keycode, e);
	my_key_ft_swich(keycode, e);
	return (1);
}

int				mouse_julia(int x, int y, t_env *e)
{
	if (e->on == 1)
	{
		e->julx = (double)x / (double)(e->zoom / 2) - 1;
		e->july = (double)y / (double)(e->zoom / 2) - 1;
	}
	ft_draw(e);
	return (0);
}
