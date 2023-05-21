/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 20:38:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* VERIFICAÇÃO DE LISTA EM ORDEM CRESCENTE
 * Se estiver ordenada, retorna 'true'.
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
		//print_list(stks->stack_a);
		print_list(stks->stack_b);
	}
}
			//ft_printf("Four or more numbers:\n");

int	main(int argc, char **argv)
{
	t_stacks	stks;
	int			*index;

	if (argc == 1)
		exit_program(1, "", NULL);
	stks = (t_stacks){0};
	stks.i_max = argc - 2;
	stks.a_size = argc - 1;
	index = malloc(sizeof(int) * stks.a_size);
	if (!index)
		exit_program(1, "Error\n", NULL);
	stks.stack_a = parse_list(argc, argv, index);
	quick_sort(index, 0, stks.i_max);
	parse_index(index, stks.stack_a, stks.a_size);
	free(index);
	push_swap_init(stks.a_size, &stks);
	exit_program(0, "", stks.stack_a);
	return (0);
}
