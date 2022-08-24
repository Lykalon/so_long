/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:31 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:28:31 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_direction(int key, t_mlx_data *g)
{
	if (key == 13)
		g->mod_y = -SPEED;
	else if (key == 1)
		g->mod_y = SPEED;
	else if (key == 0)
		g->mod_x = -SPEED;
	else if (key == 2)
		g->mod_x = SPEED;
	g->moving = 1;
}

void	player_moving(t_mlx_data *g)
{
	g->x_plr += g->mod_x;
	g->y_plr += g->mod_y;
	if (g->x_plr % 64 == 0)
		g->mod_x = 0;
	if (g->y_plr % 64 == 0)
		g->mod_y = 0;
	if (g->mod_x == 0 && g->mod_y == 0)
		g->moving = 0;
}
