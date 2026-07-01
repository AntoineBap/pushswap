/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:18:15 by abaptist          #+#    #+#             */
/*   Updated: 2026/07/01 08:08:06 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list		*stack_a;
	t_ps_list		*stack_b;
	int 			count;

	stack_a = fill_stack_a(argv[1], argc);
	compute_disorder(&stack_a);
	stack_b = NULL;
	count = 0;
	greedy_sort(&stack_a, &stack_b, &count);
	printf("%d", count);
	return (0);
}


