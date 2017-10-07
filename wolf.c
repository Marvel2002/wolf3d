/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:33:55 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/05 15:30:59 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define mapWidth 24
#define mapHeight 24
#include "wolf.h"

int		worldmap[24][24] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void	apply_color(t_env *a, char *str)
{
	if (!ft_strcmp(str, "green"))
	{
		a->red = 76;
		a->green = 153;
		a->blue = 0;
	}
	if (!ft_strcmp(str, "grey"))
	{
		a->red = 0;
		a->green = 153;
		a->blue = 153;
	}
	if (!ft_strcmp(str, "yellow"))
	{
		a->red = 255;
		a->green = 255;
		a->blue = 0;
	}
	if (!ft_strcmp(str, "blue"))
	{
		a->red = 0;
		a->green = 0;
		a->blue = 255;
	}
	//else
	//	exit(1);
}




void	fill_pixel(t_env *a, int x, int y)
{

	int i;
	int j;

	i = 0 + (4 * x);
	j = i + (a->size_line * y);

	if (a->ray.hit_side == 1)
	{
		if ((a->ray.step_x == -1 && a->ray.step_y == -1) || (a->ray.step_x == 1 && a->ray.step_y == -1))
			apply_color(a, "yellow");
		if ((a->ray.step_x == -1 && a->ray.step_y == 1) || (a->ray.step_x == 1 && a->ray.step_y == 1))
			apply_color(a, "green");
	}
	if ((a->ray.step_x == -1 && a->ray.step_y == -1) || (a->ray.step_x == -1 && a->ray.step_y == 1))
		apply_color(a, "grey");
	//apply_color(a, "blue");
	a->data[j] = a->blue;
	a->data[j + 1] = a->green;
	a->data[j + 2] = a->red;
}

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

void	draw_line(t_env *a, int x, int start, int end)
{
	int i;

	i = -1;
	while (++i <= end + a->player.z && i < a->height)
		fill_pixel(a, x, i);
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
		if (worldmap[a->ray.map_x][a->ray.map_y] > 0)
		{

			a->ray.hit = 1;
			if (a->ray.hit_side == 0)
				a->ray.dist = (a->ray.map_x - a->ray.pos_x + (1 - a->ray.step_x) / 2) / a->ray.dir_x;
			else
				a->ray.dist = (a->ray.map_y - a->ray.pos_y + (1 - a->ray.step_y) / 2) / a->ray.dir_y;
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
	a->ray.delta_x = sqrt(1 + (a->ray.dir_y * a->ray.dir_y) / (a->ray.dir_x * a->ray.dir_x));
	a->ray.delta_y = sqrt(1 + (a->ray.dir_x * a->ray.dir_x) / (a->ray.dir_y * a->ray.dir_y));
	a->ray.hit = 0;
	a->ray.dist = -1;
	a->ray.hit_side = -1;
}

void	init_player(t_env *a)
{
	a->player.pos_x = 10;
	a->player.pos_y = 10;
	a->player.dir_x = -1;
	a->player.dir_y = 0;
	a->player.z = 0;
	a->player.plane_x = 0;
	a->player.plane_y = 0.66;
}

void	raycasting(t_env *a)
{
	int	x; 

	x = -1;
	a->ray.pos_x = a->player.pos_x;
	a->ray.pos_y = a->player.pos_y;
	while (++x < a->width)
	{
		init_ray(a, x);
		calc_ray_step_side(a);
		calc_ray_distance(a);
		ray_drawline(a, x);
	}
}

int		main(int argc, char **argv)
{

	t_env		*a;

	a = malloc(sizeof(t_env));
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "wolf");
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->data = mlx_get_data_addr(a->img, &a->bpp, &a->size_line, &a->endien);
	a->width = WIDTH;
	a->height = HEIGHT;
	init_player(a);
	raycasting(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_key_hook(a->win, key_hook, a->win);
	mlx_loop(a->mlx);
	return (0);
}
