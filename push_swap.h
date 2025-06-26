/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:54:14 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/26 16:38:55 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define EXIT_FAILURE 1

typedef struct s_move
{
	int	a_index;
	int	b_index;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}		t_move;

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
int		algorithm(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	sort_three(int *stack_a, int *stack_b, int size_a, int size_b);
void	sort_five(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	greedy_sort(int *stack_a, int *stack_b, int *size_a, int *size_b);

// Validation functions
int		*validate_input(int ac, char **av, int *out_count);
int		is_valid_int(const char *str);
int		is_duplicate(int *stack, int size, int nbr);
char	**parse_args(int ac, char **av, int *out_count);

// Error handling
void	ft_error(void);
void	memory_cleanup(int *stack_a, int *stack_b);
void	clean_array(char **array);
void	clean_array_exit(char **array, int *numbers);
void	exit_with_cleanup(int ac, char **args, int *numbers);

// Sorting functions
int		find_min_pos(int *stack, int size);
int		find_max_pos(int *stack, int size);
void	final_rotation(int *stack_a, int size_a);
void	rotate_stack_top(int *stack, int size, int pos, char stack_id);
int		is_stack_sorted(int *stack, int size);

int		insert_position(int *stack, int size, int value);
t_move	find_best_move(int *stack_a, int *stack_b, int size_a, int size_b);
int		cost_sort(int size, int pos);

// Median optimization
int		find_median(int *stack, int size);
void	optimized_push(int *stack_a, int *stack_b, int *size_a, int *size_b);

#endif