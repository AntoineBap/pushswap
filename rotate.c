/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaptist <abaptist@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-10 11:47:09 by abaptist          #+#    #+#             */
/*   Updated: 2026-06-10 11:47:09 by abaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*first_node;

	maillon = *stack;
	first_node = *stack;

	while (maillon->next != NULL)
		maillon = maillon->next;
	*stack = first_node->next;
	maillon->next = first_node;
	first_node->next = NULL;
}

void	ra(t_ps_list **stack_a)
{
	rotate(stack_a);
}

void	rb(t_ps_list **stack_b)
{
	rotate(stack_b);
}

void	rr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
