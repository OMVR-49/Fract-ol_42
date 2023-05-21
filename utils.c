/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:59:08 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 01:15:33 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void render_set(t_vars *hadik)
{
	hadik->img = mlx_new_image(hadik->mlx_ptr, WIDTH, HEIGHT);
	hadik->addr = mlx_get_data_addr(hadik->img, &hadik->bits_per_pixel, &hadik->line_length,
								&hadik->endian);
	mlx_clear_window(hadik->mlx_ptr, hadik->win_ptr);
	if (hadik->rraqm == 1)
		render_mandelbrot(hadik);
	else if (hadik->rraqm == 2)
		render_julia(hadik);
	mlx_put_image_to_window(hadik->mlx_ptr, hadik->win_ptr, hadik->img, 0, 0);
}

void	my_mlx_pixel_put(t_vars *hadik, int x, int y, int color)
{
	char	*dst;

	dst = hadik->addr + (y * hadik->line_length + x * (hadik->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

