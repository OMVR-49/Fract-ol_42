/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:41:49 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/16 21:54:37 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800
# define ITER 40.0
# define ZOOM_FACTOR 1.1

typedef struct s_vars {
   	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int	it;
	int	i;
	int	j;
	int	rraqm;
	double mouse_x;
	double mouse_y;
	double zoom;
} t_vars;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void render_julia(t_vars *hadik);
int	julia(double a, double b, t_vars *hadik);
double	mag(double a, double b);
int		mandelbrot(double a, double b);
int		create_trgb(int t, int r, int g, int b);
int on_close(t_vars *hadik);
void	render_mandelbrot(t_vars *s);
int	mouse_handler(int x, int y, t_vars *hadik);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void	render_set(t_vars *hadik);
	int key_handler(int keycode, void *param);
		int mouse_key_handler(int button, int x, int y, t_vars *param);
#endif