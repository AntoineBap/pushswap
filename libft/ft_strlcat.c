/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:56:41 by schoisi           #+#    #+#             */
/*   Updated: 2026/04/25 18:53:47 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	fill;

	size_t (i) = 0;
	size_t (dlen) = 0;
	size_t (slen) = 0;
	while (dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (size <= dlen)
		return (size + slen);
	fill = size - dlen - 1;
	while (src[i] && i < fill)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
