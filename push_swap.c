/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
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

/* static void	print_stack(t_ps_list *stack, char *label)
{
	t_ps_list	*tmp;

	printf("%s : ", label);
	tmp = stack;
	if (!tmp)
		printf("(vide)");
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
} */