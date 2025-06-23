/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:51:42 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/23 12:01:42 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(int *stack_a, int size_a)
{
	int	i;
	int	temp;

	i = 0;
	if (size_a <= 1)
		return ;
	temp = stack_a[0];
	while (i < size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size_a - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(int *stack_b, int size_b)
{
	int	i;
	int	temp;

	i = 0;
	if (size_b <= 1)
		return ;
	temp = stack_b[0];
	while (i < size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[size_b - 1] = temp;
	write(1, "rb\n", 3);
}

static void	rotate(int *stack, int size)
{
	int	i;
	int	temp;

	if (size <= 1)
		return ;
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

void	rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a);
	rotate(stack_b, size_b);
	write(1, "rr\n", 3);
}
