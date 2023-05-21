/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:01:19 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 03:49:01 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void render_mandelbrot_bonus(t_vars *hadik)
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
			it = mandelbrot((hadik->zoom_x + i - WIDTH / 2) / hadik->zoom, (hadik->zoom_y + j - HEIGHT / 2) / hadik->zoom);
			my_mlx_pixel_put(hadik, i, j, which_color(it, hadik->color_num));
			i++;
		}
		j++;
	}
}
