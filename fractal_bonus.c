/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:43:47 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/12 23:10:07 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

// void	ft_parcing(int c, char *argv[])
// {
// 	if (c != 2)
		
// }

int	main(int c,char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		it;
	int		j;
	int		i;

	// ft_parcing(c, argv);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "fractol");
	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			it = (mandelbrot((i - WIDTH / 2) / (WIDTH / 4.0), \
			(j - HEIGHT / 2) / (HEIGHT / 4.0)) / ITER) * 255;
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, create_trgb(0, it, it, it));
			i++;
		}
		j++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
