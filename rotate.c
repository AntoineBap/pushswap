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

	if (!stack || !*stack || !(*stack)->next)
		return ;
	maillon = *stack;
	first_node = *stack;
	while (maillon->next != NULL)
		maillon = maillon->next;
	*stack = first_node->next;
	maillon->next = first_node;
	first_node->next = NULL;
}

void	ra(t_ps_list **stack_a, t_ps_context *ctx)
{
	rotate(stack_a);
	ctx->count++;
	ctx->count_ra++;
	printf("ra\n");
}

void	rb(t_ps_list **stack_b, t_ps_context *ctx)
{
	rotate(stack_b);
	ctx->count++;
	ctx->count_rb++;
	printf("rb\n");
}

void	rr(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx)
{
	rotate(stack_a);
	rotate(stack_b);
	ctx->count++;
	ctx->count_rr++;
	printf("rr\n");
}
