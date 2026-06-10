/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:41:37 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 21:41:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar_unsigned(unsigned int nb)
{
	unsigned long	n;
	int				div;
	int				score;
	char			c;

	n = nb;
	div = 1;
	score = 0;
	if (n == 0)
	{
		c = ((n / div) % 10) + '0';
		write(1, &c, 1);
		return (++score);
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
