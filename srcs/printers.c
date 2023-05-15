/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:33 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 21:07:11 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* TESTER: PRINT LIST
 * Imprime os números da lista linkada.
 */
void	print_list(t_list *lst)
{
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
		while (lst)
		{
			ft_printf("%i: %i\t", lst->index, lst->num);
			lst = lst->next;
		}
		ft_printf("\n");
	}
}

/* TESTER: PRINT LISTS
 * Imprime os números da lista linkada.
 */
static void	stack_screen(t_list *a, t_list *b)
{
	if (!a && !b)
		return ;
	if (!a)
		ft_printf("\t\t\t\t\t\t");
	else
	{
		ft_printf("\t*\t%i\t*\t\t\t", a->num);
	}
	if (b)
	{
		ft_printf("*\t%i\t*", b->num);
	}
	ft_printf("\n");
	t_list *a_next = a ? a->next : NULL;
	t_list *b_next = b ? b->next : NULL;
	if (a_next || b_next)
		stack_screen(a_next, b_next);
}

void	print_stacks(t_list *a, t_list *b)
{
	for (int i = 0; i < 73; i++)
		write(1, "-", 1);
	ft_printf("\n\t*    Stack A\t*\t\t\t*    Stack B\t*\n\t*\t\t*\t\t\t*\t\t*\n");
	stack_screen(a, b);
	for (int i = 0; i < 73; i++)
		write(1, "-", 1);
	write(1, "\n", 1);
}
