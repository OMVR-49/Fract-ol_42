/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:59:08 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 22:07:43 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

double	mag(double a, double b)
{
	return (sqrt(a * a + b * b));
}

void	my_mlx_pixel_put(t_vars *hadik, int x, int y, int color)
{
	char	*dst;

	dst = hadik->addr + (y * hadik->line_length + x * (hadik->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}