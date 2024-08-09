/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:56:21 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/09 21:24:05 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parser(int argc, char **argv)
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

static void	arr_stack_free(char **array, t_stack **stack)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	if (stack != NULL)
		free_stack(stack);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**array;
	int		error_flag;

	a = NULL;
	b = NULL;
	array = NULL;
	error_flag = 0;
	if (argc == 1)
		return (1);
	else if (argc >= 2)
		array = parser(argc, argv);
	create_stack_a(&a, array, &error_flag);
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
