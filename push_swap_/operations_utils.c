/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:55 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/28 09:12:12 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(long content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	else
	{
		aux = *stack;
		while (aux->next->next)
			aux = aux->next;
		last = aux;
		aux = aux->next;
		aux->next = *stack;
		*stack = aux;
		last->next = NULL;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if (a)
		reverse_rotate(a);
	if (b)
		reverse_rotate(b);
}

void	print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d ", a->content);
		a = a->next;
	}
	ft_printf("\n");
}
