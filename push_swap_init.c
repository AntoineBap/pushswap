/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:55:06 by abaptist          #+#    #+#             */
/*   Updated: 2026/07/02 10:10:53 by schoisi          ###   ########.fr       */
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

t_ps_list *fill_stack_a(char **argv, int argc)
{
    t_ps_list *(stack_a) = NULL;
    int (i) = 1;

    while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
        i++;
    while (i < argc)
    {
        ft_lstadd_back_ps(&stack_a, ft_lstnew_ps(ft_atoi(argv[i])));
        i++;
    }
    return (stack_a);
}

void	print_stack(t_ps_list **lst) // a supp
{
	t_ps_list *actual_node = *lst;
	while (actual_node != NULL)
	{
		ft_printf("%d\n",actual_node->content);
		actual_node = actual_node->next;
	}
	ft_printf("--------------------------\n");
}
