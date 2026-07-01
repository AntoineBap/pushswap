/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:24:16 by abaptist          #+#    #+#             */
/*   Updated: 2026/06/10 16:07:14 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

float	compute_disorder(t_ps_list **stack_a)
{
	float	disorder_index;

	int (i) = 0;
	int (j) = 0;
	int (mistakes) = 0;
	int (total_pairs) = 0;
	int (lst_size) = ft_lstsize_ps(*stack_a);
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
	disorder_index = (float)mistakes / total_pairs;
	return (disorder_index);
}
