/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:19:52 by marvin            #+#    #+#             */
/*   Updated: 2026/04/26 20:19:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	long	div;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	div = 1;
	while (nb / div >= 10)
		div *= 10;
	while (div > 0)
	{
		c = (nb / div) + '0';
		write(fd, &c, 1);
		nb %= div;
		div /= 10;
	}
}
