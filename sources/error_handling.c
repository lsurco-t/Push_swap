/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:36:18 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/06/17 19:08:38 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_valid_int(const char *str)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

void	validate_input(int ac, char **av)
{
	int	i;

	if (ac < 2)
		ft_error();
	i = 1;
	while (i < ac)
	{
		if (!is_valid_int(av[i]))
			ft_error();
		i++;
	}
}
