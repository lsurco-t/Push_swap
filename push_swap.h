/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:54:14 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/20 20:28:43 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
#include <stdio.h> // For debugging purposes, can be removed later

# define EXIT_FAILURE 1

// Push_swap operations
void	sa(int *stack_a, int size_a);
void	sb(int *stack_b, int size_b);
void	ss(int *stack_a, int *stack_b, int size_a, int size_b);
void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	ra(int *stack_a, int size_a);
void	rb(int *stack_b, int size_b);
void	rr(int *stack_a, int *stack_b, int size_a, int size_b);
void	rra(int *stack_a, int size_a);
void	rrb(int *stack_b, int size_b);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);

// Sorting algorithm
void	algorithm(int *stack_a, int *stack_b, int size_a, int size_b);

// Memory management
void	memory_cleanup(int *stack_a, int *stack_b);

// Validation functions
int		*validate_input(int ac, char **av, int *out_count);
int		is_valid_int(const char *str);
int		is_duplicate(int *stack, int size, int nbr);
void	clean_array(char **array);
char	**parse_args(int ac, char **av, int *out_count);

// Error handling
void	ft_error(void);

// Sorting functions
int		find_min_pos(int *stack, int size);
void	sort_three(int *stack_a, int *stack_b, int size_a, int size_b);
void	sort_four_to_five(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	small_chunk(int *stack_a, int *stack_b, int size_a, int size_b);
void	large_chunk(int *stack_a, int *stack_b, int size_a, int size_b);

// Additional sorting functions (to be implemented)
// void	sort_six_to_hundred(int *stack_a, int *stack_b, int size_a, int size_b);
// void	sort_hundred_to_five_hundred(int *stack_a, int *stack_b, int size_a, int size_b);

#endif