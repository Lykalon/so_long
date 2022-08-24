/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:27:43 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:27:43 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game(t_mlx_data *g)
{
	g->p = mlx_xpm_file_to_image(g->mlx, "img/player.xpm", &g->w, &g->h);
	g->c = mlx_xpm_file_to_image(g->mlx, "img/collect.xpm", &g->w, &g->h);
	g->wl = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &g->w, &g->h);
	g->d_c = mlx_xpm_file_to_image(g->mlx, "img/door_c.xpm", &g->w, &g->h);
	g->d_o = mlx_xpm_file_to_image(g->mlx, "img/door_o.xpm", &g->w, &g->h);
	g->door = g->d_c;
	g->s = mlx_xpm_file_to_image(g->mlx, "img/space.xpm", &g->w, &g->h);
	g->moves = 0;
	g->moving = 0;
	g->color = 0xFFFFFF;
	g->str_score = NULL;
	refresh_str(g);
	g->map = NULL;
	g->mod_x = 0;
	g->mod_y = 0;
}
