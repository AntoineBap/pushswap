/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaptist <abaptist@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-10 11:43:54 by abaptist          #+#    #+#             */
/*   Updated: 2026-06-10 11:43:54 by abaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	reverse_rotate(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*last_node;

	maillon = *stack;
	while (maillon->next->next != NULL)
		maillon = maillon->next;
	last_node = maillon->next;
	maillon->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	rra(t_ps_list **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_ps_list **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
