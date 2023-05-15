/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 21:06:51 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* VERIFICAÇÃO DE LISTA EM ORDEM CRESCENTE
 * Se estiver ordenada, retorna 'true'.
 */
static void	push_swap_init(int size, t_stacks *stks)
{
	if (size == 2 && !is_sorted(stks->stack_a))
	{
		sa(stks);
		ft_printf("Two numbers:\n");
		print_list(stks->stack_a);
	}
	else if (size == 3)
	{
		ft_printf("Three numbers:\n");
		print_list(stks->stack_a);
	}
	else if (size >= 4)
	{
		ft_printf("Four or more numbers:\n");
		//print_list(stks->stack_a);
		pa(stks);
		print_stacks(stks->stack_a, stks->stack_b);
		pb(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		pb(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		pa(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		sa(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		sb(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		ss(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		ra(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		rb(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		rr(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		rra(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		rrb(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
		rrr(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stks;

	if (argc == 1)
		exit_program(1, "", NULL);
	stks = (t_stacks){0};
	stks.t_size = argc - 1;
	stks.a_size = stks.t_size;
	stks.stack_a = parse_list(argc, argv);
	push_swap_init(stks.t_size, &stks);
	exit_program(0, "", stks.stack_a);
	return (0);
}
