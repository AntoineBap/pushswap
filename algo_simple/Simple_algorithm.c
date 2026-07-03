/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:07:45 by schoisi           #+#    #+#             */
/*   Updated: 2026/06/11 16:55:02 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	full_b_stack_algo_simple_ps(t_ps_list **stack_a,
			t_ps_list **stack_b, t_ps_context *ctx)
{
	t_ps_list *(stack_a_actual_node), *(biggest_nmb) = *stack_a;
	int (counter) = 0;
	int (iteration) = 0;
	while (*stack_a != NULL)
	{
		stack_a_actual_node = *stack_a;
		biggest_nmb = *stack_a;
		iteration = 0;
		while (stack_a_actual_node != NULL)
		{
			if (stack_a_actual_node->content < biggest_nmb->content)
			{
				biggest_nmb = stack_a_actual_node;
				counter = iteration;
			}
			stack_a_actual_node = stack_a_actual_node->next;
			iteration++;
		}
		while (counter != 0)
		{
			ra(stack_a, ctx);
			counter--;
		}
		pb(stack_b, stack_a, ctx);
	}
}

void	algo_simple_ps(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx)
{
	if (stack_a == NULL)
		return ;
	full_b_stack_algo_simple_ps(stack_a, stack_b, ctx);
	while (*stack_b != NULL)
		pa(stack_a, stack_b, ctx);
	return ;
}
