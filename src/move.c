/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:44:37 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/10 15:53:09 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	move_up(t_env *a)
{
	if (a->map[(int)(a->player.pos_x + a->player.dir_x *
				a->player.speed_move)][(int)a->player.pos_y] == 0)
		a->player.pos_x += a->player.dir_x * a->player.speed_move;
	if (a->map[(int)a->player.pos_x][(int)(a->player.pos_y + a->player.dir_y *
				a->player.speed_move)] == 0)
		a->player.pos_y += a->player.dir_y * a->player.speed_move;
}

void	move_down(t_env *a)
{
	if (a->map[(int)(a->player.pos_x - a->player.dir_x *
				a->player.speed_move)][(int)a->player.pos_y] == 0)
		a->player.pos_x -= a->player.dir_x * a->player.speed_move;
	if (a->map[(int)a->player.pos_x][(int)(a->player.pos_y - a->player.dir_y *
				a->player.speed_move)] == 0)
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
