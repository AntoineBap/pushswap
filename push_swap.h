/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 08:55:21 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/10 14:51:11 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct ps_list
{
	int				content;
	struct ps_list	*next;
}					t_ps_list;

t_ps_list	*ft_lstnew_ps(int content);
t_ps_list	*fill_stack_a(char *argv, int argc);
void		ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new);
void		sa(t_ps_list **stack_a);
void		sb(t_ps_list **stack_b);
void		pa(t_ps_list *stack_a, t_ps_list *stack_b);
void		pb(t_ps_list *stack_b, t_ps_list *stack_a);
void		ra(t_ps_list **stack_a);
void		rb(t_ps_list **stack_b);
void		rr(t_ps_list **stack_a, t_ps_list **stack_b);
void		rra(t_ps_list **stack_a);
void		rrb(t_ps_list **stack_b);
void		rrr(t_ps_list **stack_a, t_ps_list **stack_b);
int			compute_disorder(t_ps_list **stack_a);
int			ft_lstsize_ps(t_ps_list *lst);

#endif