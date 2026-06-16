#include "push_swap.h"

static int	g_op_count = 0;

void	op_count_inc(void)
{
	g_op_count++;
}

int	get_op_count(void)
{
	return (g_op_count);
}

void	pa(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
	op_count_inc();
	printf("pa\n");
}

void	pb(t_ps_list **stack_b, t_ps_list **stack_a)
{
	t_ps_list	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
	op_count_inc();
	printf("pb\n");
}