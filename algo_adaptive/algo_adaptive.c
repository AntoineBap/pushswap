/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:55:20 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/26 02:56:37 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_algo(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx)
{
	float	disorder;

	disorder = compute_disorder(stack_a);
	if (disorder < 0.2)
		algo_simple_ps(stack_a, stack_b, ctx);
	else if (disorder >= 0.2 && disorder < 0.5)
		greedy_sort(stack_a, stack_b, ctx); // a changer par l'algo medium
	if (disorder >= 0.5)
		greedy_sort(stack_a, stack_b, ctx);
}
