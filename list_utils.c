/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:34:05 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/03 22:46:55 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_ps(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->number = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*current;

	if (!stack)
		return (NULL);
	biggest = stack;
	current = stack->next;
	while (current != NULL)
	{
		if (current->number > biggest->number)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	if (!stack)
		return (NULL);
	smallest = stack;
	current = stack->next;
	while (current != NULL)
	{
		if (current->number < smallest->number)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

static void	add_node(t_stack **stack, int n)
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

void	fill_stack_a(t_stack **a, char **array, int *error_flag)
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
		i++;
	}
	i = 0;
	while (array[i])
	{
		number = converter(array[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			*error_flag = 1;
			return ;
		}
		add_node(a, (int)number);
		i++;
	}
}
