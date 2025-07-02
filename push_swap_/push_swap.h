/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:24 by ancarret          #+#    #+#             */
/*   Updated: 2025/03/21 08:20:08 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			content;
	struct s_stack	*next;
}	t_stack;
//operations
void	swap(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rr(t_stack **a, t_stack **b);

//operations_utils
void	reverse_rotate(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
t_stack	*ft_stack_new(long content);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
void	print_stack(t_stack *a);

//more_operations
int		ft_stack_size(t_stack *lst);
int		len_split(char **args);
void	free_stack(t_stack **stack);
void	free_split(char **split);
int		is_sorted(t_stack *stack);

//turk_algorithm
void	push_two_elements(t_stack **a, t_stack **b);
int		create_stacks_and_check_args(t_stack **stack_a, int argc, char **argv);
int		is_sorted_or_two_three_numbers(t_stack **stack_a);
void	push_stack_a_until_three(t_stack **stack_a, t_stack **stack_b);
void	get_back_stack_b_to_a(t_stack **stack_a, t_stack **stack_b);

//algorithm_utils
int		calculate_the_cost(t_stack *aux, t_stack *a, t_stack *b);
t_stack	*find_the_cheapest(t_stack *a, t_stack *b);
int		find_best_position(t_stack *b, int number);
int		find_place(t_stack *a, int number);
void	get_best_to_top(t_stack **stack, int number, int stack_name);

//algorithm_utills
int		is_closer_to_top(t_stack *stack, int number);
int		movements_to_top(t_stack *stack, int number);
void	sort_three(t_stack **stack);
int		find_min(t_stack *stack);
void	sort_three_more_conditions(int first, int second, int third,
			t_stack **stack);

//check_args
int		duplicates(int argc, char **argv);
int		duplicates_split(int size, char **args);
int		in_list(int num, int *list, int size);
int		check_args(int argc, char **argv);
int		check_split_args(char **args);
long	ft_atolong(const char *str);
int		out_of_range_numbers(t_stack *stack_a);
int		check_not_digit(char **argv, int i, int j);

#endif