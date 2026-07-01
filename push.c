/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaptist <abaptist@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-10 11:49:14 by abaptist          #+#    #+#             */
/*   Updated: 2026-06-10 11:49:14 by abaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	pa(t_ps_list **stack_a, t_ps_list **stack_b, int *count)
{
	t_ps_list	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
	(*count)++;
	printf("pa\n");
}

void	pb(t_ps_list **stack_b, t_ps_list **stack_a, int *count)
{
	t_ps_list	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
	(*count)++;
	printf("pb\n");
}
