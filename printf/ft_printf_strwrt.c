/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:28:23 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 21:28:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_strwrt(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (i);
	while (str[i])
		i++;
	if (write(fd, str, i) == -1)
		return (-1);
	return (i);
}
