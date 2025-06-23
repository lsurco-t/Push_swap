/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:54:30 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/23 12:01:12 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(int *stack_a, int size_a)
{
	int	temp;
	int	i;

	if (size_a <= 1)
		return ;
	temp = stack_a[size_a - 1];
	i = size_a - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(int *stack_b, int size_b)
{
	int	temp;
	int	i;

	if (size_b <= 1)
		return ;
	temp = stack_b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	write(1, "rrb\n", 4);
}

static void	reverse_rotate(int *stack, int size)
{
	int	i;
	int	temp;

	if (size <= 1)
		return ;
	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	reverse_rotate(stack_a, size_a);
	reverse_rotate(stack_b, size_b);
	write(1, "rrr\n", 4);
}
