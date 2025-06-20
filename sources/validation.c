/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:15:42 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/20 23:26:08 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_int(const char *str)
{
	long	num;
	int		i;
	int 	sign;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		num = num * 10 + (str[i++] - '0');
	}
	num = num * sign;
	if (num < -2147483648 || num > 2147483647)
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

char	**parse_args(int ac, char **av, int *out_count)
{
	char	**array_nb;
	int		i;

	if (ac == 2)
	{
		array_nb = ft_split(av[1], ' ');
		if (!array_nb || !array_nb[0])
			ft_error();
		i = 0;
		while (array_nb[i])
			i++;
		*out_count = i;
	}
	else
	{
		array_nb = av + 1;
		*out_count = ac - 1;
	}
	return (array_nb);
}

int	*validate_input(int ac, char **av, int *out_count)
{
	int		i;
	int		*numbers;
	int		count;
	char	**args;

	args = parse_args(ac, av, &count);
	if (count == 0)
    	clean_array_exit(args, NULL);
	numbers = malloc(count * sizeof(int));
	if (!numbers)
		clean_array_exit(args, NULL);
	i = 0;
	while (i < count)
	{
		if (is_valid_int(args[i]))
			clean_array_exit(args, numbers);
		numbers[i] = ft_atoi(args[i]);
		if (is_duplicate(numbers, i, numbers[i]))
			clean_array_exit(args, numbers);
		i++;
	}
	if (ac == 2)
		clean_array(args);
	*out_count = count;
	return (numbers);
}
