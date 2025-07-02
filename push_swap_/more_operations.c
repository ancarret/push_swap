/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:58:05 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/27 18:40:22 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	int		count;
	t_stack	*aux;

	if (!lst)
		return (0);
	aux = lst;
	count = 1;
	while (aux->next != NULL)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}

int	len_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (!aux || !aux->next)
		return (1);
	while (aux->next)
	{
		if (aux->content > aux->next->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}
