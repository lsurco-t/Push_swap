/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 21:49:57 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_one_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b, t_chunk chunk)
{
    int	count;

    count = 0;
    while (count < *size_a)
    {
        if (stack_a[0] >= chunk.min && stack_a[0] <= chunk.max)
        {
            pb(stack_a, stack_b, size_a, size_b);
            break;
        }
        else
            ra(stack_a, *size_a);
        count++;
    }
}
void	small_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int		*sorted;
    int		chunk_size;
    int		i;
    int		pushed;
    t_chunk	chunk;

    sorted = copy_and_sort(stack_a, *size_a);
    chunk_size = *size_a / 5;
    i = 0;
    while (i < 5)
    {
        chunk.min = sorted[i * chunk_size];
        if (i == 4)
            chunk.max = sorted[*size_a - 1];
        else
            chunk.max = sorted[(i + 1) * chunk_size - 1];
        pushed = 0;
        while (pushed < chunk_size && *size_a > 0)
        {
            push_one_chunk(stack_a, stack_b, size_a, size_b, chunk);
            pushed++;
        }
        i++;
    }
    free(sorted);
}

void	large_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int		*sorted;
    int		chunk_size;
    int		i;
    int		pushed;
    t_chunk	chunk;

    sorted = copy_and_sort(stack_a, *size_a);
    chunk_size = *size_a / 20;
    i = 0;
    while (i < 20)
    {
        chunk.min = sorted[i * chunk_size];
        if (i == 19)
            chunk.max = sorted[*size_a - 1];
        else
            chunk.max = sorted[(i + 1) * chunk_size - 1];
        pushed = 0;
        while (pushed < chunk_size && *size_a > 0)
        {
            push_one_chunk(stack_a, stack_b, size_a, size_b, chunk);
            pushed++;
        }
        i++;
    }
    free(sorted);
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
