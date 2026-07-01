#include "push_swap.h"

void	find_cheapest(t_ps_list *stack_a, t_ps_list *stack_b,
			int *best_b_index, int *best_val)
{
	t_ps_list	*current;
	int			index;
	int			size_b;
	int			cost;
	int			min_cost;

	size_b = ft_lstsize_ps(stack_b);
	min_cost = INT_MAX;
	current = stack_b;
	index = 0;
	while (current)
	{
		cost = compute_cost(stack_a, current->content, index, size_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			*best_b_index = index;
			*best_val = current->content;
		}
		current = current->next;
		index++;
	}
}

void	bring_to_top_b(t_ps_list **stack_b, int best_b_index, int *count)
{
	int	size_b;
	int	i;

	size_b = ft_lstsize_ps(*stack_b);
	if (best_b_index <= size_b / 2)
	{
		i = 0;
		while (i++ < best_b_index)
			rb(stack_b, count);
	}
	else
	{
		i = size_b - best_b_index;
		while (i-- > 0)
			rrb(stack_b, count);
	}
}

void	bring_to_target_a(t_ps_list **stack_a, int best_val, int *count)
{
	int	target;
	int	size_a;
	int	i;

	size_a = ft_lstsize_ps(*stack_a);
	target = find_target_index(*stack_a, best_val);
	if (target <= size_a / 2)
	{
		i = 0;
		while (i++ < target)
			ra(stack_a, count);
	}
	else
	{
		i = size_a - target;
		while (i-- > 0)
			rra(stack_a, count);
	}
}