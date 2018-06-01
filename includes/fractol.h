/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:33:04 by tifuret           #+#    #+#             */
/*   Updated: 2018/05/28 17:33:05 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct			s_fractol
{
	double			c_i;
	double			c_r;
	double			i;
	double			image_x;
	double			image_y;
	double			julx;
	double			july;
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			z_i;
	double			z_r;
	double			zoom;
	unsigned long	color;
	int				colb;
	int				colg;
	int				colr;
	int				bits_per_pixels;
	int				endian;
	int				size_line;
	int				fractal;
	int				iter;
	int				lock;
	char			*data;
	void			*img;
	void			*mlx;
	void			*win;
}						t_fractol;

/*
** Functions to draw fractals
*/

void					ft_mandelbrot(t_fractol *e);
void					ft_julia(t_fractol *e);
void					ft_burningship(t_fractol *e);
void					ft_douady(t_fractol *e);

/*
** Functions to put keys to the screen
*/
void					ft_put_keys(t_fractol *e);
void					ft_put_keys_colors(t_fractol *e);
void					ft_put_keys_fractals(t_fractol *e);

/*
** Utils functions
*/

void					ft_reset_fractal(t_fractol *e);
void					ft_center_window(t_fractol *e);
void					ft_set_all_window(t_fractol *e);

/*
** Events
*/

int						ft_events(int keycode, t_fractol *e);
void					ft_keys(t_fractol *e);
int						ft_mouse_julia(int x, int y, t_fractol *e);
int						ft_zoom(int keycode, int x, int y, t_fractol *e);

/*
** Functions to put pixels
*/

void					put_pxl_to_image(t_fractol *e, int x, int y);
void					put_pxl_to_image2(t_fractol *e, int x, int y);

/*
** Draw function
*/

void					ft_draw(t_fractol *e);

#endif
