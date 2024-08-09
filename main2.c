/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:56:21 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/06 20:07:17 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/
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
	int	error_flag;

	a = NULL;
	b = NULL;
	array = NULL;
	error_flag = 0;
	if (argc == 1)
		return (1);
	else if (argc >= 2)
		array = parser(argc, argv);
	fill_stack_a(&a, array, &error_flag);
	if (is_duplicate(a) || error_flag == 1)
	{
		write(2, "Error\n", 6);
		arr_stack_free(array, &a);
		return (1);
	}
	if (!is_sorted(a))
		init_sort(&a, &b);
	arr_stack_free(array, &a);
	return (0);
}
