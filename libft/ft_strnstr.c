/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:19:13 by schoisi           #+#    #+#             */
/*   Updated: 2026/04/25 18:55:10 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t (i) = 0;
	size_t (j) = 0;
	if (!little[0])
		return ((char *) big);
	while (big[i] && i < len)
	{
		if (little[j] == big[i])
		{
			while ((i + j) < len && little[j] == big[i + j])
			{
				if (!little[j + 1])
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int main (void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "h";
	char *ptr;
	char *ptr2;

	ptr = strstr(largestring, smallstring);
	ptr2 = ft_strnstr(largestring, smallstring, 11);
	printf("%s\n",ptr);
	printf("------------------\n");
	printf("%s\n",ptr2);

}
*/
