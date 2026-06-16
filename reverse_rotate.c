#include "push_swap.h"

void	reverse_rotate(t_ps_list **stack)
{
	t_ps_list	*maillon;
	t_ps_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	maillon = *stack;
	while (maillon->next->next != NULL)
		maillon = maillon->next;
	last_node = maillon->next;
	maillon->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	rra(t_ps_list **stack_a)
{
	reverse_rotate(stack_a);
	op_count_inc();
	printf("rra\n");
}

void	rrb(t_ps_list **stack_b)
{
	reverse_rotate(stack_b);
	op_count_inc();
	printf("rrb\n");
}

void	rrr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	op_count_inc();
	printf("rrr\n");
}