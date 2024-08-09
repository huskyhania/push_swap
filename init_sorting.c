#include "push_swap.h"

static void	sort_three(t_stack **head)
{
	t_stack	*biggest;

	biggest = find_biggest(*head);
	if (biggest == *head)
		ra(head);
	else if ((*head)->next == biggest)
		rra(head);
	if ((*head)->number > (*head)->next->number)
		sa(head);
}

static void	turk_sort(t_stack **a, t_stack **b, int length)
{
	if (length-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (length-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (length-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	init_sort(t_stack **a, t_stack **b)
{
	int	n;

	n = ft_lstsize_ps(*a);
	if (n == 1)
		return ;
	else if (n == 2)
		sa(a);
	else if (n == 3)
		sort_three(a);
	else
		turk_sort(a, b, n);
}
