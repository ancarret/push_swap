/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:54:08 by ancarret          #+#    #+#             */
/*   Updated: 2025/03/12 13:56:16 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_two_elements(t_stack **a, t_stack **b)
{
	int	num_elems;

	num_elems = ft_stack_size(*a);
	if (num_elems > 3)
	{
		push(b, a);
		ft_printf("pb\n");
		num_elems--;
	}
	if (num_elems > 3)
	{
		push(b, a);
		ft_printf("pb\n");
		num_elems--;
	}
}

int	create_stacks_and_check_args(t_stack **stack_a, int argc, char **argv)
{
	char	**args;
	int		i;

	args = argv;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (1);
		i = 0;
		while (args[i])
			ft_stack_add_back(stack_a, ft_stack_new(ft_atolong(args[i++])));
		if (check_split_args(args))
			return (free_stack(stack_a), free_split(args), 1);
		free_split(args);
	}
	else
	{
		i = 1;
		while (i < argc)
			ft_stack_add_back(stack_a, ft_stack_new(ft_atolong(argv[i++])));
		if (check_args(argc, argv))
			return (free_stack(stack_a), 1);
	}
	return (0);
}

int	is_sorted_or_two_three_numbers(t_stack **stack_a)
{
	if (is_sorted(*stack_a))
		return (free_stack(stack_a), 1);
	if (ft_stack_size(*stack_a) == 2)
	{
		swap(stack_a);
		ft_printf("sa\n");
		return (1);
	}
	if (ft_stack_size(*stack_a) == 3)
	{
		sort_three(stack_a);
		return (1);
	}
	return (0);
}

void	push_stack_a_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stack	*cheapest;
	int		best_pos;

	size = ft_stack_size(*stack_a);
	while (*stack_a && size > 3)
	{
		cheapest = find_the_cheapest(*stack_a, *stack_b);
		if (!cheapest)
			break ;
		best_pos = find_best_position(*stack_b, cheapest->content);
		get_best_to_top(stack_a, cheapest->content, 0);
		get_best_to_top(stack_b, best_pos, 1);
		push(stack_b, stack_a);
		ft_printf("pb\n");
		size = ft_stack_size(*stack_a);
	}
	sort_three(stack_a);
}

void	get_back_stack_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_b;
	int		target_pos;

	while (*stack_b)
	{
		cheapest_b = find_the_cheapest(*stack_b, *stack_a);
		if (!cheapest_b)
			break ;
		get_best_to_top(stack_b, cheapest_b->content, 1);
		target_pos = find_place(*stack_a, cheapest_b->content);
		get_best_to_top(stack_a, target_pos, 0);
		push(stack_a, stack_b);
		ft_printf("pa\n");
	}
}
