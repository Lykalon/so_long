/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:37 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:28:37 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_mlx_data *g)
{
	mlx_clear_window(g->mlx, g->wnd);
	map_render(g);
	events(g);
	player_moving(g);
	mlx_string_put(g->mlx, g->wnd, 32, g->y_w - 32, g->color, g->str_score);
	return (0);
}

int	key_hook(int key, t_mlx_data *g)
{
	if (key == 53)
	{
		mlx_destroy_window(g->mlx, g->wnd);
		exit(0);
	}
	if (!g->moving)
	{
		if (key == 13 || key == 0 || key == 1 || key == 2)
		{
			g->moves = g->moves + 1;
			refresh_str(g);
			set_direction(key, g);
			write(1, g->str_score, ft_strlen(g->str_score));
			write(1, "\n", 1);
		}
	}
	return (0);
}

int	ext(t_mlx_data *g)
{
	mlx_destroy_window(g->mlx, g->wnd);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	g;

	if (argc == 2)
	{
		check_extension(argv[1]);
		g.mlx = mlx_init();
		set_game(&g);
		map_init(&g, argv[1]);
		g.wnd = mlx_new_window(g.mlx, g.x_w, g.y_w, "Ded loves mora");
		mlx_hook(g.wnd, 3, 0, key_hook, &g);
		mlx_hook(g.wnd, 17, 0, ext, &g);
		mlx_loop_hook(g.mlx, render, &g);
		mlx_loop(g.mlx);
		exit (0);
	}
	else
		write(1, "USAGE: app \"dest_to_map.ber\"\n", 29);
}

/*
 * comp flags cc -lmlx -framework OpenGL -framework AppKit *.c -o app
 *
 * map checker
 * 	- read subject
 * map parser
 * 	- gnl?
 * need pics (player, collectable, wall, closed door, opened door and space)
 * free for ptr's?
 * 	- maybe exit only?
 * some valid maps (*.ber)
 * some error maps
 */