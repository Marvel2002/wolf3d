/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:43:17 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 18:02:44 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		smog_walls(t_env *a, double d)
{
	double c;

	c = d / a->ray.dist;
	while (c <= d)
		return (c);
	return (d);
}

int		smog_ground(t_env *a, double d)
{
	double c;

	c = d / (a->height / 2);
	return (a->i * c);
}

int		smog_sky(t_env *a, double d)
{
	double c;

	c = d / (-a->height / 2);
	return (a->i * c);
}

void	set_color_rgb(t_env *a, int r, int g, int b)
{
	a->red = smog_walls(a, r);
	a->green = smog_walls(a, g);
	a->blue = smog_walls(a, b);
}

void	apply_color(t_env *a, int color, int i)
{
	if (color == 1)
		set_color_rgb(255, 0, 255);
	else if (color == 2)
		set_color_rgb(204, 255, 229);
	else if (color == 3)
		set_color_rgb(0, 153, 76);
	else if (color == 4)
		set_color_rgb(255, 255, 0);
	else if (color == 5)
		set_color_rgb(0, 0, 255);
	else if (color == 6)
		set_color_rgb(255, 0, 0);
	else
		color_error(a);
}
