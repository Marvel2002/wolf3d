/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:05:03 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/05 14:46:20 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

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
	struct		s_player	player;
	struct		s_ray		ray;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			**map;
	int			height;
	int			width;
	int			map_height;
	int			map_width;
	int			bpp;
	int 		size_line;
	int			endien;
	double		blue;
	double		red;
	double 		green;
	double		i;
}				t_env;
