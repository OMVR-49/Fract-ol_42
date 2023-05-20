/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:43:50 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 22:11:22 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_BONUS_H
# define FRACTAL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800
# define ITER 40.0
# define ZOOM_FACTOR 1.1
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
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
	double zoom;
	double mouse_x;
	double mouse_y;
	int	color;
	int	color_number;
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

void	ft_parcing_bonus(t_vars *hadik, int argc, char **argv);

void	my_mlx_pixel_put_bonus(t_vars *hadik, int x, int y, int color);
double	mag_bonus(double a, double b);
int ft_strcmp_bonus(char *s1, char *s2);
int	on_close_bonus(t_vars *hadik);

void	render_mandelbrot_bonus(t_vars *hadik);
int	mandelbrot_bonus(double a, double b);

void	render_julia_bonus(t_vars *hadik);
int	julia_bonus(double a, double b, t_vars *hadik);

void	render_set_bonus(t_vars *hadik);
// void	render_burning_ship_bonus(t_vars *hadik);
void	color_shift(t_vars *hadik);


int	mouse_zoom_handler_bonus(int button, int x, int y, t_vars *param);
int	mouse_handler_bonus(int x, int y, t_vars *hadik);
int	mouse_move_hook(int x, int y, t_vars *data);
int	key_handler_bonus(int keycode, void *param);

int	create_trgb_bonus(int t, int r, int g, int b);
int	color_set1(double i);
int	color_set(double i);
int which_color(double i, int color);


// int	burning_ship(double a, double b, t_vars *hadik);

#endif
