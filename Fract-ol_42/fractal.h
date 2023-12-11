/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:41:49 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 06:01:26 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "printf/ft_printf.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define ITER 40.0
# define ZOOM_FACTOR 1.1

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		it;
	int		i;
	int		j;

	int		rraqm;

	double	julia_x;
	double	julia_y;

	double	zoom;
	double	zoom_x;
	double	zoom_y;

	int		color_num;
}			t_vars;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void		render_mandelbrot(t_vars *hadik);
int			mandelbrot(double a, double b);

void		render_julia(t_vars *hadik);
int			julia(double a, double b, t_vars *hadik);

void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void		render_set(t_vars *hadik);

int			create_trgb(int t, int r, int g, int b);
int			on_close(t_vars *hadik);
int			ft_strcmp(char *s1, char *s2);
double		mag(double a, double b);

int			mouse_zoom_handler(int button, int x, int y, t_vars *param);
int			mouse_handler(int x, int y, t_vars *hadik);

int			key_handler(int keycode, void *param);

void		hooks(t_vars *hadik);

#endif
