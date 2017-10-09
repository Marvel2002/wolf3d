/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:45:00 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 18:12:12 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		set_color_sides(t_env *a)
{
	int color;

	color = 1;
	if (a->ray.hit_side == 1)
	{
		if ((a->ray.step_x == -1 && a->ray.step_y == -1) ||
				(a->ray.step_x == 1 && a->ray.step_y == -1))
			return (color);
		if ((a->ray.step_x == -1 && a->ray.step_y == 1) ||
				(a->ray.step_x == 1 && a->ray.step_y == 1))
			return (color + 1);
	}
	if ((a->ray.step_x == -1 && a->ray.step_y == -1) ||
			(a->ray.step_x == -1 && a->ray.step_y == 1))
		return (color + 2);
	return (color + 3);
}

void	calc_ray_step_side(t_env *a)
{
	if (a->ray.dir_x < 0)
	{
		a->ray.step_x = -1;
		a->ray.side_x = (a->ray.pos_x - (int)a->ray.pos_x) * a->ray.delta_x;
	}
	else
	{
		a->ray.step_x = 1;
		a->ray.side_x = ((int)a->ray.pos_x + 1 - a->ray.pos_x) * a->ray.delta_x;
	}
	if (a->ray.dir_y < 0)
	{
		a->ray.step_y = -1;
		a->ray.side_y = (a->ray.pos_y - (int)a->ray.pos_y) * a->ray.delta_y;
	}
	else
	{
		a->ray.step_y = 1;
		a->ray.side_y = ((int)a->ray.pos_y + 1 - a->ray.pos_y) * a->ray.delta_y;
	}
}

void	calc_ray_distance(t_env *a)
{
	while (a->ray.hit == 0)
	{
		if (a->ray.side_x < a->ray.side_y)
		{
			a->ray.side_x += a->ray.delta_x;
			a->ray.map_x += a->ray.step_x;
			a->ray.hit_side = 0;
		}
		else
		{
			a->ray.side_y += a->ray.delta_y;
			a->ray.map_y += a->ray.step_y;
			a->ray.hit_side = 1;
		}
		if (a->map[a->ray.map_x][a->ray.map_y] > 0)
		{
			a->ray.hit = 1;
			if (a->ray.hit_side == 0)
				a->ray.dist = (a->ray.map_x - a->ray.pos_x +
						(1 - a->ray.step_x) / 2) / a->ray.dir_x;
			else
				a->ray.dist = (a->ray.map_y - a->ray.pos_y +
						(1 - a->ray.step_y) / 2) / a->ray.dir_y;
		}
	}
}

void	init_ray(t_env *a, int x)
{
	a->ray.map_x = (int)a->player.pos_x;
	a->ray.map_y = (int)a->player.pos_y;
	a->ray.cam = 2 * x / (double)a->width - 1;
	a->ray.dir_x = a->player.dir_x + a->player.plane_x * a->ray.cam;
	a->ray.dir_y = a->player.dir_y + a->player.plane_y * a->ray.cam;
	a->ray.delta_x = sqrt(1 + (a->ray.dir_y * a->ray.dir_y) /
			(a->ray.dir_x * a->ray.dir_x));
	a->ray.delta_y = sqrt(1 + (a->ray.dir_x * a->ray.dir_x) /
			(a->ray.dir_y * a->ray.dir_y));
	a->ray.hit = 0;
	a->ray.dist = -1;
	a->ray.hit_side = -1;
}

void	raycasting(t_env *a)
{
	int	x;

	x = 0;
	a->ray.pos_x = a->player.pos_x;
	a->ray.pos_y = a->player.pos_y;
	while (x < a->width)
	{
		init_ray(a, x);
		calc_ray_step_side(a);
		calc_ray_distance(a);
		ray_drawline(a, x);
		x++;
	}
}
