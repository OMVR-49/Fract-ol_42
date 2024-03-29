/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:52:33 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 05:20:48 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot(double a, double b)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zi = 0;
	zr = 0;
	while (i < ITER && mag(zr, zi) <= 2.0)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + a;
		zi = 2 * tmp * zi + b;
		i++;
	}
	return (i);
}

void	render_mandelbrot(t_vars *hadik)
{
	int	i;
	int	j;
	int	it;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			it = (mandelbrot((i - WIDTH / 2) / hadik->zoom, \
							(j - HEIGHT / 2) / hadik->zoom) / ITER) * 255;
			my_mlx_pixel_put(hadik, i, j, create_trgb(0, it, it, it));
			i++;
		}
		j++;
	}
}
