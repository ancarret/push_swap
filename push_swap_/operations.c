/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:32 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/27 18:25:42 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*aux;

	if (stack && (*stack) && (*stack)->next)
	{
		aux = (*stack)->next;
		(*stack)->next = aux->next;
		aux->next = *stack;
		*stack = aux;
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if (a)
		swap(a);
	if (b)
		swap(b);
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	if (!a || !b || !(*b))
		return ;
	else
	{
		aux = *b;
		*b = (*b)->next;
		aux->next = *a;
		*a = aux;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*aux;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	else
	{
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		aux->next = *stack;
		*stack = (*stack)->next;
		aux->next->next = NULL;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if (a)
		rotate(a);
	if (b)
		rotate(b);
}
