#include "push_swap.h"

void	rotate(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*first_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	maillon = *stack;
	first_node = *stack;
	while (maillon->next != NULL)
		maillon = maillon->next;
	*stack = first_node->next;
	maillon->next = first_node;
	first_node->next = NULL;
}

void	ra(t_ps_list **stack_a)
{
	rotate(stack_a);
	op_count_inc();
	printf("ra\n");
}

void	rb(t_ps_list **stack_b)
{
	rotate(stack_b);
	op_count_inc();
	printf("rb\n");
}

void	rr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	op_count_inc();
	printf("rr\n");
}