/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 08:55:21 by abaptist          #+#    #+#             */
/*   Updated: 2026/07/01 07:59:15 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct ps_list
{
	int				content;
	struct ps_list	*next;
}					t_ps_list;

typedef struct ps_ctx_list
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
	int			count;
}				ctx_list;

t_ps_list	*ft_lstnew_ps(int content);
t_ps_list	*fill_stack_a(char *argv, int argc);
void		ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new);
void		sa(t_ps_list **stack_a, int *count);
void		sb(t_ps_list **stack_b, int *count);
void		pa(t_ps_list **stack_a, t_ps_list **stack_b, int *count);
void		pb(t_ps_list **stack_b, t_ps_list **stack_a, int *count);
void		ra(t_ps_list **stack_a, int *count);
void		rb(t_ps_list **stack_b, int *count);
void		rr(t_ps_list **stack_a, t_ps_list **stack_b, int *count);
void		rra(t_ps_list **stack_a, int *count);
void		rrb(t_ps_list **stack_b, int *count);
void		rrr(t_ps_list **stack_a, t_ps_list **stack_b, int *count);
int			compute_disorder(t_ps_list **stack_a);
int			ft_lstsize_ps(t_ps_list *lst);
int			get_max(t_ps_list *stack);
int			get_min(t_ps_list *stack);
int			rotation_cost(int index, int size);
int			find_target_index(t_ps_list *stack_a, int val);
int			compute_cost(t_ps_list *stack_a, int val, int b_index, int size_b);
void		find_cheapest(t_ps_list *stack_a, t_ps_list *stack_b,
				int *best_b_index, int *best_val);
void		bring_to_top_b(t_ps_list **stack_b, int best_b_index, int *count);
void		bring_to_target_a(t_ps_list **stack_a, int best_val, int *count);
void		greedy_sort(t_ps_list **stack_a, t_ps_list **stack_b, int *count);

#endif