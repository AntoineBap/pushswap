/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:01:41 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 21:01:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list (args);
	va_start(args, format);
	int (i) = 0;
	int (somme) = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			somme = somme + ft_printf_findtype(format[i + 1], &args);
			i++;
		}
		else
		{
			ft_printf_putchar(format[i]);
			somme++;
		}
		i++;
	}
	va_end(args);
	return (somme);
}

/*

int	main(int argc, char *argv[])
{
	argc--;
	int popo = atoi(argv[argc]);
	ft_printf("caca %p\n", &popo);
}

*/

/*
//#include <stdio.h>

int main( int argc, char * argv[] ) {
    
    FILE * inputFile;
    
    argc--;   argv++;
    
    if ( argc == 0 ) {
        printf( "Usage: sample filename...\n" );
        exit( 0 );
    }
    
    inputFile = fopen( argv[0], "a" );
    if ( inputFile == NULL ) {
        fprintf( stderr, "Cannot open file %s\n", argv[0] );
        exit( 0 );
    }
    
    fprintf( inputFile, "Appending a new message in the file\n" );

    fclose( inputFile );
        
    return 0;

}*/
