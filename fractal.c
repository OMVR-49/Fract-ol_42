/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:41:52 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 04:31:17 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_parcing(t_vars *hadik, int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf ("No parameters provided use :julia, mandelbrot\n");
		exit(1);
	}
	if(argc != 2 || (ft_strcmp("mandelbrot", argv[1]) != 0 && \
						ft_strcmp("julia",argv[1]) != 0))
	{
		ft_printf("Invalid parameters, available parameter: julia|mandelbrot");
		exit(1);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		hadik->rraqm = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		hadik->rraqm = 2;
}

int	main(int argc, char **argv)
{
	t_vars	hadik;

	ft_parcing(&hadik ,argc, argv);
	hadik.zoom = ((WIDTH + HEIGHT) / 8.0);
	hadik.mlx_ptr = mlx_init();
	hadik.win_ptr = mlx_new_window(hadik.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	render_set(&hadik);
	mlx_hook(hadik.win_ptr, 6, 0, mouse_handler, &hadik);
	mlx_hook(hadik.win_ptr, 17, 0, on_close, &hadik);
	mlx_hook(hadik.win_ptr, 2, 0, key_handler, &hadik);
	mlx_mouse_hook(hadik.win_ptr, mouse_zoom_handler, &hadik);
	mlx_loop(hadik.mlx_ptr);
	return (0);
}
