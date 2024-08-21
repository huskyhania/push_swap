/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:54:04 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/21 19:41:36 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		match_a2b(*a, *b);
		move_a2b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		match_b2a(*a, *b);
		move_b2a(a, b);
	}
	set_index_median(*a);
	front_min(a);
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

static void	create_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->number = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	create_stack_a(t_stack **a, char **array, int *error_flag)
{
	long	number;
	int		i;

	i = 0;
	while (array[i])
	{
		if (!(is_number(array[i])))
		{
			*error_flag = 1;
			return ;
		}
		number = converter(array[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			*error_flag = 1;
			return ;
		}
		create_node(a, (int)number);
		i++;
	}
}
