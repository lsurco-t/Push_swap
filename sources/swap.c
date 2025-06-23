/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:50:17 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/23 10:59:59 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int *stack_a, int size_a)
{
	int	temp;

	if (size_a < 2)
		return ;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(int *stack_b, int size_b)
{
	int	temp;

	if (size_b < 2)
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	temp;

	if (size_a >= 2)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
	}
	if (size_b >= 2)
	{
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
	}
	write(1, "ss\n", 3);
}
