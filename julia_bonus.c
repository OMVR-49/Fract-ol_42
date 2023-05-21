/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:02:40 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 04:25:30 by ojebbari         ###   ########.fr       */
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
	while (i < ITER && mag(zr, zi) <= 2.0)
	{
		tmp = a;
		a = tmp * tmp - b * b + hadik->julia_x;
		b = 2 * tmp * b + hadik->julia_y;
		i++;
	}
	return (i);
}

void render_julia_bonus(t_vars *hadik)
{
	int i;
	int j;
	int it;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			it = (julia((hadik->zoom_x + i - WIDTH / 2) / hadik->zoom, \
			(hadik->zoom_y + j - HEIGHT / 2) / hadik->zoom, hadik));
			my_mlx_pixel_put(hadik, i, j, which_color(it, hadik->color_num));
			i++;
		}
		j++;
	}
}

int mouse_handler_bonus(int x, int y, t_vars *hadik)
{
	hadik->julia_x = (x - WIDTH/2.0)/(WIDTH/4.0);
	hadik->julia_y = (y - WIDTH/2.0)/(WIDTH/4.0);
	render_set_bonus(hadik);
	return(0);
}