/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 18:58:09 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	chunk_size;
	int	*sorted;
	int	i;
	int	min;
	int	max;
	int	pos;

	sorted = copy_and_sort(stack_a, *size_a);
	chunk_size = *size_a / 10;
	i = 0;
	while (i < 10)
	{
		min = sorted[i * chunk_size];
		if (i == 9)
			max = sorted[*size_a - 1];
		else
			max = sorted[(i + 1) * chunk_size - 1];
		while (has_chunk_member(stack_a, *size_a, min, max))
		{
			pos = find_closest_chunk_member(stack_a, *size_a, min, max);
			if (pos != -1)
			{
				rotate_stack_top(stack_a, *size_a, pos, 'a');
				pb(stack_a, stack_b, *size_a, *size_b);
			}
		}
		i++;
	}
	free(sorted);
}

void	large_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	chunk_size;
	int	*sorted;
	int	i;
	int	min;
	int	max;
	int	pos;

	sorted = copy_and_sort(stack_a, *size_a);
	chunk_size = *size_a / 10;
	i = 0;
	while (i < 10)
	{
		min = sorted[i * chunk_size];
		if (i == 9)
			max = sorted[*size_a - 1];
		else
			max = sorted[(i + 1) * chunk_size - 1];
		while (has_chunk_member(stack_a, *size_a, min, max))
		{
			pos = find_closest_chunk_member(stack_a, *size_a, min, max);
			if (pos != -1)
			{
				rotate_stack_top(stack_a, *size_a, pos, 'a');
				pb(stack_a, stack_b, *size_a, *size_b);
			}
		}
		i++;
	}
	free(sorted);
}

int	cost_sort(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
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
