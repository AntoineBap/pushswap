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

void	ra(t_ps_list **stack_a, int *count)
{
	rotate(stack_a);
	(*count)++;
	printf("ra\n");
}

void	rb(t_ps_list **stack_b, int *count)
{
	rotate(stack_b);
	(*count)++;
	printf("rb\n");
}

void	rr(t_ps_list **stack_a, t_ps_list **stack_b, int *count)
{
	rotate(stack_a);
	rotate(stack_b);
	(*count)++;
	printf("rr\n");
}