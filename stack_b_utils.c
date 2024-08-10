/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:47:52 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/10 15:51:58 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_for_b(t_stack *a, t_stack *b)
{
	t_stack	*helper_a;
	t_stack	*target_node;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		helper_a = a;
		while (helper_a)
		{
			if (helper_a->number > b->number
				&& helper_a->number < best_match_value)
			{
				best_match_value = helper_a->number;
				target_node = helper_a;
			}
			helper_a = helper_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	move_b2a(t_stack **a, t_stack **b)
{
	cheapest_2_top(a, (*b)->target, 'a');
	pa(a, b);
}

void	match_b2a(t_stack *a, t_stack *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_for_b(a, b);
}
