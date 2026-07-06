/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 05:24:59 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/20 16:18:28 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_print_void(int fd, void *args)
{
	char (tabhexa)[] = "0123456789abcdef";
	unsigned long long (score) = 1;
	unsigned long long (index) = 1;
	uintptr_t (addr) = (uintptr_t)args;
	uintptr_t (div) = (uintptr_t)args;
	if (!args)
		return (ft_printf_strwrt(fd, "(nil)"));
	while (div >= 16)
	{
		div = div / 16;
		score++;
	}
	char *(str) = malloc(sizeof(char) * (score + 1));
	str[score] = '\0';
	index = score;
	while (index > 0)
	{
		str[--index] = tabhexa[addr % 16];
		addr = addr / 16;
	}
	ft_printf_strwrt(fd, "0x");
	ft_printf_strwrt(fd, str);
	free(str);
	return (score + 2);
}
