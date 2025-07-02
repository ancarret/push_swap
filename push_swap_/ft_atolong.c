/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:51:58 by ancarret          #+#    #+#             */
/*   Updated: 2025/02/28 10:24:27 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atolong(const char *str)
{
	int		index;
	long	number;
	char	sign;

	index = 0;
	number = 0;
	sign = '+';
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n'
		|| str[index] == '\r' || str[index] == '\v' || str[index] == '\f')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		sign = str[index];
		index++;
	}
	while (str[index] != '\0' && ft_isdigit(str[index]))
	{
		number *= 10;
		number = number + ((int)str[index] - 48);
		index++;
	}
	if (sign == '-')
		number = -number;
	return (number);
}
