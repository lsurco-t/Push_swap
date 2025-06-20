/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:08:36 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/20 20:28:58 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	memory_cleanup(int *stack_a, int *stack_b)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;

	stack_a = validate_input(ac, av, &size_a);
	size_b = 0;
	stack_b = malloc(size_a * sizeof(int));
	if (!stack_a || !stack_b)
	{
		memory_cleanup(stack_a, stack_b);
		ft_error();
	}
	algorithm(stack_a, stack_b, size_a, size_b);
	int i = 0;
	while(i < size_a)
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	memory_cleanup(stack_a, stack_b);
	return (0);
}
