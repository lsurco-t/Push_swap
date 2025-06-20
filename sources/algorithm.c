/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:38:31 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/20 20:46:59 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(int *stack_a, int *stack_b, int size_a, int size_b)
{
	(void)stack_b;
	(void)size_b;

	if (size_a == 2)
	{
		if (stack_a[0] > stack_a[1])
			sa(stack_a, size_a);
		return ;
	}
	if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2] && stack_a[0] < stack_a[2])
		sa(stack_a, size_a);
	else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
	{
		sa(stack_a, size_a);
		rra(stack_a, size_a);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]	&& stack_a[0] > stack_a[2])
		ra(stack_a, size_a);
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]	&& stack_a[0] < stack_a[2])
	{
		sa(stack_a, size_a);
		ra(stack_a, size_a);
	}
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[0] > stack_a[2])
		rra(stack_a, size_a);
}

void	sort_four_to_five(int *stack_a, int *stack_b, int *size_a, int *size_b)
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

/*void	sort_six_to_hundred(int *stack_a, int *stack_b, int size_a, int size_b)
{
}

void	sort_hundred_to_five_hundred(int *stack_a, int *stack_b, int size_a,
		int size_b)
{
	// Implement sorting logic for one hundred to five hundred elements
}*/
void	algorithm(int *stack_a, int *stack_b, int size_a, int size_b)
{
	if (size_a <= 0)
		ft_error();
	else if (size_a == 1)
		return ;
	else if (size_a == 2 || size_a == 3)
		sort_three(stack_a, stack_b, size_a, size_b);
	else if (size_a == 4 || size_a == 5)
		sort_four_to_five(stack_a, stack_b, &size_a, &size_b);
	/*else if (size_a > 5 && size_a <= 100)
		sort_six_to_hundred(stack_a, stack_b, size_a, size_b);
	else if (size_a > 100 && size_a <= 500)
		sort_hundred_to_five_hundred(stack_a, stack_b, size_a, size_b);*/
	else
		ft_error();
}
