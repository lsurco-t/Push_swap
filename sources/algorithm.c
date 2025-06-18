/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:38:31 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/18 20:46:42 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(int *stack_a, int size_a)
{
	if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[0] < stack_a[2])
		sa(stack_a, size_a);
	else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
	{
		sa(stack_a, size_a);
		rra(stack_a, size_a);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[0] > stack_a[2])
		ra(stack_a, size_a);
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] < stack_a[2])
	{
		sa(stack_a, size_a);
		ra(stack_a, size_a);
	}
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] > stack_a[2])
		rra(stack_a, size_a);
}

void	algorithm(int *stack_a, int *stack_b, int size_a, int size_b)
{
	(void)stack_b;
	(void)size_b;
	if (size_a == 2 && stack_a[0] > stack_a[1])
		sa(stack_a, size_a);
	else if (size_a == 3)
		sort_three(stack_a, size_a);
}
