/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 20:33:12 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
}

void	large_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
}

int	best_move(t_move *moves, int size)
{
	int	i;
	int	best_index;
	int	best_cost;

	if (size == 0)
		return (-1);
	best_index = 0;
	best_cost = moves[0].total_cost;
	i = 1;
	while (i < size)
	{
		if (moves[i].total_cost < best_cost)
		{
			best_cost = moves[i].total_cost;
			best_index = i;
		}
		i++;
	}
	return (best_index);
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
