/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:09:18 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/23 21:53:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

long	ft_atol(const char *str)
{
	long	number;
	int		signal;

	signal = 1;
	number = 0;
	if (*str == '-')
		signal = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * signal);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	exit_program(int ret, char *msg, t_list *stk_a, t_list *stk_b)
{
	if (stk_a)
		ft_lstclear(stk_a);
	if (stk_b)
		ft_lstclear(stk_b);
	if (msg)
		ft_putstr_fd(msg, 2);
	exit(ret);
}

int	ft_strncmp(char *str_a, char *str_b, int n)
{
	int	i;

	if (!str_a || !str_b)
		return (0);
	i = 0;
	while (i != n)
	{
		if (str_a[i] != str_b[i])
			return (0);
		i++;
	}
	return (1);
}
