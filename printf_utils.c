/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:40:23 by marvin            #+#    #+#             */
/*   Updated: 2022/05/05 16:40:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	long int	aux;
	char		caux[12];
	ssize_t		i;
	int	count;

	caux[0] = '0';
	aux = n;
	i = 0;
	if (aux < 0)
	{
		aux *= -1;
		write(1, "-", 1);
	}
	while (aux > 9)
	{
		caux[i] = (aux % 10) + '0';
		aux = aux / 10;
		i++;
	}
	caux[i] = (aux % 10) + '0';
	i++;
	caux[i] = '\0';
	count = i;
	while (0 < i--)
		write(1, &caux[i], 1);
	return (count);
}