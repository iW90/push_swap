/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 17:55:03 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* TESTER: PRINT LIST
 * Imprime os números da lista linkada.
 */
static void	print_list(t_list *lst)
{
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
		while (lst)
		{
			ft_printf("%i\t", lst->num);
			lst = lst->next;
		}
		ft_printf("\n");
	}
}

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
		print_list(stks->stack_a);
		pb(stks);
		pb(stks);
		pa(stks);
		pa(stks);
		pa(stks);
		print_list(stks->stack_a);
		print_list(stks->stack_b);
	}
}
		//mini_push_swap();
		//push_swap()

int	main(int argc, char **argv)
{
	t_stacks	stks;

	if (argc == 1)
		exit_program(1, "", NULL);
	stks = (t_stacks){0};
	stks.stack_a = parse_list(argc, argv);
	push_swap_init(--argc, &stks);
	exit_program(0, "", stks.stack_a);
	return (0);
}
