/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:36:26 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 12:46:56 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_top(int *stack, int size, int pos)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack, size);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack, size);
			pos++;
		}
	}
}

int	find_closest_chunk_member(int *stack, int size, int min, int max)
{
	int	i;
	int	best_pos;
	int	best_cost;
	int	cost;

	best_pos = -1;
	best_cost = size + 1;
	if (size == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (stack[i] >= min && stack[i] <= max)
		{
			cost = cost_sort(size, i, stack[i]);
			if (cost < best_cost)
			{
				best_cost = cost;
				best_pos = i;
			}
		}
		i++;
	}
	return (best_pos);
}

int	has_chunk_member(int *stack, int size, int min, int max)
{
	int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (stack[i] >= min && stack[i] <= max)
			return (1);
		i++;
	}
	return (0);
}
