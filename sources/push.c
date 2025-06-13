/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:53:25 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/13 12:10:03 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_b == 0)
		return ;
	stack_a[*size_a] = stack_b[*size_b - 1];
	(*size_a)++;
	(*size_b)--;
}

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_a == 0)
		return ;
	stack_b[*size_b] = stack_a[*size_a - 1];
	(*size_b)++;
	(*size_a)--;
}
