/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:13:26 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/10 04:29:10 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_putnbr(int fd, int nb)
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
		write(fd, "-", 1);
		n *= -1;
		score++;
	}
	while ((n / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		c = ((n / div) % 10) + '0';
		write(fd, &c, 1);
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
		count++;
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