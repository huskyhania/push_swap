/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:56:44 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/04 00:21:39 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack *stack)
{
	long	cheapest_flag;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_flag = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_flag)
		{
			cheapest_flag = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest_flag = 1;
}

t_stack	*fetch_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest_flag)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_stack **stack, t_stack *top, char stack_id)
{
	while (*stack != top)
	{
		if (stack_id == 'a')
		{
			if (top->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_id == 'b')
		{
			if (top->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = fetch_cheapest(*a);
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->is_above_median)
		&& !(cheapest->target->is_above_median))
		rev_rotate_both(a, b, cheapest);
	//maybe there could be a condition is one of them is met and the other not - one r the other rev_r)
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize_ps(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	min_on_top(t_stack **a)
{
	while ((*a)->number != find_smallest(*a)->number)
	{
		if (find_smallest(*a)->is_above_median)
			ra(a);
		else
			rra(a);
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

void	set_target_a(t_stack *a, t_stack *b)
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

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < best_match_index)
			{
				best_match_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}
