/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:44:09 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/10 16:14:33 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	put_error(t_env *a)
{
	ft_putstr("Error : one map ONLY required. Usage : ./wolf3d <map_file>\n");
	free(a);
	exit(0);
}

void	malloc_error(void)
{
	ft_putstr("Error : couldn't malloc\n");
	exit(0);
}

void	map_error(t_env *a)
{
	ft_putstr("Error : incorrect map\n");
	free(a);
	exit(0);
}

void	player_error(t_env *a)
{
	ft_putstr("Error : player position cannot be on a wall (1) ");
	ft_putstr("or outside the map\n");
	free(a);
	exit(0);
}

void	color_error(t_env *a)
{
	ft_putstr("Error : wrong color detected\n");
	free(a);
	exit(0);
}
