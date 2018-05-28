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
# define SUCCESS 1
# define FAILURE -1
# define FINISHED 42

typedef struct			s_env
{
	/* Data for draw functions */
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
	/* Colors */
	unsigned long	color;
	int				colb;
	int				colg;
	int				colr;
	/* mlx_get_data_addr */
	int				bits_per_pixels;
	int				endian;
	int				size_line;
	/* Events */
	int				fractal;
	int				iter;
	int				lock;
	/* Data for the windows */
	char			*data;
	void			*img;
	void			*mlx;
	void			*win;
}						t_env;

/*
** Functions to draw fractals
*/

void					ft_mandelbrot(t_env *e);
void					ft_julia(t_env *e);
void					ft_burningship(t_env *e);
void					ft_douady(t_env *e);

/*
** Functions to put keys to the screen
*/
void					ft_put_keys(t_env *e);
void					ft_put_keys_colors(t_env *e);
void            		ft_put_keys_fractals(t_env *e);

/*
** Utils functions
*/

void					ft_reset_fractal(t_env *e);
void					ft_center_window(t_env *e);

/*
** Events
*/

int						ft_events(int keycode, t_env *e);
void					ft_keys(t_env *e);
int						ft_mouse_julia(int x, int y, t_env *e);
int						ft_zoom(int button, int x, int y, t_env *e);

/*
** Functions to put pixels
*/

void					put_pxl_to_image(t_env *e, int x, int y);
void					put_pxl_to_image2(t_env *e, int x, int y);

/*
** Draw function
*/

void					ft_draw(t_env *e);

#endif
