/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:08:36 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/16 12:36:37 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void memory_cleanup(int *stack_a, int *stack_b)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}
void memory_allocation(int **stack_a, int **stack_b, int size_a, int size_b)
{
	*stack_a = malloc(size_a * sizeof(int));
	if (!*stack_a)
		return;
	*stack_b = malloc(size_b * sizeof(int));
	if (!*stack_b)
	{
		free(*stack_a);
		return;
	}
}
int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	if (ac < 2 || (ac == 2 && !ft_strcmp(av[1], "")))
		ft_error;
	size_a = ac - 1;
	size_b = ac - 1;
	memory_allocation(&stack_a, &stack_b, size_a, size_b);
	if (!stack_a || !stack_b)
	{
		memory_cleanup(stack_a, stack_b);
		ft_error;
	}
	return (0);
}
