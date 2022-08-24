/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:22:30 by lykalon           #+#    #+#             */
/*   Updated: 2021/10/08 21:05:39 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_rev_tab(char *tab, size_t size)
{
	size_t		count;
	char		temp;

	count = 0;
	while (count < (size / 2))
	{
		temp = *(tab + count);
		*(tab + count) = *(tab + size - count - 1);
		*(tab + size - count - 1) = temp;
		count++;
	}
}

static void	ft_check_negative(char *buffer, int *n, int *i, int *sign)
{
	if (*n == -2147483648)
	{
		buffer[*i] = '8';
		*n = *n / 10;
		*i = *i + 1;
	}
	if (*n < 0)
	{
		*sign = (-1);
		*n = *n * (-1);
	}
}

static void	ft_set_array(char buffer[12], int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	ft_check_negative(buffer, &n, &i, &sign);
	while (n > 9)
	{
		buffer[i] = (char)((n % 10) + 48);
		n = n / 10;
		i++;
	}
	buffer[i] = (char)(n + 48);
	i++;
	if (sign < 0)
		buffer[i] = '-';
}

char	*ft_itoa(int n)
{
	char	*result;
	char	buffer[12];

	ft_memset(buffer, 0, 12);
	ft_set_array(buffer, n);
	ft_rev_tab(buffer, ft_strlen(buffer));
	result = ft_strdup(buffer);
	return (result);
}
