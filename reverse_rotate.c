/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:43:54 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/10 16:09:31 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	maillon = *stack;
	while (maillon->next->next != NULL)
		maillon = maillon->next;
	last_node = maillon->next;
	maillon->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	rra(t_ps_list **stack_a, t_ps_context *ctx)
{
	reverse_rotate(stack_a);
	ctx->count++;
	ctx->count_rra++;
	ft_printf(1, "rra\n");
}

void	rrb(t_ps_list **stack_b, t_ps_context *ctx)
{
	reverse_rotate(stack_b);
	ctx->count++;
	ctx->count_rrb++;
	ft_printf(1, "rrb\n");
}

void	rrr(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ctx->count++;
	ctx->count_rrr++;
	ft_printf(1, "rrr\n");
}
