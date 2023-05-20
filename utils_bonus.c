/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:04:08 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/20 19:53:42 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int ft_strcmp_bonus(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	my_mlx_pixel_put_bonus(t_vars *hadik, int x, int y, int color)
{
	char	*dst;

	dst = hadik->addr + (y * hadik->line_length + x * (hadik->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	mag_bonus(double a, double b)
{
	return (sqrt(a * a + b * b));
}