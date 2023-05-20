/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:32:40 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 20:02:37 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int	create_trgb_bonus(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_set(double i)
{
	int				color;
	unsigned char	rgb;

	color = 0;
	rgb = 255 - i / ITER * 255.0;
	color = rgb;
	color = (color << 8) | rgb;
	color = (color << 8) | rgb;
	return (color);
}

int	color_set1(double i)
{
	int		color;
	double	ratio;

	color = 0;
	ratio = i / ITER;
	color = (unsigned char)(10 * (1 - ratio) * pow(ratio, 2) * 255);
	color = (color << 8) | (unsigned char)(3 * pow((1 - ratio), 3) * pow(ratio,
				2) * 255);
	color = (color << 8) | (unsigned char)(2 * pow((1 - ratio), 3)
			* (ratio) * 255);
	return (color);
}

int which_color(double i, int color)
{
	if (color == 0)
		return(color_set(i));
	else if (color == 1)
		return (color_set1(i));
	return(0);
}

void	color_shift(t_vars *hadik)
{
	hadik->color_number = ++hadik->color_number % 4;
	render_set_bonus(hadik);
}