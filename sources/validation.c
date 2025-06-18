/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:15:42 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/18 18:59:23 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_int(const char *str)
{
	long	num;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

int	is_duplicate(int *stack, int size, int nbr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	*validate_input(int ac, char **av)
{
	int	i;
	int	*numbers;

	if (ac < 2)
		ft_error();
	numbers = malloc((ac - 1) * sizeof(int));
	if (!numbers)
		ft_error();
	i = 1;
	while (i < ac)
	{
		if (is_valid_int(av[i]))
			ft_error();
		numbers[i - 1] = ft_atoi(av[i]);
		if (is_duplicate(numbers, i - 1, numbers[i - 1]))
			ft_error();
		i++;
	}
	return (numbers);
}
