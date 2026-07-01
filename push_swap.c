/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:18:15 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/11 18:23:13 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
	int			count;

	count = 0;
	if (argc < 2 || argc > 3)
		exit_prog(3);
	stack_a = fill_stack_a(argv[1 + (argc == 3)], argc);
	if (argc == 2 || ((ft_strncmp(argv[1], "--adaptive", 8) == 0) && argc == 3))
		adaptive_algo(&stack_a, &stack_b, &count);
	else if (ft_strncmp(argv[1], "--simple", 10) == 0)
		algo_simple_ps(&stack_a, &stack_b, &count);
/*	else if (ft_strncmp(argv[1], "--medium", 10) == 0)
		algo_medium_ps(stack_a);  */
	else if (ft_strncmp(argv[1], "--complex", 9) == 0)
		greedy_sort(&stack_a, &stack_b, &count);
	else
		exit_prog(4);
	ft_printf("%s%d\n", "operations count : ", count);
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