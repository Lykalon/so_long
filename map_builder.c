/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:00 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:28:00 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_no_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

t_map	*list_new(char *line)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	new->next = NULL;
	new->line = line;
	return (new);
}

t_map	*list_last(t_map *map)
{
	t_map	*temp;

	if (!map)
		return (NULL);
	temp = map;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	list_count(t_map *first)
{
	t_map	*temp;
	int		count;

	temp = first;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		++count;
	}
	return (count);
}
