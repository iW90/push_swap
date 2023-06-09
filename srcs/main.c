/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/26 21:03:17 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* INICIALIZADOR
 * Chama o sort correto de acordo com
 * a quantidade de números de entrada.
 */
static void	push_swap_init(int size, t_stacks *stks)
{
	if (!is_sorted(stks->stack_a))
	{
		if (size == 2)
			sa(stks);
		else if (size == 3)
			sort_three(stks);
		else if (size == 4)
			sort_four(stks);
		else if (size == 5)
			sort_five(stks);
		else if (size >= 6)
			push_swap(stks);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stks;
	int			*index;

	if (argc == 1)
		exit_program(1, "", NULL, NULL);
	stks = (t_stacks){0};
	stks.i_max = argc - 2;
	stks.a_size = argc - 1;
	index = malloc(sizeof(int) * stks.a_size);
	if (!index)
		exit_program(1, "Error\n", NULL, NULL);
	stks.stack_a = parse_list(argc, argv, index);
	quick_sort(index, 0, stks.i_max);
	parse_index(index, stks.stack_a, stks.a_size);
	push_swap_init(stks.a_size, &stks);
	exit_program(0, "", stks.stack_a, index);
	return (0);
}
