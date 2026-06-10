/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:17:27 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/04 18:21:29 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	t_list *(pnode) = *lst;
	t_list *(temp_pnode) = pnode;
	while (pnode)
	{
		temp_pnode = pnode->next;
		del(pnode->content);
		free(pnode);
		pnode = temp_pnode;
	}
	*lst = NULL;
}
