/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:33:06 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 03:09:40 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

// int mouse_zoom_bonus(int button, int x, int y, t_vars *hadik)
// {
// 	x = 0;
// 	y = x;
// 	if(button == 4)
// 		hadik->zoom *= ZOOM_FACTOR;
// 	else if(button == 5)
// 		hadik->zoom /= ZOOM_FACTOR;
// 	render_set_bonus(hadik);
// 	return (y);
// }

int	mouse_zoom_follow(int keycode, int x, int y, t_vars *hadik)
{
	x = x - (WIDTH / 2);
	y = y - (HEIGHT / 2);

	if(keycode == 4)
	{
		hadik->zoom *= ZOOM_FACTOR;
		hadik->zoom_x *= ZOOM_FACTOR;
		hadik->zoom_y *= ZOOM_FACTOR;
		hadik->zoom_x += x * (ZOOM_FACTOR - 1);
		hadik->zoom_y += y * (ZOOM_FACTOR - 1);
		render_set_bonus(hadik);
	}
	else if(keycode == 5)
	{
		hadik->zoom /= ZOOM_FACTOR;
		hadik->zoom_x /= ZOOM_FACTOR;
		hadik->zoom_y /= ZOOM_FACTOR;
		render_set_bonus(hadik);
	}
	return (0);
}

void render_set_bonus(t_vars *bonus)
{
	bonus->img = mlx_new_image(bonus->mlx_ptr, WIDTH, HEIGHT);
	bonus->addr = mlx_get_data_addr(bonus->img, &bonus->bits_per_pixel, &bonus->line_length,
								&bonus->endian);
	mlx_clear_window(bonus->mlx_ptr, bonus->win_ptr);
	if (bonus->rraqm == 1)
		render_mandelbrot_bonus(bonus);
	else if (bonus->rraqm == 2)
		render_julia_bonus(bonus);
	else if (bonus->rraqm == 3)
		render_Tricorn(bonus);
	mlx_put_image_to_window(bonus->mlx_ptr, bonus->win_ptr, bonus->img, 0, 0);
}

int key_handler_bonus(int keycode, t_vars *bonus)
{
	if(keycode == UP)
	{
		bonus->zoom_y -= 50;
		render_set_bonus(bonus);
	}
	else if (keycode == DOWN)
	{
		bonus->zoom_y += 50;
		render_set_bonus(bonus);
	}
	else if (keycode == LEFT)
	{
		bonus->zoom_x -= 50;
		render_set_bonus(bonus);
	}
	else if (keycode == RIGHT)
	{
		bonus->zoom_x += 50;
		render_set_bonus(bonus);
	}
	else if(keycode == SHIFT)
		color_shift(bonus);
	else if(keycode == 53)
		on_close(bonus);
	return 0;
}
