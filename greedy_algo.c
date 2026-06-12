#include "push_swap.h"

int	get_max(t_ps_list *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_ps_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	rotation_cost(int index, int size)
{
	if (index <= size / 2)
		return (index);
	return (size - index);
}

static int	index_of_max(t_ps_list *stack_a)
{
	t_ps_list	*current;
	int			index;
	int			best_index;
	int			best_val;

	current = stack_a;
	index = 0;
	best_index = 0;
	best_val = INT_MIN;
	while (current)
	{
		if (current->content > best_val)
		{
			best_val = current->content;
			best_index = index;
		}
		current = current->next;
		index++;
	}
	return (best_index);
}

int	find_target_index(t_ps_list *stack_a, int val)
{
	t_ps_list	*current;
	int			index;
	int			best_index;
	int			best_val;

	current = stack_a;
	index = 0;
	best_index = -1;
	best_val = INT_MAX;
	while (current)
	{
		if (current->content > val && current->content < best_val)
		{
			best_val = current->content;
			best_index = index;
		}
		current = current->next;
		index++;
	}
	if (best_index == -1)
		return (index_of_max(stack_a) + 1);
	return (best_index);
}

int	compute_cost(t_ps_list *stack_a, int val, int b_index, int size_b)
{
	int	size_a;
	int	target_a;
	int	cost_b;
	int	cost_a;

	size_a = ft_lstsize_ps(stack_a);
	target_a = find_target_index(stack_a, val);
	cost_b = rotation_cost(b_index, size_b);
	cost_a = rotation_cost(target_a, size_a);
	return (cost_b + cost_a);
}