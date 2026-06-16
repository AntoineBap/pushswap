#include "push_swap.h"

void	swap(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*first_node;

	maillon = *stack;
	first_node = maillon;
	maillon = maillon->next;
	first_node->next = maillon->next;
	maillon->next = first_node;
	*stack = maillon;
}

void	sa(t_ps_list **stack_a)
{
	swap(stack_a);
	op_count_inc();
	printf("sa\n");
}

void	sb(t_ps_list **stack_b)
{
	swap(stack_b);
	op_count_inc();
	printf("sb\n");
}