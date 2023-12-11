/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:46:01 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/21 05:23:47 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int	color_ko0(double i)
{
	int				clr;
	unsigned char	rgb;

	clr = 0;
	rgb = 255 - i / ITER * 255.0;
	clr = rgb;
	clr = (clr << 8) | rgb;
	clr = (clr << 8) | rgb;
	return (clr);
}

int	color_ko1(double i)
{
	int		clr;
	double	raat;

	clr = 0;
	raat = i / ITER;
	clr = (unsigned char)(9 * (1 - raat) * pow(raat, 3) * 255);
	clr = (clr << 8) | (unsigned char)(15 * pow((1 - raat), 2) * 255);
	clr = (clr << 8) | (unsigned char)(8.5 * pow((1 - raat), 3) * raat * 255);
	return (clr);
}

void	color_shift(t_vars *hadik)
{
	hadik->color_num = ++hadik->color_num % 2;
	render_set_bonus(hadik);
}

int	which_color(double i, int ko)
{
	if (ko == 0)
		return (color_ko0(i));
	else if (ko == 1)
		return (color_ko1(i));
	return (0);
}
