/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:33:55 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 19:45:46 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_command(char **argv)
{
	ft_putstr("Wolf3d is ON with ");
	ft_putendl(argv[1]);
	ft_putendl("Commands : ");
	ft_putendl("Move : Up, down, left, right");
	ft_putendl("Exit : ESC or close the window");
}

int		main(int argc, char **argv)
{
	t_env		*a;

	a = init_env();
	wolf_init(a, argc, argv);
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "Wolf3d");
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->data = mlx_get_data_addr(a->img, &a->bpp, &a->size_line, &a->endien);
	raycasting(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	ft_command(argv);
	mlx_hook(a->win, 2, 1, key_hook, a);
	mlx_hook(a->win, 17, 1, close_hook, a);
	mlx_hook(a->win, 12, 1, expose_hook, a);
	mlx_loop(a->mlx);
	return (0);
}
