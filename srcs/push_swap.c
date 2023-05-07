/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/07 18:04:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	num_validator(int total, char **num)
{
	int i;

	i = 1;
	while (num[i] < total)
	{
		if (!ft_isalldigit(num[i]))
			exit_program(1, "Error.\n", 2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	num_validator(argc, argv);
	//validar se há números repetidos
	//atoi e distribuição dos números na lista linkada
	return (0);
}
