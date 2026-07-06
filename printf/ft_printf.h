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

int		ft_printf(int fd, const char *format, ...);
int		ft_printf_strwrt(int fd, char *str);
int		ft_printf_putchar(int fd, char c);
int		ft_printf_findtype(int fd, const char format, va_list *args);
int		ft_print_putnbr(int fd, int nb);
int		ft_printf_putchar_unsigned(int fd, unsigned int nb);
int		ft_print_hexa_up(int fd, unsigned int nb);
int		ft_print_hexa_low(int fd, unsigned int nb);
int		ft_print_void(int fd, void *args);
int		ft_print_float(int fd, float nb, int precision);

#endif