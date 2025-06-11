/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:53:25 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/11 11:35:12 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_b == 0)
		return;
	stack_a[*size_a] = stack_b[*size_b - 1];
	(*size_a)++;
	(*size_b)--;
}
void pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_a == 0)
		return;
	stack_b[*size_b] = stack_a[*size_a - 1];
	(*size_b)++;
	(*size_a)--;
}
void ra(int *stack_a, int size_a)
{
	int i;

	i = 0;
	if (size_a <= 1)
		return;
	int temp = stack_a[0];
	while (i < size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size_a - 1] = temp;
}
void rb(int *stack_b, int size_b)
{
	int i;
	i = 0;
	if (size_b <= 1)
		return;
	int temp = stack_b[0];
	while (1 < size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[size_b - 1] = temp;
}
void rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	ra(stack_a, size_a);
	rb(stack_b, size_b);
}