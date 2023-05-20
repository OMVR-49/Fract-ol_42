/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:00:06 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/19 19:45:59 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int	mandelbrot_bonus(double a, double b)
{
	double		zr;
	double		zi;
	double		tmp;
	int			i;

	i = 0;
	zi = 0;
	zr = 0;
	while (i < ITER && mag_bonus(zr, zi) < 2.0)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + a;
		zi = 2 * tmp * zi + b;
		i++;
	}
	return (i);
}

void render_mandelbrot_bonus(t_vars *hadik)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			hadik->it = (mandelbrot_bonus((i - WIDTH / 2) / hadik->zoom, (j - HEIGHT / 2) / hadik->zoom) / ITER) * 255;
			my_mlx_pixel_put_bonus(hadik, i, j, create_trgb_bonus(0, hadik->it- 10, hadik->it - 15, hadik->it-5));
			i++;
		}
		j++;
	}
}
