/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:14:10 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 03:45:20 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

static void	initialization(t_vars *bonus)
{
	bonus->zoom = ((WIDTH + HEIGHT) / 8.0);
	bonus->mlx_ptr = mlx_init();
	bonus->win_ptr = mlx_new_window(bonus->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	bonus->img = NULL;
	bonus->addr = NULL;
	bonus->color_num = 0;
	bonus->zoom_x = 0;
	bonus->zoom_y = 0;
	bonus->julia_x = 0;
	bonus->julia_y = 0;
}
static void	ft_parcing_bonus(t_vars *bonus, int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("No parameters provided use :julia, mandelbrot\
		, tricorn\n");
		exit(1);
	}
	if(argc != 2 || (ft_strcmp("mandelbrot", argv[1]) != 0 && ft_strcmp("julia",argv[1]) != 0 && ft_strcmp("tricorn",argv[1]) != 0))
	{
		ft_printf("Invalid parameters, available parameters: julia, mandelbrot\
, tricorn");
		exit(1);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		bonus->rraqm = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		bonus->rraqm = 2;
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		bonus->rraqm = 3;
}

int main(int argc, char **argv)
{
	t_vars	bonus;

	ft_parcing_bonus(&bonus ,argc, argv);
	initialization(&bonus);
	render_set_bonus(&bonus);
	mlx_hook(bonus.win_ptr, 6, 0, mouse_handler_bonus, &bonus);
	mlx_mouse_hook(bonus.win_ptr, mouse_zoom_follow, &bonus);
	mlx_hook(bonus.win_ptr, 17, 0, on_close, &bonus);
	mlx_hook(bonus.win_ptr, 2, 0, key_handler_bonus, &bonus);
	mlx_loop(bonus.mlx_ptr);
}
