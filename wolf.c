/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:33:55 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/03 16:56:26 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define mapWidth 24
#define mapHeight 24
#include "minilibx/mlx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		worldmap[24][24] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void	apply_color(int red, int blue, int green, char *str)
{
	if (!strcmp(str, "black"))
	{
		red = 255;
		green = 255;
		blue = 255;
	}
	else
		exit(1);
}

void	fill_pixel(int x, char *str)
{
	int i;
	int j;
	int red;
	int green;
	int blue;

	i = 0 + (4 * x);
	apply_color(red, blue, green, "black");
	str[i] = blue;
	str[i + 1] = green;
	str[i + 2] = red;
}

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(int argc, char **argv)
{
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;

	int screenW = 384;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 512, screenW, "wolf");
	int bpp, size_line, endien = 0;
	void *img = mlx_new_image(mlx, 512, 384);
	char *data = mlx_get_data_addr(img, &bpp, &size_line, &endien);

	double time = 0, oldTime = 0;
	int x = 0;
	while (x < 512)
	{
		double cameraX = 2 * x / (double)screenW - 1;
		double rayPosX = posX;
		double rayPosY = posY;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int)rayPosX;
		int mapY = (int)rayPosY;
		printf("mapX = %d, mapY = %d\n", mapX, mapY);

		double sideDistX;
		double sideDistY;

		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepX = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepX = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldmap[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - rayPosY+ (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(512 / perpWallDist);

		int drawStart = -lineHeight / 2 + 384 / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + 384 / 2;
		if (drawEnd >= 384)
			drawStart = 384 - 1;
		fill_pixel(x, data);
		printf("x = %d\n", x);
		x++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, key_hook, win);
	mlx_loop(mlx);
	return (0);
}
