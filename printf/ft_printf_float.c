/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaptist <abaptist@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-03 09:14:02 by abaptist          #+#    #+#             */
/*   Updated: 2026-07-03 09:14:02 by abaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_pow10(int n)
{
	long	result;

	result = 1;
	while (n-- > 0)
		result = result * 10;
	return (result);
}

static int	ft_putnbr_long(long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = count + ft_putnbr_long(n / 10);
	count = count + ft_printf_putchar('0' + n % 10);
	return (count);
}

static int	ft_putnbr_pad(long n, int precision)
{
	long	tmp;
	int		digits;
	int		count;

	count = 0;
	digits = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		digits++;
	}
	while (digits++ < precision)
		count = count + ft_printf_putchar('0');
	count = count + ft_putnbr_long(n);
	return (count);
}

int	ft_print_float(float nb, int precision)
{
	long	scale;
	long	value;
	int		count;

	count = 0;
	if (precision <= 0)
		precision = 2;
	if (nb < 0)
	{
		count = count + ft_printf_putchar('-');
		nb = -nb;
	}
	scale = ft_pow10(precision);
	value = (long)(nb * (double)scale + 0.5);
	count = count + ft_putnbr_long(value / scale);
	count = count + ft_printf_putchar('.');
	count = count + ft_putnbr_pad(value % scale, precision);
	return (count);
}
