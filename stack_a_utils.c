/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:30:59 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/09 21:14:15 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_for_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number
				&& current_b->number > best_match_index)
			{
				best_match_index = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = find_biggest(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	a_length;
	int	b_length;

	a_length = ft_lstsize_ps(a);
	b_length = ft_lstsize_ps(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->is_above_median))
			a->push_cost = a_length - (a->index);
		if (a->target->is_above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += b_length - (a->target->index);
		a = a->next;
	}
}

void	match_a2b(t_stack *a, t_stack *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_for_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	move_a2b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = fetch_cheapest(*a);
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->is_above_median)
		&& !(cheapest->target->is_above_median))
		rev_rotate_both(a, b, cheapest);
	cheapest_2_top(a, cheapest, 'a');
	cheapest_2_top(b, cheapest->target, 'b');
	pb(b, a);
}
