/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:18:15 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/10 15:04:44 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	int			current;
	t_ps_list	*temp;
	t_ps_list	*temp2;
	t_ps_list	*temp3;

	stack_a = fill_stack_a(argv[1], argc);
	temp = stack_a;
	ft_printf("STACK INITIALE : \n");
	while (temp)
	{
		current = temp->content;
		ft_printf("%d\n", current);
		temp = temp->next;
	}
	printf("\nTEST ROTATE : \n");
	ra(&stack_a);
	temp = stack_a;
	while (temp)
	{
		current = temp->content;
		ft_printf("%d\n", current);
		temp = temp->next;
	}
	printf("\nTEST REVERSE ROTATE : \n");
	rra(&stack_a);
	temp2 = stack_a;
	while (temp2)
	{
		current = temp2->content;
		ft_printf("%d\n", current);
		temp2 = temp2->next;
	}
	temp3 = stack_a;
	compute_disorder(&temp3);
	return (0);
}


