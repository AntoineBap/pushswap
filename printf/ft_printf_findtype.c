/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:05:56 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 22:05:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_findtype(const char format, va_list *args)
{
	int (score) = 0;
	if (format == 'c')
		score = ft_printf_putchar(va_arg(*args, int));
	if (format == 's')
		score = ft_printf_strwrt(va_arg(*args, char *));
	if (format == '%')
		score = ft_printf_putchar('%');
	if (format == 'd')
		score = ft_print_putnbr(va_arg(*args, int));
	if (format == 'i')
		score = ft_print_putnbr(va_arg(*args, int));
	if (format == 'u')
		score = ft_printf_putchar_unsigned(va_arg(*args, unsigned int));
	if (format == 'x')
		score = ft_print_hexa_low(va_arg(*args, int));
	if (format == 'X')
		score = ft_print_hexa_up(va_arg(*args, int));
	if (format == 'p')
		score = ft_print_void(va_arg(*args, void *));
	return (score);
}

