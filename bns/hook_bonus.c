/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:43:37 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 22:12:26 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int on_close_bonus(t_vars *hadik)
{
	(void)hadik;
	exit(0);
}

int key_handler_bonus(int keycode, void *param)
{
	if(keycode == 257)
		color_shift(param);
	else if(keycode == UP)
	{
		
		render_set_bonus(param);
	}
	else if(keycode == DOWN)
	{
		
		render_set_bonus(param);
	}
	else if(keycode == LEFT)
	{
		
		render_set_bonus(param);
	}
	else if(keycode == RIGHT)
	{
		
		render_set_bonus(param);
	}
	else if(keycode == 53)
		on_close_bonus(param);
	return 0;
}

int mouse_handler_bonus(int x, int y, t_vars *hadik)
{
	if (hadik->rraqm != 2)
		return 0;
	hadik->mouse_x = (x - WIDTH/2.0)/(WIDTH/4.0);
	hadik->mouse_y = (y - HEIGHT/2.0)/(HEIGHT/4.0);
	render_set_bonus(hadik);
	return(0);
}

// int		mouse_zoom_handler_bonus(int button, int x, int y, t_vars *data)
// {
// 	double	scale_factor;
// 	double	dx;
// 	double	dy;
// 	if (button == 4 || button == 5) // Zoom in or out only if mouse wheel is scrolled
// 	{
// 		if (button == 4) // Zoom in
// 			scale_factor = 1.1;
// 		if (button == 5) // Zoom out
// 			scale_factor = 0.9;

// 		double new_scale = data->scale * scale_factor;

// 		// Adjust the scaling center based on mouse position
// 		dx = (x - data->mouse_x) * (1.0 / data->scale - 1.0 / new_scale);
// 		dy = (y - data->mouse_y) * (1.0 / data->scale - 1.0 / new_scale);

// 		data->scale = new_scale;
// 	}
// 	return (0);
// }


