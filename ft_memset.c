/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:19:48 by lykalon           #+#    #+#             */
/*   Updated: 2021/10/07 18:19:48 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_memset(void *buffer, int c, size_t len)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = buffer;
	while (i < len)
	{
		new[i] = c;
		++i;
	}
}
