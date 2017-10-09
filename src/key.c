/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:23:56 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 19:46:11 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		key_hook(int keycode, t_env *a)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
		move_up(a);
	if (keycode == 125)
		move_down(a);
	if (keycode == 123)
		move_left(a);
	if (keycode == 124)
		move_right(a);
	raycasting(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	return (0);
}

int		close_hook(t_env *a)
{
	free(a);
	exit(1);
	return (0);
}

int		expose_hook(t_env *a)
{
	raycasting(a);
	return (0);
}
