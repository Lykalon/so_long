/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:19:48 by lykalon           #+#    #+#             */
/*   Updated: 2021/10/07 18:19:48 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *src)
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	len = ft_strlen(src);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
