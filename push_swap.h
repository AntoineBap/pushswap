/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 08:55:21 by abaptist          #+#    #+#             */
/*   Updated: 2026/07/02 10:13:53 by schoisi          ###   ########.fr       */
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

typedef struct s_ps_context
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
	int			count;
	int			count_pa;
	int			count_pb;
	int			count_sa;
	int			count_sb;
	int			count_ss;
	int			count_ra;
	int			count_rb;
	int			count_rr;
	int			count_rra;
	int			count_rrb;
	int			count_rrr;
}					t_ps_context;

t_ps_list	*ft_lstnew_ps(int content);
t_ps_list	*fill_stack_a(char **argv, int argc);
void		ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new);
void		sa(t_ps_list **stack_a, t_ps_context *ctx);
void		sb(t_ps_list **stack_b, t_ps_context *ctx);
void		ss(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx);
void		pa(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx);
void		pb(t_ps_list **stack_b, t_ps_list **stack_a, t_ps_context *ctx);
void		ra(t_ps_list **stack_a, t_ps_context *ctx);
void		rb(t_ps_list **stack_b, t_ps_context *ctx);
void		rr(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx);
void		rra(t_ps_list **stack_a, t_ps_context *ctx);
void		rrb(t_ps_list **stack_b, t_ps_context *ctx);
void		rrr(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx);
float		compute_disorder(t_ps_list **stack_a);
int			ft_lstsize_ps(t_ps_list *lst);
int			get_max(t_ps_list *stack);
int			get_min(t_ps_list *stack);
int			rotation_cost(int index, int size);
int			find_target_index(t_ps_list *stack_a, int val);
int			compute_cost(t_ps_list *stack_a, int val, int b_index, int size_b);
void		find_cheapest(t_ps_list *stack_a, t_ps_list *stack_b,
				int *best_b_index, int *best_val);
void		bring_to_top_b(t_ps_list **stack_b, int best_b_index, t_ps_context *ctx);
void		bring_to_target_a(t_ps_list **stack_a, int best_val, t_ps_context *ctx);
void		greedy_sort(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx);
void		exit_prog(int status);
int			is_number(char *str, int *i);
int			check_format(char *str);
void		adaptive_algo(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx);
void		algo_simple_ps(t_ps_list **stack_a,
				t_ps_list **stack_b, t_ps_context *ctx);
				
// en cours a ne surtout pas toucher
//int			algo_medium_ps(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx);
//t_ps_list	*find_end_node(int nmb_of_blocs,t_ps_list *actual_node);
//void		print_stack(t_ps_list **lst);
int			bench_gestion(float disorder,char *algo, t_ps_context *ctx);//probleme sur le counter : on a pas un counter pour chaque operation distinct
char		*find_algo_flag(char **argv, int argc);
int			has_bench_flag(char **argv, int argc);


#endif