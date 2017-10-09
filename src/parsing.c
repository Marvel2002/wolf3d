/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:44:50 by mmatime           #+#    #+#             */
/*   Updated: 2017/10/09 18:43:02 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	parse_position(int fd, t_env *a)
{
	char	*line;
	char	**line_split;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) < 1)
		put_error(a);
	line_split = ft_strsplit(line, ' ');
	while (line_split[i])
		i++;
	if (i != 4)
		map_error(a);
	a->map_width = ft_atoi(line_split[0]);
	a->map_height = ft_atoi(line_split[1]);
	a->player.pos_y = ft_atoi(line_split[2]) + 0.5;
	a->player.pos_x = ft_atoi(line_split[3]) + 0.5;
	if (a->map_width < 0 || a->map_height < 0 || a->player.pos_x < 0 ||
			a->player.pos_y < 0 || a->player.pos_x >= a->map_height ||
			a->player.pos_y >= a->map_width)
		map_error(a);
}

void	parse_line(char *line, int y, int **map, t_env *a)
{
	int		x;
	char	**line_split;

	x = 0;
	if (y >= a->map_height)
		map_error(a);
	line_split = ft_strsplit(line, ' ');
	map[y] = (int *)malloc(sizeof(int *) * a->map_width);
	while (line_split[x])
	{
		if (!(line_split[x][0] >= '0' && line_split[x][0] <= '9' &&
					ft_atoi(line_split[x]) >= 0 && x < a->map_width))
			map_error(a);
		map[y][x] = ft_atoi(line_split[x]);
		if ((x == 0 || x == a->map_width - 1 || y == 0 ||
					y == a->map_height - 1) && map[y][x] == 0)
			map_error(a);
		x++;
	}
	if (x != a->map_width)
		map_error(a);
}

int		parse_file(int fd, t_env *a)
{
	char	*line;
	int		y;
	int		**map;

	y = 0;
	parse_position(fd, a);
	map = (int **)malloc(sizeof(int **) * a->map_height);
	while (get_next_line(fd, &line) == 1)
	{
		parse_line(line, y, map, a);
		y++;
	}
	if (map[(int)a->player.pos_x][(int)a->player.pos_y] != 0)
		player_error(a);
	a->map = map;
	return (1);
}

int		file_open(t_env *a, char *argv)
{
	int fd;

	fd = open(argv, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	return (parse_file(fd, a));
}

void	wolf_init(t_env *a, int argc, char **argv)
{
	if (argc != 2)
		put_error(a);
	if (!file_open(a, argv[1]))
		map_error(a);
}
