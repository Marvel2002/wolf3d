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
	{1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

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

void	apply_color(t_env *a, int color, int i)
{
	if (color == 1)
	{
		a->red = smog_walls(a, 255);
		a->green = smog_walls(a, 0);
		a->blue = smog_walls(a, 255);
	}
	else if (color == 2)
	{
		a->red = smog_walls(a, 204);
		a->green = smog_walls(a, 255);
		a->blue = smog_walls(a, 229);
	}
	else if (color == 3)
	{
		a->red = smog_walls(a, 0);
		a->green = smog_walls(a, 153);
		a->blue = smog_walls(a, 76);
	}
	else if (color == 4)
	{
		a->red = smog_walls(a, 255);
		a->green = smog_walls(a, 255);
		a->blue = 0;
	}
	else if (color == 5)
	{	
		a->red = 0;
		a->green = 0;
		a->blue = smog_sky(a, 255);
	}
	else if (color == 6)
	{	
		a->red = smog_ground(a, 255);
		a->green = 0;
		a->blue = 0;
	}
	else
	{
		printf("wrong color, color = %d\n", color);
	}
}


int		set_color(t_env *a)
{
	int color;
	
	color = 1;
	if (a->ray.hit_side == 1)
	{
		if ((a->ray.step_x == -1 && a->ray.step_y == -1) || (a->ray.step_x == 1 && a->ray.step_y == -1))
			return (color);
		if ((a->ray.step_x == -1 && a->ray.step_y == 1) || (a->ray.step_x == 1 && a->ray.step_y == 1))
			return (color + 1);
	}
	if ((a->ray.step_x == -1 && a->ray.step_y == -1) || (a->ray.step_x == -1 && a->ray.step_y == 1))
		return (color + 2);
	return (color + 3);
}

void	fill_pixel(t_env *a, int x, int y)
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

void	fill_pixel2(t_env *a, int x, int y)
{

	int i;
	int j;
	int color;

	i = 0 + (4 * x);
	j = i + (a->size_line * y);
	//color = set_color(a);
	apply_color(a, 5, a->i);
	a->data[j] = a->blue;
	a->data[j + 1] = a->green;
	a->data[j + 2] = a->red;
}

void	fill_pixel3(t_env *a, int x, int y)
{
	int i;
	int j;
	int color;

	i = 0 + (4 * x);
	j = i + (a->size_line * y);
	//color = set_color(a);
	apply_color(a, 6, a->i);
	a->data[j] = a->blue;
	a->data[j + 1] = a->green;
	a->data[j + 2] = a->red;
}



void	draw_line(t_env *a, int x, int start, int end)
{
	a->i = -1;

	while (++a->i <= a->height / 2)
		fill_pixel2(a, x, a->i);
	while (++a->i < a->height)
		fill_pixel3(a, x, a->i);
	a->i = start;
	while (++a->i <= end && a->i < a->height)
		fill_pixel(a, x, a->i);
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
			//printf("%f ", a->ray.dist);
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
	a->player.plane_x = 0;
	a->player.plane_y = 0.66;
	a->player.speed_move = 0.05;
	a->player.speed_turn = 0.05;
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

void	move_up(t_env *a)
{
	if (worldmap[(int)(a->player.pos_x + a->player.dir_x * a->player.speed_move)][(int)a->player.pos_y] == 0)
		a->player.pos_x += a->player.dir_x * a->player.speed_move;
	if (worldmap[(int)a->player.pos_x][(int)(a->player.pos_y + a->player.dir_y * a->player.speed_move)] == 0)
		a->player.pos_y += a->player.dir_y * a->player.speed_move;
}

void	move_down(t_env *a)
{
	if (worldmap[(int)(a->player.pos_x - a->player.dir_x * a->player.speed_move)][(int)a->player.pos_y] == 0)
		a->player.pos_x -= a->player.dir_x * a->player.speed_move;
	if (worldmap[(int)a->player.pos_x][(int)(a->player.pos_y - a->player.dir_y * a->player.speed_move)] == 0)
		a->player.pos_y -= a->player.dir_y * a->player.speed_move;
}

void	move_left(t_env *a)
{
	double old;

	old = a->player.dir_x;
	a->player.dir_x = a->player.dir_x * cos(a->player.speed_turn) -
		a->player.dir_y * sin(a->player.speed_turn);
	a->player.dir_y = old * sin(a->player.speed_turn) +
		a->player.dir_y * cos(a->player.speed_turn);
	old = a->player.plane_x;
	a->player.plane_x = a->player.plane_x * cos(a->player.speed_turn) -
		a->player.plane_y * sin(a->player.speed_turn);
	a->player.plane_y = old * sin(a->player.speed_turn) +
		a->player.plane_y * cos(a->player.speed_turn);
}

void	move_right(t_env *a)
{
	double old;

	old = a->player.dir_x;
	a->player.dir_x = a->player.dir_x * cos(-a->player.speed_turn) -
		a->player.dir_y * sin(-a->player.speed_turn);
	a->player.dir_y = old * sin(-a->player.speed_turn) +
		a->player.dir_y * cos(-a->player.speed_turn);
	old = a->player.plane_x;
	a->player.plane_x = a->player.plane_x * cos(-a->player.speed_turn) -
		a->player.plane_y * sin(-a->player.speed_turn);
	a->player.plane_y = old * sin(-a->player.speed_turn) +
		a->player.plane_y * cos(-a->player.speed_turn);
}

int		key_hook(int keycode, t_env *a)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
		move_up(a);
	if (keycode == 1)
		move_down(a);
	if (keycode == 0)
		move_left(a);
	if (keycode == 2)
		move_right(a);
	raycasting(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	return (0);
}

void	init()
{
	
	char *line;
	char **line_split;
	int i;
	int fd;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);
	if (get_next_line(fd, &line) < 1)
		exit(1); // mettre la ft
	line_split = ft_strsplit(line, ' ');
	while (line_split[i])
		i++;
	if (i != 4)
		exit(1);
	a->map_width = ft_atoi(line_split[0]);
	a->map_height = ft_atoi(line_split[1]);
	a->player.pos_x = ft_atoi(line_split[2]);
	a->player.pos_y = ft_atoi(line_split[3]);
	if (a->map_width < 0 || a->map_height < 0 || a->player.pos_x < 0 || a->player.pos_y < 0 || a->player.pos_x >= a->map_width || a->player.pos_y >= a->map_width)
		exit(1);

}

void	wolf_init(t_env *a, int argc, char **argv)
{
	if (argc != 2)
		put_error(a);
	if (!file(a, argv[1]))
		map_error();
}

int		main(int argc, char **argv)
{

	t_env		*a;

	a = malloc(sizeof(t_env));
	if (!a)
		error_malloc();
	wolf_init(a, argc, argv);
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "wolf");
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->data = mlx_get_data_addr(a->img, &a->bpp, &a->size_line, &a->endien);
	a->width = WIDTH;
	a->height = HEIGHT;
	init_player(a);
	raycasting(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_hook(a->win, 2, 1, key_hook, a);
	//mlx_key_hook(a->win, key_hook, a->win);
	mlx_loop(a->mlx);
	return (0);
}
