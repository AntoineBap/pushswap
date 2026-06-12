/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:18:15 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/12 09:27:38 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_ps_list *stack, char *label)
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
}

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
	int			current;
	t_ps_list	*temp;
	t_ps_list	*temp2;
	t_ps_list	*temp3;

	stack_a = fill_stack_a(argv[1], argc);
	temp = stack_a;
	printf("STACK INITIALE : \n");
	while (temp)
	{
		current = temp->content;
		printf("%d\n", current);
		temp = temp->next;
	}
	printf("\nTEST ROTATE : \n");
	ra(&stack_a);
	temp = stack_a;
	while (temp)
	{
		current = temp->content;
		printf("%d\n", current);
		temp = temp->next;
	}
	printf("\nTEST REVERSE ROTATE : \n");
	rra(&stack_a);
	temp2 = stack_a;
	while (temp2)
	{
		current = temp2->content;
		printf("%d\n", current);
		temp2 = temp2->next;
	}
	temp3 = stack_a;
	compute_disorder(&temp3);
	stack_b = NULL;
	print_stack(stack_a, "avant");
	greedy_sort(&stack_a, &stack_b);
	print_stack(stack_a, "apres");
	return (0);
}


