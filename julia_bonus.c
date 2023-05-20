/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:58:36 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 22:19:50 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int	julia_bonus(double a, double b, t_vars *hadik)
{
	double		zr;
	double		zi;
	double		tmp;
	int			i;

	i = 0;
	zr = a;
	zi = b;
	while (i < ITER && mag_bonus(zr, zi) < 2.0)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + hadik->mouse_x ;
		zi = 2 * tmp * zi + hadik->mouse_y;
		i++;
	}
	return (i);
}

void render_julia_bonus(t_vars *hadik)
{
	int i;
	int j;
	int it;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			it = (julia_bonus((i - WIDTH / 2) / hadik->zoom, \
			(j - HEIGHT / 2) / hadik->zoom, hadik) / ITER) * 255;
			my_mlx_pixel_put_bonus(hadik, i, j, create_trgb_bonus(0, it, it, it));
			i++;
		}
		j++;
	}
}
