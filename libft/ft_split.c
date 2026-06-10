/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 03:38:01 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/06 08:04:47 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

int	count_words(char const *str, char charset)
{
	int (i) = 0;
	int (count) = 0;
	while (str[i])
	{
		if (check_charset(str[i], charset)
			&& str[i + 1]
			&& !check_charset(str[i + 1], charset))
			count++;
		i++;
	}
	if (str[0] && !check_charset(str[0], charset))
		count++;
	return (count);
}

char	**create_big_tab(char const *str, char charset)
{
	int		count;
	char	**big_tab;

	count = count_words(str, charset);
	big_tab = malloc(sizeof(char *) * (count + 1));
	if (!big_tab)
		return (NULL);
	big_tab[count] = NULL;
	return (big_tab);
}

char	*create_little_tab(char const *str, int start, int end)
{
	char *(little_tab) = malloc(sizeof(char) * (end - start + 1));
	int (i) = 0;
	if (!little_tab)
		return (NULL);
	while (start < end)
		little_tab[i++] = str[start++];
	little_tab[i] = '\0';
	return (little_tab);
}

char	**ft_split(char const *s, char c)
{
	char **(big_t) = create_big_tab(s, c);
	int (index_base) = 0;
	int (index_safe) = -1;
	int (index_big) = 0;
	if (!big_t)
		return (NULL);
	while (s[index_base])
	{
		if (!check_charset(s[index_base], c) && index_safe == -1)
			index_safe = index_base;
		if (check_charset(s[index_base], c) && index_safe != -1)
		{
			big_t[index_big++] = create_little_tab(s, index_safe, index_base);
			index_safe = -1;
		}
		index_base++;
	}
	if (index_safe != -1)
		big_t[index_big++] = create_little_tab(s, index_safe, index_base);
	big_t[index_big] = NULL;
	return (big_t);
}
/*

#include <stdio.h>

void	display_array(char **tab)
{
	int	i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	main(void)
{
	char	*str = "p i p i,caca,po-po";
	char	*charset = ",- ";
	char	**res;

	res = ft_split(str, charset);
	display_array(res);
	return (0);
}
*/