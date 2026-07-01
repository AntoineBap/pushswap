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
			t_ps_list **stack_b, int *count)
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
		while (count != 0)
		{
			ra(stack_a, count);
			counter--;
		}
		pb(stack_b, stack_a, count);
	}
}

void	algo_simple_ps(t_ps_list **stack_a, t_ps_list **stack_b, int *count)
{
	if (stack_a == NULL)
		return ;
	full_b_stack_algo_simple_ps(stack_a, stack_b, count);
	while (*stack_b != NULL)
		pa(stack_a, stack_b, count);
	return ;
}
