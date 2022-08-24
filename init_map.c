/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:27:52 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:27:52 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_item(char *line, char item)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (line[x])
	{
		if (line[x] == item)
			++count;
		++x;
	}
	return (count);
}

static int	find_player(char *line)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (line[x] == 'P')
			return (x);
		++x;
	}
	return (0);
}

void	set_player_coord(t_mlx_data *g)
{
	int		x;
	int		y;
	t_map	*temp;

	temp = g->map;
	x = 0;
	y = -1;
	while (!x)
	{
		x = find_player(temp->line);
		temp = temp->next;
		++y;
	}
	g->x_plr = x * 64;
	g->y_plr = y * 64;
}

void	set_window_size(t_mlx_data *g)
{
	g->y_w = list_count(g->map) * 64 + 64;
	g->x_w = ft_strlen_no_nl(g->map->line) * 64;
}

void	map_init(t_mlx_data *g, char *map_dest)
{
	t_map	*last;
	int		fd;
	char	*line;

	fd = open(map_dest, O_RDONLY);
	if (fd == -1)
		rise_wrong_path();
	line = get_next_line(fd);
	while (line)
	{
		if (!g->map)
			g->map = list_new(line);
		else
		{
			last = list_last(g->map);
			last->next = list_new(line);
		}
		line = get_next_line(fd);
	}
	close(fd);
	check_map(g->map);
	set_window_size(g);
	set_player_coord(g);
}
