/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 23:41:04 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_forward_index(int *stack, int size, int min, int max)
{
    int	i;

    i = 0;
    while (i < size)
    {
        if (stack[i] >= min && stack[i] <= max)
            return (i);
        i++;
    }
    return (-1);
}

static int	find_backward_index(int *stack, int size, int min, int max)
{
    int	i;

    i = size - 1;
    while (i >= 0)
    {
        if (stack[i] >= min && stack[i] <= max)
            return (size - i);
        i--;
    }
    return (-1);
}

static void push_one_chunk(t_stacks *stacks, t_chunk chunk)
{
    int forward_index;
    int backward_index;

    forward_index = find_forward_index(stacks->a, *(stacks->size_a), chunk.min, chunk.max);
    backward_index = find_backward_index(stacks->a, *(stacks->size_a), chunk.min, chunk.max);
    if (forward_index == -1 && backward_index == -1)
        return; 
    if (forward_index != -1 && (backward_index == -1 || forward_index <= backward_index))
    {
        while (forward_index-- > 0)
            ra(stacks->a, *(stacks->size_a));
    }
    else if (backward_index != -1)
    {
        while (backward_index-- > 0)
            rra(stacks->a, *(stacks->size_a));
    }
    pb(stacks->a, stacks->b, stacks->size_a, stacks->size_b);
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
    i = 7;
    while (i >= 0)
    {
        chunk.min = sorted[i * chunk_size];
        if (i == 7)
            chunk.max = sorted[*size_a - 1];
        else
            chunk.max = sorted[(i + 1) * chunk_size - 1];
        while (has_chunk_number(stack_a, *size_a, chunk.min, chunk.max))
            push_one_chunk(&stacks, chunk);
        i--;
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
    i = 19;
    while (i >= 0)
    {
        chunk.min = sorted[i * chunk_size];
        if (i == 19)
            chunk.max = sorted[*size_a - 1];
        else
            chunk.max = sorted[(i + 1) * chunk_size - 1];
        while (has_chunk_number(stack_a, *size_a, chunk.min, chunk.max))
            push_one_chunk(&stacks, chunk);
        i--;
    }
    free(sorted);
}

