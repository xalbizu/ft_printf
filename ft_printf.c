/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:08:28 by marvin            #+#    #+#             */
/*   Updated: 2022/05/05 16:08:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int checkargs(char c, va_list args)
{
    int count;

    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(args, int));
	else if (c == 'd')
        count += ft_putnbr(va_arg(args, int));
        
    return (count);
}

int ft_printf(char const *str, ...)
{
    va_list args;
    int     i;
    int     count;

    va_start(args, str);
    count = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            count += checkargs(str[i + 1] , args);
            i += 2;
        }
        else
		{
			count += ft_putchar(str[i]);
        	i++;
		}
    }
	va_end(args);
    return (count);
}

int main(void)
{
    ft_printf("El numero%c %d",':', 1235);
}
