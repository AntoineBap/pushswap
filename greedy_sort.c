#include "push_swap.h"

static int	find_min_index(t_ps_list *stack_a)
{
	t_ps_list	*tmp;
	int			min_val;
	int			index;
	int			i;

	min_val = get_min(stack_a);
	tmp = stack_a;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->content == min_val)
			index = i;
		tmp = tmp->next;
		i++;
	}
	return (index);
}

static void	put_min_on_top(t_ps_list **stack_a, int *count)
{
	int	min_index;
	int	size_a;
	int	i;

	min_index = find_min_index(*stack_a);
	size_a = ft_lstsize_ps(*stack_a);
	if (min_index <= size_a / 2)
	{
		i = 0;
		while (i++ < min_index)
			ra(stack_a, count);
	}
	else
	{
		i = size_a - min_index;
		while (i-- > 0)
			rra(stack_a, count);
	}
}

static void	sort_three(t_ps_list **stack_a, int *count)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sa(stack_a, count);
	else if (a > b && b > c)
	{ sa(stack_a, count); rra(stack_a, count); }
	else if (a > b && b < c && a > c)
		ra(stack_a, count);
	else if (a < b && b > c && a < c)
	{ sa(stack_a, count); ra(stack_a, count); }
	else if (a < b && b > c && a > c)
		rra(stack_a, count);
}

void	greedy_sort(t_ps_list **stack_a, t_ps_list **stack_b, int *count)
{
	int	best_b_index;
	int	best_val;

	while (ft_lstsize_ps(*stack_a) > 3)
		pb(stack_b, stack_a, count);
	if (ft_lstsize_ps(*stack_a) == 3)
		sort_three(stack_a, count);
	else if (ft_lstsize_ps(*stack_a) == 2)
		sa(stack_a, count);
	while (*stack_b)
	{
		best_b_index = 0;
		best_val = 0;
		find_cheapest(*stack_a, *stack_b, &best_b_index, &best_val);
		bring_to_top_b(stack_b, best_b_index, count);
		bring_to_target_a(stack_a, best_val, count);
		pa(stack_a, stack_b, count);
	}
	if (!*stack_a)
		return ;
	put_min_on_top(stack_a, count);
}
