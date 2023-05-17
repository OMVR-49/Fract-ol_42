/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:07:34 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/17 15:23:32 by ojebbari         ###   ########.fr       */
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
	(void)param;
	if(keycode == 53)
		on_close(param);
	return 0;
}
int mouse_key_handler(int button, int x, int y, t_vars *param)
{
	x = 0;
	y = x;
	if(button == 4)
		param->zoom *= 1.05;
	else if(button == 5)
		param->zoom /= 1.05;
	render_set(param);
	return y;
}