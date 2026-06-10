/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:25:04 by username          #+#    #+#             */
/*   Updated: 2026/05/06 06:33:34 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t(i) = 0;
	unsigned char *(d) = ((unsigned char *)pointer1);
	unsigned char *(e) = ((unsigned char *)pointer2);
	while (i < size)
	{
		if (d[i] > e[i])
			return (d[i] - e[i]);
		if (d[i] < e[i])
			return (d[i] - e[i]);
		i++;
	}
	return (0);
}
/*
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// My memcmp implementation
int mymemcmp( const void * pointer1, const void * pointer2, size_t size ) {
unsigned long position;
for( position=0; position<size; ++position ) {
int delta = *(unsigned char *)pointer1++ - *(unsigned char *)pointer2++;
if ( delta ) return delta;
}
return 0;
}

int main() {

int array1 [] = { 54, 85, 20, 63, 21 };
int array2 [] = { 54, 85, 19, 63, 21 };
size_t size = sizeof( int ) * 5;

assert( memcmp( array1, array2, size) == ft_memcmp( array1, array2, size) );
assert( memcmp( array1, array1, size) == ft_memcmp( array1, array1, size) );
assert( memcmp( array2, array1, size) == ft_memcmp( array2, array1, size) );

printf( "Test is ok\n" );

return 0;
}
*/
