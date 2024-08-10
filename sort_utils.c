/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:56:44 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/10 15:59:59 by hskrzypi         ###   ########.fr       */
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

void	cheapest_2_top(t_stack **stack, t_stack *cheapest, char stack_id)
{
	while (*stack != cheapest)
	{
		if (stack_id == 'a')
		{
			if (cheapest->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_id == 'b')
		{
			if (cheapest->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	set_index_median(t_stack *stack)
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
