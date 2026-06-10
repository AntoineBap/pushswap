/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 03:44:53 by marvin            #+#    #+#             */
/*   Updated: 2026/05/04 03:44:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int (i) = 0;
	t_list *(track) = lst;
	if (lst == NULL)
		return (0);
	while (track->next != NULL)
	{
		track = track->next;
		i++;
	}
	return (i + 1);
}
