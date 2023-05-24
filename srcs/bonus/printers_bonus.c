/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:33 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/23 22:07:59 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include <stdio.h>

/* TESTER: PRINT LISTS
 * Imprime os números da lista linkada.
 */
static void	stack_screen(t_list *a, t_list *b)
{
	if (!a && !b)
		return ;
	if (!a)
		printf("\t\t\t\t\t\t");
	else
	{
		printf("\t*\t%i\t*\t\t\t", a->num);
	}
	if (b)
	{
		printf("*\t%i\t*", b->num);
	}
	printf("\n");
	t_list *a_next = a ? a->next : NULL;
	t_list *b_next = b ? b->next : NULL;
	if (a_next || b_next)
		stack_screen(a_next, b_next);
}

void	print_stacks(t_stacks *s)
{
	for (int i = 0; i < 73; i++)
		write(1, "-", 1);
	printf("\n\t*    Stack A\t*\t\t\t*    Stack B\t*\n\t*\t\t*\t\t\t*\t\t*\n");
	stack_screen(s->stack_a, s->stack_b);
	for (int i = 0; i < 73; i++)
		write(1, "-", 1);
	write(1, "\n", 1);
}
