/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/07 21:13:47 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	num_validator(int total, char **num)
{
	int	i;

	i = 1;
	while (num[i] < total)
	{
		if (!ft_isalldigit(num[i]))
			exit_program(1, "Error.\n", 0);
		i++;
	}
}

static t_list parse_list(int total, char **num)
{
	t_list	*lst;
	int		i;
	long	n;
	
	lst = 0;
	i = 1;
	while (num[i] < total)
	{
		n = ft_atol(num[i]);
		if (num[i] <= INT_MIN || num[i] >= INT_MAX)
			exit_program(1, "Error.\n", lst);
		lst = ft_newnode(n, lst);
		i++;
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_program(1, "", 0);
	num_validator(argc, argv);
	//atol e distribuição dos números na lista linkada
	//lembrar de dar free nos nodos que já foram alocados
	//validar se há números repetidos
	return (0);
}
