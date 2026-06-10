/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:34:49 by schoisi           #+#    #+#             */
/*   Updated: 2026/04/25 07:16:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126) || (c >= 10 && c <= 13))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	printf("\a");
	printf("%d\n",ft_isprint(argv[1][0]));
}
*/