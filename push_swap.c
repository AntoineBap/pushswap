/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:18:15 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/16 14:24:33 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	stack_a = fill_stack_a(argv[1], argc);
	compute_disorder(&stack_a);
	stack_b = NULL;
	greedy_sort(&stack_a, &stack_b);
	printf("total operations : %d\n", get_op_count());
	return (0);
}


