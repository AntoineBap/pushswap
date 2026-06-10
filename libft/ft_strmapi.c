/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:49:08 by marvin            #+#    #+#             */
/*   Updated: 2026/04/26 18:49:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *(newstr) = malloc(sizeof(char) * (ft_strlen(s) + 1));
	int (i) = -1;
	if (!newstr)
		return (NULL);
	while (s[++i])
		newstr[i] = (*f)(i, s[i]);
	return (newstr);
}
