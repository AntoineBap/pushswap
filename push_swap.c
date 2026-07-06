/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:18:15 by abaptist          #+#    #+#             */
/*   Updated: 2026/07/02 10:15:08 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_context	ctx;

	t_ps_list *(stack_a) = NULL;
	t_ps_list *(stack_b) = NULL;
	ft_bzero(&ctx, sizeof(t_ps_context));
	if (argc < 2)
		return (0);
	stack_a = fill_stack_a(argv, argc);
	if (!stack_a)
		exit_prog(6);
	float (disorder) = compute_disorder(&stack_a);
	char *(algo) = find_algo_flag(argv, argc);
	if (ft_strncmp(algo, "--simple", 9) == 0)
		algo_simple_ps(&stack_a, &stack_b, &ctx);
	//else if (ft_strncmp(algo, "--medium", 9) == 0)
		//algo_medium_ps(&stack_a, &stack_b, &ctx);
	else if (ft_strncmp(algo, "--complex", 10) == 0)
		greedy_sort(&stack_a, &stack_b, &ctx);
	else
		adaptive_algo(&stack_a, &stack_b, &ctx);
	if (has_bench_flag(argv, argc))
		bench_gestion(disorder, algo, &ctx);
	return (0);
}

char	*find_algo_flag(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			return ("--simple");
		if (ft_strncmp(argv[i], "--medium", 9) == 0)
			return ("--medium");
		if (ft_strncmp(argv[i], "--complex", 10) == 0)
			return ("--complex");
		if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			return ("--adaptive");
		i++;
	}
	return ("--adaptive");
}

int	has_bench_flag(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}
