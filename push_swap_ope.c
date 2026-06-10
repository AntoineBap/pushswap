/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ope.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:28:48 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/10 15:05:50 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_ps_list *stack_a, t_ps_list *stack_b)
{
	ft_lstadd_front_ps(&stack_a, stack_b);
}

void	push_b(t_ps_list *stack_b, t_ps_list *stack_a)
{
	ft_lstadd_front_ps(&stack_b, stack_a);
}

void	rotate_a(t_ps_list **stack_a)
{
	t_ps_list	*maillon;
	t_ps_list	*first_node;

	maillon = *stack_a;
	first_node = *stack_a;

	while (maillon->next != NULL)
		maillon = maillon->next;
	*stack_a = first_node->next;
	maillon->next = first_node;
	first_node->next = NULL;
}

void	rotate_b(t_ps_list **stack_b)
{
	t_ps_list	*maillon;
	t_ps_list	*first_node;

	maillon = *stack_b;
	first_node = *stack_b;

	while (maillon->next != NULL)
		maillon = maillon->next;
	*stack_b = first_node->next;
	maillon->next = first_node;
	first_node->next = NULL;
}

