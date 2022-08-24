/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:07 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:28:07 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all(t_map *map)
{
	t_map	*temp;
	int		count;

	temp = map;
	while (temp != NULL)
	{
		count = 0;
		count += count_item(temp->line, '1');
		count += count_item(temp->line, '0');
		count += count_item(temp->line, 'P');
		count += count_item(temp->line, 'C');
		count += count_item(temp->line, 'E');
		if (count != ft_strlen_no_nl(temp->line))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_walls(t_map *map)
{
	t_map	*temp;
	int		last;
	char	*line;

	temp = map;
	if (ft_strlen_no_nl(temp->line) != count_item(temp->line, '1'))
		return (1);
	temp = list_last(temp);
	if (ft_strlen_no_nl(temp->line) != count_item(temp->line, '1'))
		return (1);
	temp = map;
	while (temp != NULL)
	{
		line = temp->line;
		last = ft_strlen_no_nl(line) - 1;
		if (line[0] != '1' || line[last] != '1')
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_rect(t_map *map)
{
	t_map	*temp;
	int		row;

	temp = map;
	row = ft_strlen_no_nl(temp->line);
	while (temp != NULL)
	{
		if (row != ft_strlen_no_nl(temp->line))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_basic(t_map *map)
{
	t_map	*temp;
	int		collect;
	int		start;
	int		door;

	collect = 0;
	start = 0;
	door = 0;
	temp = map;
	while (temp != NULL)
	{
		collect += count_item(temp->line, 'C');
		start += count_item(temp->line, 'P');
		door += count_item(temp->line, 'E');
		temp = temp->next;
	}
	if (collect == 0 || start != 1 || door == 0)
		return (1);
	return (0);
}

void	check_map(t_map *map)
{
	int	err;

	err = 0;
	err += check_basic(map);
	err += check_rect(map);
	err += check_walls(map);
	err += check_all(map);
	if (err != 0)
	{
		write(2, "Error\nInvalid map!\n", 19);
		exit(1);
	}
}
