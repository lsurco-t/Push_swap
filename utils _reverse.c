/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils _reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:54:30 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/11 11:45:35 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *stack_a, int size_a)
{
	int	temp;

	if (size_a <= 1)
		return ;
	temp = stack_a[size_a - 1];
	for (int i = size_a - 1; i > 0; i--)
		stack_a[i] = stack_a[i - 1];
	stack_a[0] = temp;
}
void	rrb(int *stack_b, int size_b)
{
	int	temp;

	if (size_b <= 1)
		return ;
	temp = stack_b[size_b - 1];
	for (int i = size_b - 1; i > 0; i--)
		stack_b[i] = stack_b[i - 1];
	stack_b[0] = temp;
}
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rra(stack_a, size_a);
	rrb(stack_b, size_b);
}
