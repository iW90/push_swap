/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:09:18 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 16:11:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

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

void	exit_program(int ret, char *msg, t_list *lst)
{
	if (lst)
		ft_lstclear(lst);
	if (msg)
		ft_putstr_fd(msg, 2);
	exit(ret);
}
