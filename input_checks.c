/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:20:11 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/07/30 19:38:04 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *a)
{
	t_stack	*current;
	t_stack	*runner;

	current = a;
	if (!a)
		return (0);
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->number == runner->number)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	if (!a)
		return (1);
	while (current->next != NULL)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	converter(const char *str)
{
	int		i;
	long	number;
	int		negation;

	i = 0;
	number = 0;
	negation = 1;
	if (str[i] == '-')
	{
		negation = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * negation);
}
