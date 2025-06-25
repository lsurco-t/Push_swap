/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:10:28 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/25 23:18:27 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_elements(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_elements(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_elements(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quicksort(int *arr, int low, int high)
{
	int	part_index;

	if (low < high)
	{
		part_index = partition(arr, low, high);
		quicksort(arr, low, part_index - 1);
		quicksort(arr, part_index + 1, high);
	}
}

int	find_median(int *stack, int size)
{
	int	*temp_array;
	int	median;
	int	i;

	temp_array = (int *)malloc(sizeof(int) * size);
	if (!temp_array)
		ft_error();
	i = 0;
	while (i < size)
	{
		temp_array[i] = stack[i];
		i++;
	}
	quicksort(temp_array, 0, size - 1);
	median = temp_array[size / 2];
	free(temp_array);
	return (median);
}

void	optimized_push(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	median;
	int	pushed;
	int	target_pushes;
	int	rotations;

	median = find_median(stack_a, *size_a);
	pushed = 0;
	target_pushes = *size_a - 3;
	rotations = 0;
	while (pushed<target_pushes && * size_a> 3)
	{
		if (stack_a[0] < median)
		{
			pb(stack_a, stack_b, size_a, size_b);
			pushed++;
			rotations = 0;
		}
		else
		{
			ra(stack_a, *size_a);
			rotations++;
			if (rotations >= *size_a)
				break ;
		}
	}
	while (*size_a > 3)
		pb(stack_a, stack_b, size_a, size_b);
}
