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

int hexa(unsigned int num, const char format)
{
	int	len;
    unsigned int    aux;

    if (num == 0)
    {
        ft_puthexa(num, format);
        return (1);
    }
    aux = num;
	len = 0;
	while (aux != 0)
	{
		len++;
		aux = aux / 16;
	}
    ft_puthexa(num, format);
	return (len);
}

int putptr(unsigned int num)
{
    int cont;

    cont = 0;
    cont += ft_putstr("0x");
    cont += hexa(num,'x');
    return (cont);
}

int checkargs(char c, va_list args)
{
    int count;

    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(args, int));
	else if (c == 'd' || c == 'i')
        count += ft_putnbr(va_arg(args, int));
	else if (c == 's')
    	count += ft_putstr(va_arg(args, char *));
    else if (c == 'u') /*-----PROBAR NEGATIVOS, EN CASA DAN COSAS RARAS-----*/
    	count += ft_putunsignedint(va_arg(args, unsigned int));
    else if (c == '%')
        count += ft_putchar('%');
    else if (c == 'x' || c == 'X')
        count += hexa(va_arg(args, unsigned int), c);
        else if (c == 'p')
        count += putptr(va_arg(args, unsigned int));
        
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
            count += checkargs(str[i + 1], args);
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
printf("%d\n",ft_printf("%p", "hola"));
printf("%d\n",printf("%p", "hola"));
}
