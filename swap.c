/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaptist <abaptist@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-10 11:45:53 by abaptist          #+#    #+#             */
/*   Updated: 2026-06-10 11:45:53 by abaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*first_node;

	maillon = *stack;
	first_node = maillon;
	maillon = maillon->next;
	first_node->next = maillon->next;
	maillon->next = first_node;
	*stack = maillon;
}

void	sa(t_ps_list **stack_a, t_ps_context *ctx)
{
	swap(stack_a);
	ctx->count++;
	ctx->count_sa++;
	ft_printf(1, "sa\n");
}

void	sb(t_ps_list **stack_b, t_ps_context *ctx)
{
	swap(stack_b);
	ctx->count++;
	ctx->count_sb++;
	ft_printf(1, "sb\n");
}

void	ss(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx)
{
	swap(stack_a);
	swap(stack_b);
	ctx->count++;
	ctx->count_ss++;
	ft_printf(1, "ss\n");
}

