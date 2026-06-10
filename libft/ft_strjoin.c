/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:17:47 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/06 06:42:58 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t (i) = 0;
	size_t (j) = 0;
	if (!s1 || !s2)
		return (NULL);
	size_t (maxlen) = (ft_strlen(s1) + ft_strlen(s2));
	char *(newstr) = malloc(sizeof(char) * maxlen + 1);
	if (!newstr)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}
