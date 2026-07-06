/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 20:26:44 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/10 05:07:47 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_up(int fd, unsigned int nb)
{
	char			*digits;
	char			buffer[9];
	int				i;
	int				count;

	digits = "0123456789ABCDEF";
	i = 8;
	buffer[i] = '\0';
	count = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	while (nb > 0)
	{
		buffer[--i] = digits[nb % 16];
		nb = nb / 16;
		count++;
	}
	write(fd, &buffer[i], count);
	return (count);
}
