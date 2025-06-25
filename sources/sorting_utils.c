/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:01:53 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/25 23:50:05 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_pos(int *stack, int size)
{
	int	i;
	int	max;
	int	max_pos;

	max = stack[0];
	max_pos = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

int	find_min_pos(int *stack, int size)
{
	int	i;
	int	min;
	int	min_pos;

	min = stack[0];
	min_pos = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

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

void	final_rotation(int *stack_a, int size_a)
{
	int	min_pos;
	int	r;

	min_pos = find_min_pos(stack_a, size_a);
	if (min_pos == 0)
		return ;
	if (min_pos <= size_a / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a, size_a);
	}
	else
	{
		r = size_a - min_pos;
		while (r-- > 0)
			rra(stack_a, size_a);
	}
}
