/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:05:03 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 19:44:53 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed_move;
	double		speed_turn;
}				t_player;

typedef struct	s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		dist;
	double		cam;
	int			hit;
	int			hit_side;
}				t_ray;

typedef struct	s_env
{
	struct s_player		player;
	struct s_ray		ray;
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					**map;
	int					height;
	int					width;
	int					map_height;
	int					map_width;
	int					bpp;
	int					size_line;
	int					endien;
	double				blue;
	double				red;
	double				green;
	double				i;
}				t_env;

int				smog_walls(t_env *a, double d);
int				smog_ground(t_env *a, double d);
int				smog_sky(t_env *a, double d);
void			set_color_rgb(t_env *a, int r, int g, int b);
void			apply_color(t_env *a, int color, int i);
void			fill_pixel_walls(t_env *a, int x, int y);
void			fill_pixel_sky(t_env *a, int x, int y);
void			fill_pixel_ground(t_env *a, int x, int y);
void			draw_line(t_env *a, int x, int start, int end);
void			ray_drawline(t_env *a, int x);
void			put_error(t_env *a);
void			malloc_error(void);
void			map_error(t_env *a);
void			player_error(t_env *a);
void			color_error(t_env *a);
void			init_player(t_env *a);
t_env			*init_env(void);
void			ft_command(char **argv);
void			move_up(t_env *a);
void			move_down(t_env *a);
void			move_left(t_env *a);
void			move_right(t_env *a);
int				key_hook(int keycode, t_env *a);
int				close_hook(t_env *a);
int				expose_hook(t_env *a);
void			parse_position(int fd, t_env *a);
void			parse_line(char *line, int y, int **map, t_env *a);
int				parse_file(int fd, t_env *a);
int				file_open(t_env *a, char *argv);
void			wolf_init(t_env *a, int argc, char **argv);
int				set_color_sides(t_env *a);
void			calc_ray_step_side(t_env *a);
void			calc_ray_distance(t_env *a);
void			init_ray(t_env *a, int x);
void			raycasting(t_env *a);

#endif
