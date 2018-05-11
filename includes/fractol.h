#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct			s_env
{
	double			c_i;
	double			c_r;
	double			h;
	double			i;
	double			image_x;
	double			image_y;
	double			julx;
	double			july;
	double			x1;
	double			x2;
	double			x;
	double			y1;
	double			y2;
	double			y;
	double			z_i;
	double			z_r;
	double			zoom;
	unsigned long	color;
	float			a;
	float			b;
	int				bpp;
	int				colb;
	int				colg;
	int				colr;
	int				endian;
	int				fractal;
	int				iter_max;
	int				on;
	int				size_l;
	char			*data;
	void			*img;
	void			*mlx;
	void			*win;
}						t_env;

void					ft_event(t_env *e);
void					ft_draw(t_env *e);
void					ft_calc(t_env *e);
void					ft_init(t_env *e);
void					put_pxl_to_image(t_env *e, int x, int y);
void					put_pxl_to_image2(t_env *e, int x, int y);
int						my_key_ft(int keycode, t_env *e);
int						mouse_julia(int x, int y, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
void					ft_string_put(t_env *e);

#endif
