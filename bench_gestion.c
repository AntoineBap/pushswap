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

void	print_bench_resume(float disorder, char **argv,
	t_ps_context *ctx, char *demo)
{
	ft_printf("[bench] disorder: %f%%\n", disorder * 100);
	ft_printf("[bench] strategy: %s / %s\n", argv[2], demo);
	ft_printf("[bench] total_ops: %d\n", ctx->count);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", ctx->count_sa,
		ctx->count_sb, ctx->count_ss, ctx->count_pa, ctx->count_pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ctx->count_ra, ctx->count_rb, ctx->count_rr, ctx->count_rra,
		ctx->count_rrb, ctx->count_rrr);
}

int bench_gestion(float disorder, char **argv, t_ps_context *ctx)//in progress
{
	char *(demo);
	if (ft_strncmp(argv[2], "--adaptive", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(nVn)") + 1));
		ft_strlcat(demo, "O(nVn)", ft_strlen("O(nVn)"));
	}
	else if (ft_strncmp(argv[2], "--simple", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(n2 )") + 1));
		ft_strlcat(demo, "O(n2 )", ft_strlen("O(n2 )"));
	}
	else if (ft_strncmp(argv[2], "--medium", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(nVn)") + 1));
		ft_strlcat(demo, "O(nVn)", ft_strlen("O(nVn)"));
	}
	else if (ft_strncmp(argv[2], "--complex", 11) == 0)
	{
		demo = malloc(sizeof(char) * (ft_strlen("O(n log n)") + 1));
		ft_strlcat(demo, "O(n log n)", ft_strlen("O(n log n)"));
	}
	else
	{
		demo = malloc(sizeof(char) * 11);
		ft_strlcat(demo, "O(nVn)", ft_strlen("O(nVn)"));
	}
	print_bench_resume(disorder, argv, ctx, demo);
	return (0);
}

/* output dans les exemples

[bench] disorder: 49.93%
[bench] strategy: Adaptive / O(n n)
[bench] total_ops: 7997
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 4840 rb: 1098 rr: 0 rra: 0 rrb: 1059 rrr: 0

*/