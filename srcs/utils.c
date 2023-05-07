/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:09:18 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/07 19:29:47 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *str)
{
	long	number;
	int		signal;

	signal = 1;
	number = 0;
	if (*str == '-')
		signal = -1;
	while (*str && *str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * signal);
}

int	ft_isalldigit(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	exit_program(int ret, char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(ret);
}
