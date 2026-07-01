/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:55:06 by abaptist          #+#    #+#             */
/*   Updated: 2026/07/01 04:39:21 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*ft_lstnew_ps(int content)
{
	t_ps_list	*elem;

	elem = malloc(sizeof(t_ps_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*maillon;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	maillon = *lst;
	while (maillon->next != NULL)
		maillon = maillon->next;
	maillon->next = new;
}

t_ps_list	*fill_stack_a(char *argv, int argc)
{
	char		**split_result;
	int			i;
	t_ps_list	*stack_a;
	int			len_list;

	if (argc != 2 && argc != 3)
		return (NULL);
	else
	{
		split_result = ft_split(argv, ' ');
		i = 0;
		len_list = 0;
		while (split_result[len_list])
			len_list++;
		stack_a = ft_lstnew_ps(ft_atoi(split_result[i++]));
		while (i < len_list)
		{
			ft_lstadd_back_ps(&stack_a, ft_lstnew_ps(ft_atoi(split_result[i])));
			i++;
		}
		return (stack_a);
	}
}
