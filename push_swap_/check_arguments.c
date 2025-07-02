/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:28:53 by ancarret          #+#    #+#             */
/*   Updated: 2025/03/21 08:20:16 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	*list_elems;
	int	num;

	i = 1;
	j = 0;
	list_elems = malloc(sizeof(int) * (argc - 1));
	if (!list_elems)
		return (0);
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (in_list(num, list_elems, j))
		{
			free(list_elems);
			return (1);
		}
		list_elems[j] = num;
		i++;
		j++;
	}
	free(list_elems);
	return (0);
}

int	duplicates_split(int size, char **args)
{
	int	i;
	int	j;
	int	*list_elems;
	int	num;

	i = 0;
	j = 0;
	list_elems = malloc(sizeof(int) * (size));
	if (!list_elems)
		return (0);
	while (i < size)
	{
		num = ft_atoi(args[i]);
		if (in_list(num, list_elems, j))
		{
			free(list_elems);
			return (1);
		}
		list_elems[j] = num;
		i++;
		j++;
	}
	free(list_elems);
	return (0);
}

int	in_list(int num, int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (num == list[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			if (argv[i][j + 1] != '\0' || argv[i][j + 1] != '\0')
				j++;
			else
				return (ft_putstr_fd("Error\n", 2), 1);
		}
		if (check_not_digit(argv, i, j))
			return (1);
		i++;
	}
	if (duplicates(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

int	check_split_args(char **args)
{
	int	i;
	int	size;
	int	j;

	size = len_split(args);
	i = 0;
	while (i < size)
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
		{
			if (args[i][j + 1] != '\0' || args[i][j + 1] != '\0')
				j++;
			else
				return (ft_putstr_fd("Error\n", 2), 1);
		}
		if (check_not_digit(args, i, j))
			return (1);
		i++;
	}
	if (duplicates_split(size, args))
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}
