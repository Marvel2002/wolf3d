/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:17:14 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/05 14:53:16 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct p_env
{
	int c;
}				y_env;

typedef struct x_env
{
	int b;
	struct p_env rofl;
}			r_env;

typedef struct s_env
{
	int a;
	struct x_env lol;
}			t_env;

int		main(void)
{
	t_env *mdr;

	mdr = malloc(sizeof(*mdr));
	mdr->a = 10;
	mdr->lol.b = 15;
	mdr->lol.rofl.c = 20;
	clock_t b = clock();
	printf("a = %d, b = %d, c = %d\n", mdr->a, mdr->lol.b, mdr->lol.rofl.c);
	mdr->lol.rofl.c++;
	printf("a = %d, b = %d, c = %d\n", mdr->a, mdr->lol.b, mdr->lol.rofl.c);
	printf("clock = %lu\n", b);
	return (0);
}
