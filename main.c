/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:56:21 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/04 00:27:19 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//to delete printlist
#include <stdio.h>

//to delete
void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		printf("%d", tmp->number);
		if (tmp->next != NULL)
			printf(" -> ");
		tmp = tmp->next;
	}
	printf("\n");
}

char	**parser(int argc, char **argv)
{
	char	**str_arr;
	int		i;

	i = 0;
	if (argc == 2)
		str_arr = ft_split(argv[1], ' ');
	else
	{
		str_arr = malloc(sizeof(char *) * argc);
		if (!str_arr)
			return (NULL);
		while (i < argc - 1)
		{
			str_arr[i] = ft_strdup(argv[i + 1]);
			if (str_arr[i] == NULL)
				return (NULL);
			i++;
		}
		str_arr[i] = NULL;
	}
	return (str_arr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**array;

	a = NULL;
	b = NULL;
	array = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc >= 2)
		array = parser(argc, argv);
	fill_stack_a(&a, array);
	if (is_duplicate(a) == 1)
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		free(array);
		return (0);
	}
	print_stack(a);
	if (!is_sorted(a))
	{
//		printf("requires sorting\n"); // to delete
		init_sort(&a, &b);
	}
	//printf("%d, %d\n", a->number, a->prev->number);
//	else if (is_sorted(a)) //to delete
//		printf("input is sorted\n");
//	printf("back to main:\n");
//	int i = ft_lstsize_ps(a);
//	printf("amount of numbers on the list %d\n", i);
//	printf("numbers in stack\n");
	print_stack(a);
//	printf("\n");
	free_stack(&a);
	free(array);
	return (0);
}
