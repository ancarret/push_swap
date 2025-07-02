/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:47:07 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/27 18:58:01 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_the_cost(t_stack *aux, t_stack *a, t_stack *b)
{
	int	cost_a;
	int	best_pos;
	int	cost_b;
	int	total_cost;

	cost_a = movements_to_top(a, aux->content);
	cost_b = 0;
	best_pos = find_best_position(b, aux->content);
	if (b)
		cost_b = movements_to_top(b, best_pos);
	total_cost = cost_a + cost_b;
	return (total_cost);
}

t_stack	*find_the_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	int		min_cost;
	t_stack	*aux;
	int		total_cost;

	cheapest = NULL;
	min_cost = INT_MAX;
	aux = a;
	while (aux)
	{
		total_cost = calculate_the_cost(aux, a, b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = aux;
		}
		aux = aux->next;
	}
	return (cheapest);
}

int	find_best_position(t_stack *b, int number)
{
	t_stack	*aux;
	t_stack	*closest;

	closest = NULL;
	aux = b;
	while (aux)
	{
		if (aux->content < number
			&& (!closest || aux->content > closest->content))
			closest = aux;
		aux = aux->next;
	}
	if (!closest)
	{
		aux = b;
		closest = aux;
		while (aux)
		{
			if (aux->content > closest->content)
				closest = aux;
			aux = aux->next;
		}
	}
	return (closest->content);
}

int	find_place(t_stack *a, int number)
{
	t_stack	*aux;
	t_stack	*closest;

	closest = NULL;
	aux = a;
	while (aux)
	{
		if (aux->content > number
			&& (!closest || aux->content < closest->content))
			closest = aux;
		aux = aux->next;
	}
	if (!closest)
	{
		aux = a;
		closest = aux;
		while (aux)
		{
			if (aux->content < closest->content)
				closest = aux;
			aux = aux->next;
		}
	}
	return (closest->content);
}

void	get_best_to_top(t_stack **stack, int number, int stack_name)
{
	if (!stack || !(*stack))
		return ;
	while ((*stack)->content != number)
	{
		if (is_closer_to_top(*stack, number))
		{
			rotate(stack);
			if (stack_name)
				ft_printf("rb\n");
			else
				ft_printf("ra\n");
		}
		else
		{
			reverse_rotate(stack);
			if (stack_name)
				ft_printf("rrb\n");
			else
				ft_printf("rra\n");
		}
	}
}
