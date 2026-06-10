/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 01:22:22 by marvin            #+#    #+#             */
/*   Updated: 2026/05/04 01:22:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	*new->next = **lst;
	*lst = new->next;
}

/*

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new->next;
}

*/