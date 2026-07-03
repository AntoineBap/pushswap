/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:04:32 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 21:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# pragma once
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printf_strwrt(char *str);
int		ft_printf_putchar(char c);
int		ft_printf_findtype(const char format, va_list *args);
int		ft_print_putnbr(int nb);
int		ft_printf_putchar_unsigned(unsigned int nb);
int		ft_print_hexa_up(unsigned int nb);
int		ft_print_hexa_low(unsigned int nb);
int		ft_print_void(void *args);
int		ft_print_float(float nb, int precision);

#endif