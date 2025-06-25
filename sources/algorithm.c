/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:38:31 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/25 23:10:14 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(int *stack_a, int *stack_b, int size_a, int size_b)
{
	(void)stack_b;
	(void)size_b;
	if (size_a == 2 && stack_a[0] > stack_a[1])
	{
		sa(stack_a, size_a);
		return ;
	}
	while (!(stack_a[0] < stack_a[1] && stack_a[1] < stack_a[2]))
	{
		if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2])
			ra(stack_a, size_a);
		else if (stack_a[1] > stack_a[0] && stack_a[1] > stack_a[2])
			rra(stack_a, size_a);
		if (stack_a[0] > stack_a[1])
			sa(stack_a, size_a);
	}
}

void	sort_five(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	min_pos;
	int	r;

	while (*size_a > 3)
	{
		min_pos = find_min_pos(stack_a, *size_a);
		if (min_pos == 0)
			pb(stack_a, stack_b, size_a, size_b);
		else if (min_pos <= *size_a / 2)
		{
			while (min_pos-- > 0)
				ra(stack_a, *size_a);
			pb(stack_a, stack_b, size_a, size_b);
		}
		else
		{
			r = *size_a - min_pos;
			while (r-- > 0)
				rra(stack_a, *size_a);
			pb(stack_a, stack_b, size_a, size_b);
		}
	}
	sort_three(stack_a, stack_b, *size_a, *size_b);
	while (*size_b > 0)
		pa(stack_a, stack_b, size_a, size_b);
}

void	greedy_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	t_move	best_move;

	if (*size_a > 100)
		optimized_push(stack_a, stack_b, size_a, size_b);
	else
	{
		while (*size_a > 3)
			pb(stack_a, stack_b, size_a, size_b);
	}
	sort_three(stack_a, stack_b, *size_a, *size_b);
	while (*size_b > 0)
	{
		best_move = find_best_move(stack_a, stack_b, *size_a, *size_b);
		while (best_move.cost_a > 0 && best_move.cost_b > 0)
		{
			rr(stack_a, stack_b, *size_a, *size_b);
			best_move.cost_a--;
			best_move.cost_b--;
		}
		while (best_move.cost_a < 0 && best_move.cost_b < 0)
		{
			rrr(stack_a, stack_b, *size_a, *size_b);
			best_move.cost_a++;
			best_move.cost_b++;
		}
		rotate_stack_top(stack_a, *size_a, best_move.cost_a, 'a');
		rotate_stack_top(stack_b, *size_b, best_move.cost_b, 'b');
		pa(stack_a, stack_b, size_a, size_b);
	}
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

void	algorithm(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_a <= 0)
		ft_error();
	else if (*size_a == 1 || is_stack_sorted(stack_a, *size_a))
		return ;
	else if (*size_a == 2 || *size_a == 3)
		sort_three(stack_a, stack_b, *size_a, *size_b);
	else if (*size_a == 4 || *size_a == 5)
		sort_five(stack_a, stack_b, size_a, size_b);
	else if (*size_a > 5)
	{
		greedy_sort(stack_a, stack_b, size_a, size_b);
		final_rotation(stack_a, *size_a);
	}
	else
		ft_error();
}
