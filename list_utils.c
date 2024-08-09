/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:34:05 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/09 20:20:12 by hskrzypi         ###   ########.fr       */
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
