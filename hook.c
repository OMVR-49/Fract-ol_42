/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:07:34 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 19:11:08 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int on_close(t_vars *hadik)
{
	(void)hadik;
	exit(0);
}
int key_handler(int keycode, void *param)
{
	if(keycode == 53)
		on_close(param);
	return 0;
}

int mouse_handler(int x, int y, t_vars *hadik)
{
	if (hadik->rraqm != 2)
		return 0;
	hadik->mouse_x = (x - WIDTH/2.0)/(WIDTH/4.0);
	hadik->mouse_y = (y - HEIGHT/2.0)/(HEIGHT/4.0);
	render_set(hadik);
	return(0);
}

int mouse_zoom_handler(int button, int x, int y, t_vars *hadik)
{
	x = 0;
	y = x;
	if(button == 4)
		hadik->zoom *= 1.05;
	else if(button == 5)
		hadik->zoom /= 1.05;
	render_set(hadik);
	return (y);
}
