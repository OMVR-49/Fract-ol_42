/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:41:52 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/16 23:31:48 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_parcing(t_vars *hadik, int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf (" No parameters provided");
		exit(1);
	}
	if(argc != 2 || (strcmp("mandelbrot", argv[1]) != 0 && strcmp("julia",argv[1]) != 0))
	{
		ft_printf("Invalid parameters, available parameters: julia, mandelbrot");
		exit(1);
	}
	else if (strcmp(argv[1], "mandelbrot") == 0)
		hadik->rraqm = 1;
	else if (strcmp(argv[1], "julia") == 0)
		hadik->rraqm = 2;
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

void f()
{
	system("leaks FRACTAL");
}

int	main(int argc, char **argv)
{
	t_vars	hadik;
	
	//atexit(f);
	ft_parcing(&hadik ,argc, argv);
	hadik.zoom = ((WIDTH + HEIGHT) / 8.0);
	hadik.mlx_ptr = mlx_init();
	hadik.win_ptr = mlx_new_window(hadik.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	render_set(&hadik);
	mlx_hook(hadik.win_ptr, 6, 0, mouse_handler, &hadik);
	mlx_hook(hadik.win_ptr, 17, 0, on_close, &hadik);
	mlx_hook(hadik.win_ptr, 2, 0, key_handler, &hadik);
	mlx_mouse_hook(hadik.win_ptr, mouse_key_handler, &hadik);
	mlx_loop(hadik.mlx_ptr);
	return (0);
}
