/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/04/24 20:35:58 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	num_validator(char **num)
{
	int	n;
	
	num++;
	while (*num)
	{
		if (!ft_isalldigit(num))
			exit_program(1, "Error.\n", 2);
		num++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		exit_program(1, "Error.\n", 2);
		return (0);
	}
	num_validator(**argv);

	return (0);
}
