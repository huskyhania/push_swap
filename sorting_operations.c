/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:14:16 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/04 00:22:46 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head)
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

void	turk_sort(t_stack **a, t_stack **b, int length)
{
//	try adding condition to swap first and second first if necessary - might cut some operations later on
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
