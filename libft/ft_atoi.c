/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:48:35 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/06 07:45:48 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int (i) = 0;
	int (sign) = 1;
	int (result) = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char * argv[] ) {
     
    if ( argc == 1 ) {
        printf( "Usage: %s intValue ...\n", argv[0] );
        exit( EXIT_SUCCESS );
    }

    argc--;   argv++;

    int sum = 0;

    while ( argc != 0 ) {

		sum += ft_atoi(*argv++);
		argc--;

    }

    printf( "La somme des valeurs saisies est de %d.\n", sum );

    return EXIT_SUCCESS;
}
*/