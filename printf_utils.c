/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:40:23 by marvin            #+#    #+#             */
/*   Updated: 2022/05/11 16:36:35 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	long int	aux;
	char		caux[12];
	int			i;
	int			count;

	caux[0] = '0';
	aux = n;
	i = 0;
	count = 0;
	if (aux < 0 && ++count)
	{
		aux *= -1;
		write(1, "-", 1);
	}
	while (aux > 9)
	{
		caux[i++] = (aux % 10) + '0';
		aux = aux / 10;
	}
	caux[i] = (aux % 10) + '0';
	caux[++i] = '\0';
	count += i;
	while (0 < i--)
		write(1, &caux[i], 1);
	return (count);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putunsignedint(unsigned int num)
{
	long int	aux;
	char		caux[12];
	int			i;
	int			count;

	caux[0] = '0';
	aux = num;
	i = 0;
	while (aux > 9)
	{
		caux[i++] = (aux % 10) + '0';
		aux = aux / 10;
	}
	caux[i] = (aux % 10) + '0';
	caux[++i] = '\0';
	count = i;
	while (0 < i--)
		write(1, &caux[i], 1);
	return (count);
}

void	ft_puthexa(unsigned long int num, const char format)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (num >= 16)
	{
		ft_puthexa(num / 16, format);
		ft_puthexa(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}
