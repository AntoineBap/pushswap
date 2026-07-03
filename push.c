/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:49:14 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/26 00:40:56 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx)
{
	t_ps_list	*node;
	static int	count_pa;

	if (!*stack_b)
		return ;
	count_pa++;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
	ctx->count++;
	ctx->count_pa++;
	printf("pa\n");
}

void	pb(t_ps_list **stack_b, t_ps_list **stack_a, t_ps_context *ctx)
{
	t_ps_list	*node;
	static int	count_pb;

	if (!*stack_a)
		return ;
	count_pb++;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
	ctx->count++;
	ctx->count_pb++;
	printf("pb\n");
}
