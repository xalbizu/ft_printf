/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:25:49 by marvin            #+#    #+#             */
/*   Updated: 2022/05/05 16:25:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	digit_counter(int n);
int	exp_counter(int n);
char	*ft_itoa(int n);
int	ft_putunsignedint(unsigned int num);
void ft_puthexa(unsigned int num, const char format);
int hexa(unsigned int num, const char format);
int putptr(unsigned int num);
#endif