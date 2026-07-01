/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:13:26 by schoisi           #+#    #+#             */
/*   Updated: 2026/07/01 08:01:35 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_putnbr(int nb)
{
	long	n;
	int		div;
	int		score;
	char	c;

	n = nb;
	div = 1;
	score = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		score++;
	}
	while ((n / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		c = ((n / div) % 10) + '0';
		write(1, &c, 1);
		div /= 10;
		score++;
	}
	return (score);
}
/*
{
	int (sign) = 0;
	int (count) = 1;
	char *(str);
	if (nb < 0)
	{
		nb = nb * -1;
		sign = 1;
	}
	int (calc) = nb;
	while (calc > 9)
	{
		calc = calc / 10;
		(*count)++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (sign != 0)
		ft_putchar('-');
	str[count + 1] = '\0';
	while (count > -1)
	{
		str[--count] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}*/