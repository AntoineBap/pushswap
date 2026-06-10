/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:27:10 by marvin            #+#    #+#             */
/*   Updated: 2026/04/24 13:27:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t (i) = 0;
	void *(tab) = malloc(elementSize * elementCount);
	if (!tab)
		return (NULL);
	if (elementSize != 0 && elementCount > (65535 / elementSize))
		return (NULL);
	while (i < elementCount * elementSize)
	{
		((unsigned char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}

/*

#include <stdio.h>          
#include <stdlib.h>
#include <assert.h>

#define INT_NUMBER 10

int main() {
    
    int i;
    int * pointer = (int *) calloc( INT_NUMBER, sizeof(int) );

    assert( pointer != NULL );

    for ( i=0; i<INT_NUMBER-1; i++ ) {
        pointer[i] = i;
    }

    for (i=0; i<INT_NUMBER; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );

    free( pointer );

    return 0;
}

*/