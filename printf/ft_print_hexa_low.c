/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 20:26:44 by schoisi           #+#    #+#             */
/*   Updated: 2026/07/01 08:01:35 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_low(unsigned int nb)
{
	char			*digits;
	char			buffer[9];
	int				i;
	int				count;

	digits = "0123456789abcdef";
	i = 8;
	buffer[i] = '\0';
	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb > 0)
	{
		buffer[--i] = digits[nb % 16];
		nb = nb / 16;
		(*count)++;
	}
	write(1, &buffer[i], count);
	return (count);
}
