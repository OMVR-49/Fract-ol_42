/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:43:50 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 03:28:41 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_BONUS_H
# define FRACTAL_BONUS_H

# include "fractal.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf/ft_printf.h"

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define SHIFT 257

void render_set_bonus(t_vars *bonus);

void render_Tricorn(t_vars *hadik);
int	Tricorn(double a, double b);

int	mouse_zoom_follow(int keycode, int x, int y, t_vars *hadik);

int key_handler_bonus(int keycode, t_vars *bonus);

void color_shift(t_vars *hadik);

int which_color(double i, int ko);
int color_ko0(double i);
int color_ko1(double i);

void render_mandelbrot_bonus(t_vars *hadik);

void render_julia_bonus(t_vars *hadik);

int mouse_handler_bonus(int x, int y, t_vars *hadik);

int	julia_bonus(double a, double b, t_vars *hadik);

#endif
