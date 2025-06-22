/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:36:26 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 23:05:11 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack_top(int *stack, int size, int cost, char stack_id)
{
	if (cost)
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

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*copy_and_sort(int *stack, int size)
{
	int	*copy;
	int	i;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = stack[i];
		i++;
	}
	ft_sort_int_tab(copy, size);
	return (copy);
}

int	has_chunk_number(int *stack, int size, int min, int max)
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

int	cost_sort(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}
