/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 01:08:04 by schoisi           #+#    #+#             */
/*   Updated: 2026/07/02 10:07:04 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Range-based methods : 0 carre(n);
int	algo_medium_ps(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_context *ctx)
{
	t_ps_list *(actual_node) = *stack_a;
	int (nmb_of_blocs) = has_dot(racine(ft_lstsize_ps(*stack_a)));
	int (min_max)[2];
	find_min_max(stack_a, min_max);

	//triee la stack pour mettre les plus petit et le plus grand ensemble
	while (*stack_a)
	{
		min_in_bloc(nmb_of_blocs, actual_node, stack_a, count);
		pb(stack_b, stack_a, count);
	}

	return (0);
}
// [0][1][-2][9][5][4][50][2][100][90] | 10 - 

//debut <--------> fin
//rotation direction ---->


// source : https://openclassrooms.com/forum/sujet/trouver-la-racine-caree-d-un-nombre-sois-meme-87116
double racine(double nb)
{
	double calc;	// Calcul de la racine dans la boucle
	double diff;	// Pour tester la différence avec la valeur précédente

	// Si la racine n'a pas besoin d'être calculée (pour "0" ou "1")
	if (nb == 0.0 || nb == 1.0)
			return (nb);

	// Initialisation début de boucle
	calc=nb;                            // Ou n'importe quel nombre différent de "0"
	do {
			// Récupération de "calc" pour comparer avec le calcul suivant
			diff=calc;

			// Approximation de la racine (le calcul se fera en précision "double")
			calc=0.5 * (calc + nb / calc);

	// Tant que le processeur peut faire la différence entre ce calcul et le précédent (limite)
	} while (calc != diff);

	// Renvoi du résultat calculé
	return (calc);
}

//retourme 1 si il y a une virgule
int has_dot(double racine)
{
	if (racine != (int)racine)
	{
		return (1 + (int)racine);
	}
	return((int)racine);
}

int *find_min_max(t_ps_list **stack_a, int *min_max)
{
	t_ps_list *(node_actual) = *stack_a;
	int (value) = node_actual->content;
	while (node_actual)
	{
		if (node_actual->content < value)
		{
			value = node_actual->content;
		}
		node_actual = node_actual->next;
	}
	min_max[0] = value;
	node_actual = *stack_a;
	value = node_actual->content;
		while (node_actual)
	{
		if (node_actual->content > value)
		{
			value = node_actual->content;
		}
		node_actual = node_actual->next;
	}
	min_max[1] = value;
	return (min_max);
}

void min_in_bloc(int nmb_of_blocs, t_ps_list *actual_node, t_ps_list **stack_a, t_ps_context *ctx)
{
	//t_ps_list *(start_node) = actual_node;
	t_ps_list *(end_node) = find_end_node(nmb_of_blocs, actual_node);
	int (min_val) = actual_node ->content;
	int (count_bloc) = 0;
	int (number_of_tour) = 0;
	while (actual_node != end_node)
	{
		if (actual_node->content < min_val)
		{
			count_bloc = number_of_tour;
		}
		number_of_tour++;
		actual_node = actual_node->next;
	}
	while (count_bloc != 0)
	{
		ra(stack_a, count);
		count_bloc--;
	}
}
