/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:08:36 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/16 15:11:36 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void memory_cleanup(int *stack_a, int *stack_b)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}
int memory_allocation(int **stack_a, int **stack_b, int size_a)
{
	*stack_a = malloc(size_a * sizeof(int));
	if (!*stack_a)
		return (0);
	*stack_b = malloc(size_a* sizeof(int));
	if (!*stack_b)
	{
		free(*stack_a);
		return (0);
	}
	return (1);
}
int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int i;

	if (ac < 2)
		ft_error();
	size_a = ac - 1;
	size_b = 0;
	memory_allocation(&stack_a, &stack_b, size_a);
	if (!stack_a || !stack_b)
	{
		memory_cleanup(stack_a, stack_b);
		ft_error();
	}
	i = 0;
	while (i < size_a)
	{
		stack_a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	algorithm(stack_a, stack_b, size_a, size_b);
	memory_cleanup(stack_a, stack_b);
	return (0);
}
