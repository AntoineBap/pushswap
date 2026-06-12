/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:45:53 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/12 09:54:53 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*first_node;

	maillon = *stack;
	first_node = maillon;
	maillon = maillon->next;
	first_node->next = maillon->next;
	maillon->next = first_node;
	*stack = maillon;
}

void	sa(t_ps_list **stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_ps_list **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}
