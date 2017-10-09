/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:43:52 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 18:05:29 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill_pixel_walls(t_env *a, int x, int y)
{
	int i;
	int j;
	int color;

	i = 0 + (4 * x);
	j = i + (a->size_line * y);
	color = set_color(a);
	apply_color(a, color, a->i);
	a->data[j] = a->blue;
	a->data[j + 1] = a->green;
	a->data[j + 2] = a->red;
}

void	fill_pixel_sky(t_env *a, int x, int y)
{
	int i;
	int j;
	int color;

	i = 0 + (4 * x);
	j = i + (a->size_line * y);
	apply_color(a, 5, a->i);
	a->data[j] = a->blue;
	a->data[j + 1] = a->green;
	a->data[j + 2] = a->red;
}

void	fill_pixel_ground(t_env *a, int x, int y)
{
	int i;
	int j;
	int color;

	i = 0 + (4 * x);
	j = i + (a->size_line * y);
	apply_color(a, 6, a->i);
	a->data[j] = a->blue;
	a->data[j + 1] = a->green;
	a->data[j + 2] = a->red;
}

void	draw_line(t_env *a, int x, int start, int end)
{
	a->i = 0;
	while (a->i <= a->height / 2)
	{
		fill_pixel_sky(a, x, a->i);
		a->i++;
	}
	while (a->i < a->height)
	{
		fill_pixel_ground(a, x, a->i);
		a->i++;
	}
	a->i = start;
	while (a->i <= end && a->i < a->height)
	{
		fill_pixel_walls(a, x, a->i);
		a->i++;
	}
}

void	ray_drawline(t_env *a, int x)
{
	int height;
	int start;
	int end;

	height = (int)(a->height / a->ray.dist);
	start = -height / 2 + a->height / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + a->height / 2;
	if (end >= a->height)
		end = a->height - 1;
	draw_line(a, x, start, end);
}
