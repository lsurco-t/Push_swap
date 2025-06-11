/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:08:36 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/11 10:55:49 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
void sa(int *stack_a, int size_a)
{
	if (size_a < 2)
		return;
	int temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}
void sb(int *stack_b, int size_b)
{
	if (size_b < 2)
		return;
	int temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
}
void ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	sa(stack_a, size_a);
	sb(stack_b, size_b);
}
int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	int stack_a[100];
	int stack_b[100];
	int size_a = 0;
	int size_b = 0;
	while (--ac > 0)
	{
		if (!ft_isdigit(*av[ac]) && *av[ac] != '-' && *av[ac] != '+')
			ft_error();
		stack_a[size_a++] = ft_atoi(av[ac]);
	}
	return (0);
}