/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_extension.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:16 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:28:16 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rise_wrong_path(void)
{
	write(2, "Error\nInvalid path! Maybe it's not a map!\n", 42);
	exit(1);
}

void	check_extension(char *path)
{
	int		index;
	char	*extension;
	int		i;

	i = 0;
	extension = ft_strdup(".ber");
	index = ft_strlen_no_nl(path) - 4;
	if (index < 0)
	{
		write(2, "Error\nInvalid path!\n", 20);
		exit(1);
	}
	while (i < 4)
	{
		if (path[index + i] != extension[i])
		{
			write(2, "Error\nInvalid extension!\n", 25);
			exit(1);
		}
		++i;
	}
	free(extension);
}
