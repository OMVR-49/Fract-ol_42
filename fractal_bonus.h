/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:43:50 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/12 23:03:29 by ojebbari         ###   ########.fr       */
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

double	mag(double a, double b);
int		mandelbrot(double a, double b);
int		create_trgb(int t, int r, int g, int b);
#endif