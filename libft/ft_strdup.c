/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:18:55 by marvin            #+#    #+#             */
/*   Updated: 2026/04/24 17:18:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*newstring;

	i = 0;
	while (s[i])
		i++;
	newstring = malloc(sizeof(char) * i + 1);
	if (!newstring)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstring[i] = s[i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

/*

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%s",ft_strdup(argv[1]));
}
*/