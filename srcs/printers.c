/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:33 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/23 22:10:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/* TESTER: PRINT LISTS
 * Imprime os números da lista linkada.
 */
static void	stack_full_screen(t_list *a, t_list *b)
{
	if (!a && !b)
		return ;
	if (!a)
		printf("\t\t\t\t\t\t");
	else
	{
		printf("i:%i\t*\t%i\t*\t", a->index, a->num);
		if (a->prev)
			printf("(p-%i)\t", a->prev->num);
		else
			printf(" head\t");
		if (a->next)
			printf("(n-%i)\t", a->next->num);
		else
			printf(" tail\t");
	}
	printf("   \t|   ");
	if (b)
	{
		printf("*\t  %i\t*", b->num);
		if (b->prev)
			printf("\t(p-%i)\t", b->prev->num);
		else
			printf("\thead\t");
		if (b->next)
			printf("(n-%i)\t", b->next->num);
		else
			printf(" tail\t");
		printf("\ti:%i", b->index);
	}
	printf("\n");
	t_list *a_next = a ? a->next : NULL;
	t_list *b_next = b ? b->next : NULL;
	if (a_next || b_next)
		stack_full_screen(a_next, b_next);
}

void	print_full_stacks(t_stacks *s)
{
	for (int i = 0; i < 111; i++)
		write(1, "-", 1);
	printf("\n\t*    Stack A\t*\t\t\t\t|   *  Stack B\t*\n\t*\t\t*\t\t\t\t|   *\t\t*\n");
	stack_full_screen(s->stack_a, s->stack_b);
	for (int i = 0; i < 111; i++)
		write(1, "-", 1);
	write(1, "\n", 1);
}

/*
./push_swap 8 47 25 7 81 6 32 44 12 53 26 93 55 51 50 92 58 10 74 24 2 65 73 42 36 57 13 94 82 19 64 69 59 54 20 3 48 98 49 23 75 9 5 89 85 35 87 67 91 39 95 27 60 17 21 0 88 61 37 31 80 71 77 86 30 70 4 45 38 14 62 15 46 1 52 83 16 84 33 56 96 79 90 11 76 22 43 99 68 72 34 63 66 41 29 78 97 40 28 18 > test.txt 
*/