/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:08:36 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/13 12:05:46 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
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
		ft_error();
	*stack_b = malloc(size_b * sizeof(int));
	if (!*stack_b)
	{
		free(*stack_a);
		ft_error();
	}
}
int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	if (ac < 2 || (ac == 2 && !ft_strcmp(av[1], "")))
	{
		ft_error;
		return (0);
	}
	size_a = ac - 1;
	size_b = 0;
	memory_allocation(&stack_a, &stack_b, size_a, size_b);
	if (!stack_a || !stack_b)
		ft_error();
	return (0);
}
