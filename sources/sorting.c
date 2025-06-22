/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/22 11:53:58 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_chunk(int *stack_a, int *stack_b, int size_a, int size_b)
{
	
}

void	large_chunk(int *stack_a, int *stack_b, int size_a, int size_b)
{
	
}

int	find_min_pos(int *stack, int size)
{
    int i = 0;
    int min = stack[0];
    int min_pos = 0;
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
