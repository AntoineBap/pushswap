/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Medium_algorithm_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 08:22:15 by schoisi           #+#    #+#             */
/*   Updated: 2026/07/02 08:26:00 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ps_list *find_end_node(int nmb_of_blocs,t_ps_list *actual_node)
{
	t_ps_list *(end_node) = actual_node;
	int (count_bloc) = 0;
	while (count_bloc <= nmb_of_blocs)
	{
		if (end_node->next)
			end_node = end_node->next;
		else
			break;
		count_bloc++;
	}
	return (end_node);
}
