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

# define WIDTH 512
# define HEIGHT 384

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int 		size_line;
	int			endien;
	int			blue;
	int			red;
	int 		green;
	int			z;
}				t_env;
