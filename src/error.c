/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:44:09 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 19:00:21 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	put_error(t_env *a)
{
	ft_putendl("Error : one map ONLY required. Usage : ./wolf3d <map_file>");
	free(a);
	exit(1);
}

void	malloc_error(void)
{
	ft_putendl("Error : couldn't malloc");
	exit(1);
}

void	map_error(t_env *a)
{
	ft_putendl("Error : incorrect map");
	free(a);
	exit(1);
}

void	player_error(t_env *a)
{
	ft_putstr("Error : player position cannot be on a wall (1) ");
	ft_putendl("or outside the map");
	free(a);
	exit(1);
}

void	color_error(t_env *a)
{
	ft_putendl("Error : wrong color detected");
	free(a);
	exit(1);
}
