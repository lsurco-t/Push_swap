/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:59:43 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/25 23:47:43 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_closest_bigger(int *stack, int size, int value)
{
	int	i;
	int	closest;
	int	pos;
	int	found;

	i = 0;
	found = 0;
	closest = 2147483647;
	pos = 0;
	while (i < size)
	{
		if (stack[i] > value && stack[i] < closest)
		{
			closest = stack[i];
			pos = i;
			found = 1;
		}
		i++;
	}
	if (found)
		return (pos);
	return (0);
}

int	insert_position(int *stack, int size, int value)
{
	int	max_pos;
	int	min_pos;

	max_pos = find_max_pos(stack, size);
	min_pos = find_min_pos(stack, size);
	if (value > stack[max_pos] || value < stack[min_pos])
		return ((max_pos + 1) % size);
	return (find_closest_bigger(stack, size, value));
}

static void	update_best_move(t_move *best, t_move *candidate)
{
	int	total_cost;

	if ((candidate->cost_a >= 0 && candidate->cost_b >= 0)
		|| (candidate->cost_a < 0 && candidate->cost_b < 0))
	{
		if (ft_abs(candidate->cost_a) > ft_abs(candidate->cost_b))
			total_cost = ft_abs(candidate->cost_a);
		else
			total_cost = ft_abs(candidate->cost_b);
	}
	else
		total_cost = ft_abs(candidate->cost_a) + ft_abs(candidate->cost_b);
	if (total_cost < best->total_cost)
	{
		best->a_index = candidate->a_index;
		best->b_index = candidate->b_index;
		best->cost_a = candidate->cost_a;
		best->cost_b = candidate->cost_b;
		best->total_cost = total_cost;
	}
}

int	cost_sort(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
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
