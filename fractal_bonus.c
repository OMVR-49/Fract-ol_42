/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:14:10 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 22:08:35 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	ft_parcing_bonus(t_vars *hadik, int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("No parameters provided use :julia, mandelbrot\
		, burningship\n");
		exit(1);
	}
	if(argc != 2 || (ft_strcmp_bonus("mandelbrot", argv[1]) != 0 && \
						ft_strcmp_bonus("julia",argv[1]) != 0))
	{
		ft_printf("Invalid parameters, available parameters: julia, mandelbrot\
, burningship");
		exit(1);
	}
	else if (ft_strcmp_bonus(argv[1], "mandelbrot") == 0)
		hadik->rraqm = 1;
	else if (ft_strcmp_bonus(argv[1], "julia") == 0)
		hadik->rraqm = 2;
	else if (ft_strcmp_bonus(argv[1], "burningship") == 0)
		hadik->rraqm = 3;
}

void render_set_bonus(t_vars *hadik)
{
	hadik->img = mlx_new_image(hadik->mlx_ptr, WIDTH, HEIGHT);
	hadik->addr = mlx_get_data_addr(hadik->img, &hadik->bits_per_pixel, &hadik->line_length,
								&hadik->endian);
	mlx_clear_window(hadik->mlx_ptr, hadik->win_ptr);
	if (hadik->rraqm == 1)
		render_mandelbrot_bonus(hadik);
	else if (hadik->rraqm == 2)
		render_julia_bonus(hadik);
	// else if (hadik->rraqm == 3)
	// 	render_burning_ship(hadik);
	mlx_put_image_to_window(hadik->mlx_ptr, hadik->win_ptr, hadik->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_vars	hadik;

	ft_parcing_bonus(&hadik ,argc, argv);
	hadik.zoom = ((WIDTH + HEIGHT) / 8.0);
	hadik.mlx_ptr = mlx_init();
	hadik.win_ptr = mlx_new_window(hadik.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	render_set_bonus(&hadik);
	mlx_hook(hadik.win_ptr, 17, 0, on_close_bonus, &hadik);
	mlx_hook(hadik.win_ptr, 2, 0, key_handler_bonus, &hadik);
	// mlx_hook(hadik.win_ptr, 2, 0, color_change_handler_bonus, &hadik);
	mlx_hook(hadik.win_ptr, 6, 0, mouse_handler_bonus, &hadik);
	// mlx_hook(hadik.win_ptr, 6, 0, mouse_move_hook, &hadik);
	// mlx_mouse_hook(hadik.win_ptr, mouse_zoom_handler_bonus, &hadik);
	mlx_loop(hadik.mlx_ptr);
	return (0);
}
