/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:27:52 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/16 16:45:48 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int mouse_handler(int x, int y, t_vars *hadik)
{
	if (hadik->rraqm != 2)
		return 0;
	hadik->mouse_x = (x - WIDTH/2.0)/(WIDTH/4.0);
	hadik->mouse_y = (y - HEIGHT/2.0)/(HEIGHT/4.0);
	render_set(hadik);
	return(0);
}