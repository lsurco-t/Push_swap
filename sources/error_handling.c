/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:36:18 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/23 12:02:39 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	memory_cleanup(int *stack_a, int *stack_b)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}

void	clean_array_exit(char **array, int *numbers)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
	if (numbers)
		free(numbers);
	ft_error();
}

void	clean_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	exit_with_cleanup(int ac, char **args, int *numbers)
{
	if (ac == 2)
		clean_array_exit(args, numbers);
	else
	{
		if (numbers)
			free(numbers);
		ft_error();
	}
}
