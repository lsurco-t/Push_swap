/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:15:42 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/18 20:35:17 by lsurco-t         ###   ########.fr       */
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

char	**parse_args(int ac, char **av, int *count)
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
		*count = i;
	}
	else
	{
		array_nb = av + 1;
		*count = ac - 1;
	}
	return (array_nb);
}

void	clean_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	*validate_input(int ac, char **av, int *out_count)
{
	int		i;
	int		*numbers;
	int		count;
	char	**args;

	args = parse_args(ac, av, &count);
	numbers = malloc(count * sizeof(int));
	if (!numbers)
		ft_error();
	i = 0;
	while (i < count)
	{
		if (is_valid_int(args[i]))
			ft_error();
		numbers[i] = ft_atoi(args[i]);
		if (is_duplicate(numbers, i, numbers[i]))
			ft_error();
		i++;
	}
	if (ac == 2)
		clean_array(args);
	*out_count = count;
	return (numbers);
}
