/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:36:18 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/20 23:24:11 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
void	clean_array_exit(char **array, int *numbers)
{
    int	i = 0;
	
    if (array)
    {
        while (array[i])
            free(array[i++]);
        free(array);
    }
    if (numbers)
        free(numbers);
    ft_error();
}

void	clean_array(char **array)
{
    int i = 0;

    if (!array)
        return;
    while (array[i])
        free(array[i++]);
    free(array);
}