/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:52 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:28:52 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_line(t_mlx_data *g, char *line, int y)
{
	int	x;
	int	collect;

	collect = 0;
	x = 0;
	y *= 64;
	while (line[x] && line[x] != '\n')
	{
		mlx_put_image_to_window(g->mlx, g->wnd, g->s, x * 64, y);
		if (line[x] == '1')
		{
			mlx_put_image_to_window(g->mlx, g->wnd, g->wl, x * 64, y);
		}
		else if (line[x] == 'C')
		{
			collect += 1;
			mlx_put_image_to_window(g->mlx, g->wnd, g->c, x * 64, y);
		}
		else if (line[x] == 'E')
			mlx_put_image_to_window(g->mlx, g->wnd, g->door, x * 64, y);
		++x;
	}
	return (collect);
}

void	map_render(t_mlx_data *g)
{
	t_map	*map;
	int		line;
	int		collect;

	collect = 0;
	map = g->map;
	line = 0;
	while (map)
	{
		collect += set_line(g, map->line, line);
		line += 1;
		map = map->next;
	}
	if (!collect)
		g->door = g->d_o;
	mlx_put_image_to_window(g->mlx, g->wnd, g->p, g->x_plr, g->y_plr);
}
