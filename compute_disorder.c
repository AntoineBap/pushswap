/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:24:16 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/10 15:04:36 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_lstsize_ps(t_ps_list *lst)
{
	t_ps_list	*maillon;
	int			i;

	maillon = lst;
	i = 0;
	while (maillon)
	{
		maillon = maillon->next;
		i++;
	}
	return (i);
}

int	ft_lstget(t_ps_list **stack, int i)
{
	int			count;
	t_ps_list	*maillon;
	int			result;

	maillon = *stack;
	count = 0;
	while (count < i)
	{
		maillon = maillon->next;
		count++;
	}
	result = maillon->content;
	return (result);
}

int	compute_disorder(t_ps_list **stack_a)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;
	int	lst_size;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	lst_size = ft_lstsize_ps(*stack_a);
	while (i < lst_size)
	{
		j = i + 1;
		while (j < lst_size)
		{
			total_pairs += 1;
			if (ft_lstget(stack_a, i) > ft_lstget(stack_a, j))
				mistakes += 1;
			j += 1;
		}
		i += 1;
	}
	ft_printf("\nmistakes : %d\ntotal pairs : %d\n", mistakes, total_pairs);
	return (mistakes / total_pairs);
}
