/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:59:43 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 21:31:11 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	insert_position(int *stack, int size, int value)
{
	int	i;
	int	pos;
	int	diff;
	int	min_diff;

	i = 0;
	pos = 0;
	min_diff = 2147483647;
	while (i < size)
	{
		diff = stack[i] - value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			pos = i;
		}
		i++;
	}
	if (min_diff == 2147483647)
		pos = find_max_pos(stack, size) + 1;
	if (pos == size)
		pos = 0;
	return (pos);
}

static void	update_best_move(t_move *best, t_move *candidate)
{
	int	total_cost;

	if ((candidate->cost_a >= 0 && candidate->cost_b >= 0)
		|| (candidate->cost_a < 0 && candidate->cost_b < 0))
	{
		if (abs(candidate->cost_a) > abs(candidate->cost_b))
			total_cost = abs(candidate->cost_a);
		else
			total_cost = abs(candidate->cost_b);
	}
	else
		total_cost = abs(candidate->cost_a) + abs(candidate->cost_b);
	if (total_cost < best->total_cost)
	{
		best->a_index = candidate->a_index;
		best->b_index = candidate->b_index;
		best->cost_a = candidate->cost_a;
		best->cost_b = candidate->cost_b;
		best->total_cost = total_cost;
	}
}

t_move	find_best_move(int *stack_a, int *stack_b, int size_a, int size_b)
{
	t_move	best;
	t_move	candidate;
	int		i;

	best.total_cost = 2147483647;
	i = 0;
	while (i < size_b)
	{
		candidate.a_index = insert_position(stack_a, size_a, stack_b[i]);
		candidate.b_index = i;
		candidate.cost_a = cost_sort(size_a, candidate.a_index);
		candidate.cost_b = cost_sort(size_b, i);
		update_best_move(&best, &candidate);
		i++;
	}
	return (best);
}
