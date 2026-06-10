/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:36:55 by schoisi           #+#    #+#             */
/*   Updated: 2026/05/05 18:05:30 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *(newlst);
	t_list *(newnode);
	t_list *(last);
	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	last = NULL;
	while (lst)
	{
		newnode = malloc(sizeof(t_list));
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		newnode->next = NULL;
		if (!newlst)
			newlst = newnode;
		else
			last->next = newnode;
		last = newnode;
		lst = lst->next;
	}
	return (newlst);
}
