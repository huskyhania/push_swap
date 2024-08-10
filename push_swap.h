/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:17:45 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/10 16:04:23 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "../complete_Libft/libft.h"

typedef struct s_stack_node
{
	int					number;
	int					index;
	int					push_cost;
	int					is_above_median;
	int					cheapest_flag;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
}	t_stack;

//Input checks:
int		is_duplicate(t_stack *a);
int		is_sorted(t_stack *a);
int		is_number(const char *str);
long	converter(const char *str);

//List utils:
void	free_stack(t_stack **stack);
void	create_stack_a(t_stack **a, char **array, int *error_flag);
int		ft_lstsize_ps(t_stack *lst);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_last(t_stack *stack);

//Sorting functions and commands:
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//Turk sort utils:
void	init_sort(t_stack **a, t_stack **b);
void	set_cheapest(t_stack *stack);
t_stack	*fetch_cheapest(t_stack *stack);
void	cheapest_2_top(t_stack **stack, t_stack *cheapest, char stack_id);
void	match_a2b(t_stack *a, t_stack *b);
void	match_b2a(t_stack *a, t_stack *b);
void	move_a2b(t_stack **a, t_stack **b);
void	move_b2a(t_stack **a, t_stack **b);
void	set_index_median(t_stack *stack);
void	front_min(t_stack **a);

#endif
