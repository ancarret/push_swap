/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:30:17 by ancarret          #+#    #+#             */
/*   Updated: 2025/03/21 08:19:53 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	out_of_range_numbers(t_stack *stack_a)
{
	t_stack	*aux;
	long	number;

	aux = stack_a;
	while (aux)
	{
		number = aux->content;
		if (number > INT_MAX || number < INT_MIN)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	check_not_digit(char **argv, int i, int j)
{
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		min;

	stack_a = NULL;
	stack_b = NULL;
	if (create_stacks_and_check_args(&stack_a, argc, argv))
		return (1);
	if (out_of_range_numbers(stack_a))
		return (free_stack(&stack_a), ft_putstr_fd("Error\n", 2), 1);
	if (is_sorted_or_two_three_numbers(&stack_a))
		return (free_stack(&stack_a), 0);
	else
	{
		push_two_elements(&stack_a, &stack_b);
		push_stack_a_until_three(&stack_a, &stack_b);
		get_back_stack_b_to_a(&stack_a, &stack_b);
		min = find_min(stack_a);
		get_best_to_top(&stack_a, min, 0);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
