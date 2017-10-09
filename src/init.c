/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:44:19 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 21:03:17 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	init_player(t_env *a)
{
	a->player.pos_x = 0;
	a->player.pos_y = 0;
	a->player.dir_x = -1;
	a->player.dir_y = 0;
	a->player.plane_x = 0;
	a->player.plane_y = 0.66;
	a->player.speed_move = 0.07;
	a->player.speed_turn = 0.07;
}

t_env	*init_env(void)
{
	t_env *a;

	a = (t_env *)malloc(sizeof(t_env));
	if (!a)
		malloc_error();
	a->width = WIDTH;
	a->height = HEIGHT;
	init_player(a);
	return (a);
}
