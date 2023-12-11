/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:13:10 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 05:23:30 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int	tricorn(double a, double b)
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
		zi = -2 * tmp * zi + b;
		i++;
	}
	return (i);
}

void	render_tricorn(t_vars *hadik)
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
			it = tricorn((hadik->zoom_x + i - WIDTH / 2) / hadik->zoom,
					(hadik->zoom_y + j - HEIGHT / 2) / hadik->zoom);
			my_mlx_pixel_put(hadik, i, j, which_color(it, hadik->color_num));
			i++;
		}
		j++;
	}
}
