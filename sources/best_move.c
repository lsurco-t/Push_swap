/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:59:43 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/23 10:45:20 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	insert_position(int *stack, int size, int value)
{
    int	i;
    int	pos = 0;
    int	max_pos = find_max_pos(stack, size);
    int	min_pos = find_min_pos(stack, size);

    // If value is outside current range, insert after max
    if (value > stack[max_pos] || value < stack[min_pos])
        return ((max_pos + 1) % size);

    // Find the position where value should be inserted
    // Look for the smallest element that is greater than value
    int found = 0;
    int closest_bigger = 2147483647;
    
    for (i = 0; i < size; i++)
    {
        if (stack[i] > value && stack[i] < closest_bigger)
        {
            closest_bigger = stack[i];
            pos = i;
            found = 1;
        }
    }
    
    return (found ? pos : 0);
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



