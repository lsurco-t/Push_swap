/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:36:26 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/23 12:46:20 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack_top(int *stack, int size, int cost, char stack_id)
{
	if (cost > 0)
	{
		while (cost > 0)
		{
			if (stack_id == 'a')
				ra(stack, size);
			else
				rb(stack, size);
			cost--;
		}
	}
	else if (cost < 0)
	{
		while (cost < 0)
		{
			if (stack_id == 'a')
				rra(stack, size);
			else
				rrb(stack, size);
			cost++;
		}
	}
}

int	cost_sort(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

int	is_stack_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
