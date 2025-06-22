/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 22:48:32 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void push_one_chunk(t_stacks *stacks, t_chunk chunk)
{
    int count = 0;
    while (count < *(stacks->size_a))
    {
        if (stacks->a[0] >= chunk.min && stacks->a[0] <= chunk.max)
        {
            pb(stacks->a, stacks->b, stacks->size_a, stacks->size_b);
            break;
        }
        else
            ra(stacks->a, *(stacks->size_a));
        count++;
    }
}
void	small_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int		*sorted;
    int		chunk_size;
    int		i;
    t_chunk	chunk;
	t_stacks stacks;

	stacks = (t_stacks){stack_a, stack_b, size_a, size_b};
    sorted = copy_and_sort(stack_a, *size_a);
    chunk_size = *size_a / 8;
    i = 0;
    while (i < 8)
    {
        chunk.min = sorted[i * chunk_size];
        if (i == 7)
            chunk.max = sorted[*size_a - 1];
        else
            chunk.max = sorted[(i + 1) * chunk_size - 1];
        while (has_chunk_number(stack_a, *size_a, chunk.min, chunk.max))
    		push_one_chunk(&stacks, chunk);
        i++;
    }
    free(sorted);
}

void	large_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int		*sorted;
    int		chunk_size;
    int		i;
    t_chunk	chunk;
	t_stacks stacks;

	stacks = (t_stacks){stack_a, stack_b, size_a, size_b};
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
        while (has_chunk_number(stack_a, *size_a, chunk.min, chunk.max))
            push_one_chunk(&stacks, chunk);
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
