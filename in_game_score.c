/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:27:31 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:27:31 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_str(t_mlx_data *g)
{
	char		*score_str;
	char		*str_put;

	if (g->str_score != NULL)
	{
		free(g->str_score);
		g->str_score = NULL;
	}
	score_str = ft_itoa(g->moves);
	str_put = ft_strjoin("YOU'R SCORE: ", score_str);
	free(score_str);
	g->str_score = str_put;
}
