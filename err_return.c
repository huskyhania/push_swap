/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:39:06 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/06 17:40:07 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_return(char **array, t_stack **stack)
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
//	write(2, "Error\n", 6);
	return ;
}
