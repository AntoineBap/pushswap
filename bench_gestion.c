/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoisi <schoisi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 04:07:44 by schoisi           #+#    #+#             */
/*   Updated: 2026/07/02 10:06:24 by schoisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_bench_resume(float disorder, char *algo,
	t_ps_context *ctx, char *demo)
{
	ft_printf(2, "[bench] disorder: %f%%\n", disorder * 100);
	ft_printf(2, "[bench] strategy: %s / %s\n", algo, demo);
	ft_printf(2, "[bench] total_ops: %d\n", ctx->count);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ctx->count_sa,
		ctx->count_sb, ctx->count_ss, ctx->count_pa, ctx->count_pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ctx->count_ra, ctx->count_rb, ctx->count_rr, ctx->count_rra,
		ctx->count_rrb, ctx->count_rrr);
}

int	bench_gestion(float disorder, char *algo, t_ps_context *ctx)//in progress
{
	char *(demo);

	if (ft_strncmp(algo, "--adaptive", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(nVn)") + 1));
		if (!demo)
			return (1);
		ft_strlcpy(demo, "O(nVn)", ft_strlen("O(nVn)") + 1);
	}
	else if (ft_strncmp(algo, "--simple", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(n2 )") + 1));
		if (!demo)
			return (1);
		ft_strlcpy(demo, "O(n2 )", ft_strlen("O(n2 )") + 1);
	}
	else if (ft_strncmp(algo, "--medium", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(nVn)") + 1));
		if (!demo)
			return (1);
		ft_strlcpy(demo, "O(nVn)", ft_strlen("O(nVn)") + 1);
	}
	else if (ft_strncmp(algo, "--complex", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(n log n)") + 1));
		if (!demo)
			return (1);
		ft_strlcpy(demo, "O(n log n)", ft_strlen("O(n log n)") + 1);
	}
	else
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(nVn)") + 1));
		if (!demo)
			return (1);
		ft_strlcpy(demo, "O(nVn)", ft_strlen("O(nVn)") + 1);
	}
	print_bench_resume(disorder, algo, ctx, demo);
	free(demo);
	return (0);
}
