/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:17:45 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/08/04 00:14:28 by hskrzypi         ###   ########.fr       */
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

void	free_stack(t_stack **stack);
void	fill_stack_a(t_stack **a, char **array, int *error_flag);
int		is_duplicate(t_stack *a);
int		is_sorted(t_stack *a);
int		is_number(const char *str);
long	converter(const char *str);
void	init_sort(t_stack **a, t_stack **b);
void	err_return(char **str, t_stack **stack);

//Sorting commands (retrieved):
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//Turk sort utils:
int		ft_lstsize_ps(t_stack *lst);//retrieved
void	print_stack(t_stack *stack);//retrieved, to be deleted
t_stack	*find_biggest(t_stack *stack);//retrieved
t_stack	*find_smallest(t_stack *stack);//retrieved
t_stack	*find_last(t_stack *stack);//retrieved

//Sort utils: // retrieved
void	set_cheapest(t_stack *stack);
t_stack	*fetch_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	prep_for_push(t_stack **stack, t_stack *top, char stack_id);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	current_index(t_stack *stack);
void	min_on_top(t_stack **a);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);

#endif
