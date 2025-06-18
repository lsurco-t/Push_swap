/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:53:25 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/18 19:12:46 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_b == 0)
		return ;
	i = *size_a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	(*size_a)++;
	i = *size_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	(*size_b)--;
	stack_b[*size_b] = 0; // Clear the last element to avoid garbage value
	write(1, "pa\n", 3);
}

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_a == 0)
		return ;
	i = *size_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	(*size_b)++;
	i = 0;
	while (i < *size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(*size_a)--;
	stack_a[*size_a] = 0; // Clear the last element to avoid garbage value
	write(1, "pb\n", 3);
}
