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

void	push(t_ps_list **receiver_stack, t_ps_list *giver_stack)
{
	giver_stack->next = *receiver_stack;
	*receiver_stack = giver_stack;
}

void	pa(t_ps_list *stack_a, t_ps_list *stack_b)
{
	push(&stack_a, stack_b);
}

void	pb(t_ps_list *stack_b, t_ps_list *stack_a)
{
	push(&stack_b, stack_a);
}
