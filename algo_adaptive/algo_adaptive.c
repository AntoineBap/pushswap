/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaptist <abaptist@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-17 10:55:20 by abaptist          #+#    #+#             */
/*   Updated: 2026-06-17 10:55:20 by abaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_algo(t_ps_list **stack_a, t_ps_list **stack_b, int *count)
{
	float	disorder;

	disorder = compute_disorder(stack_a);
	if (disorder < 0.2)
		algo_simple_ps(stack_a, stack_b, count);
	else if (disorder >= 0.2 && disorder < 0.5)
		greedy_sort(stack_a, stack_b, count);
	if (disorder >= 0.5)
		greedy_sort(stack_a, stack_b, count);
}
