/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:26:57 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:26:57 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_door(t_mlx_data *g, int x, int y)
{
	t_map	*map;
	char	*up;

	if (g->moving == 2)
	{
		map = g->map;
		while (y > 0)
		{
			up = map->line;
			map = map->next;
			--y;
		}
		if (((g->mod_y < 0 && up[x] == 'E') || (g->mod_y > 0
					&& map->next->line[x] == 'E') || (g->mod_x < 0
					&& map->line[x - 1] == 'E') || (g->mod_x > 0
					&& map->line[x + 1] == 'E')) && (g->door == g->d_c))
		{
			g->mod_x = 0;
			g->mod_y = 0;
			g->moving = 0;
		}
		else
			g->moving = 3;
	}
}

void	check_for_wall(t_mlx_data *g, int x, int y)
{
	t_map	*map;
	char	*up;

	if (g->moving == 1)
	{
		map = g->map;
		while (y > 0)
		{
			up = map->line;
			map = map->next;
			--y;
		}
		if ((g->mod_y < 0 && up[x] == '1') || (g->mod_y > 0
				&& map->next->line[x] == '1') || (g->mod_x < 0
				&& map->line[x - 1] == '1') || (g->mod_x > 0
				&& map->line[x + 1] == '1'))
		{
			g->mod_x = 0;
			g->mod_y = 0;
			g->moving = 0;
		}
		else
			g->moving = 2;
	}
}

void	check_for_exit(t_mlx_data *g, int x, int y)
{
	t_map	*map;

	if (g->moving == 0)
	{
		map = g->map;
		while (y > 0)
		{
			map = map->next;
			--y;
		}
		if (map->line[x] == 'E')
		{
			mlx_destroy_window(g->mlx, g->wnd);
			exit(0);
		}
	}
}

void	check_collectable(t_mlx_data *g, int x, int y)
{
	t_map	*map;

	if (g->moving == 0)
	{
		map = g->map;
		while (y > 0)
		{
			map = map->next;
			--y;
		}
		if (map->line[x] == 'C')
			map->line[x] = '0';
	}
}

void	events(t_mlx_data *g)
{
	int		x;
	int		y;

	x = g->x_plr / 64;
	y = g->y_plr / 64;
	check_collectable(g, x, y);
	if (g->moving != 2)
		check_for_wall(g, x, y);
	if (g->moving != 3)
		check_for_door(g, x, y);
	check_for_exit(g, x, y);
}
