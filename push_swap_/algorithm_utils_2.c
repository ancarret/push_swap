/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:49:51 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/27 18:07:00 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_closer_to_top(t_stack *stack, int number)
{
	t_stack	*aux;
	int		pos;
	int		size;

	pos = 0;
	size = ft_stack_size(stack);
	aux = stack;
	while (aux && aux->content != number)
	{
		pos++;
		aux = aux->next;
	}
	return (pos <= size / 2);
}

int	movements_to_top(t_stack *stack, int number)
{
	t_stack	*aux;
	int		pos;
	int		size;

	size = ft_stack_size(stack);
	pos = 0;
	aux = stack;
	while (aux && aux->content != number)
	{
		pos++;
		aux = aux->next;
	}
	if (!aux)
		return (0);
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

void	sort_three_more_conditions(int first, int second, int third,
		t_stack **stack)
{
	if (first > second && second < third && first > third)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	else if (first < second && second > third && first > third)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	else if (first > second && second > third)
	{
		swap(stack);
		ft_printf("sa\n");
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second < third && first < third)
	{
		swap(stack);
		ft_printf("sa\n");
	}
	else if (first < second && second > third && first < third)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
		swap(stack);
		ft_printf("sa\n");
	}
	sort_three_more_conditions(first, second, third, stack);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*aux;

	min = INT_MAX;
	aux = stack;
	while (aux)
	{
		if (aux->content < min)
			min = aux->content;
		aux = aux->next;
	}
	return (min);
}
