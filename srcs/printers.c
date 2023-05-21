/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:33 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/21 10:44:41 by inwagner         ###   ########.fr       */
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
			ft_printf("Índice %i:\tNúmero: %i\n", lst->index, lst->num);
			lst = lst->next;
		}
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

void	print_stacks(t_stacks *s)
{
	for (int i = 0; i < 73; i++)
		write(1, "-", 1);
	ft_printf("\n\t*    Stack A\t*\t\t\t*    Stack B\t*\n\t*\t\t*\t\t\t*\t\t*\n");
	stack_screen(s->stack_a, s->stack_b);
	for (int i = 0; i < 73; i++)
		write(1, "-", 1);
	write(1, "\n", 1);
}

static void	stack_full_screen(t_list *a, t_list *b)
{
	if (!a && !b)
		return ;
	if (!a)
		ft_printf("\t\t\t\t\t\t");
	else
	{
		ft_printf("i:%i\t*\t%i\t*\t", a->index, a->num);
		if (a->prev)
			ft_printf("(p-%i)\t", a->prev->num);
		else
			ft_printf(" head\t");
		if (a->next)
			ft_printf("(n-%i)\t", a->next->num);
		else
			ft_printf(" tail\t");
	}
	ft_printf("   \t|   ");
	if (b)
	{
		ft_printf("*\t  %i\t*", b->num);
		if (b->prev)
			ft_printf("\t(p-%i)\t", b->prev->num);
		else
			ft_printf("\thead\t");
		if (b->next)
			ft_printf("(n-%i)\t", b->next->num);
		else
			ft_printf(" tail\t");
		ft_printf("\ti:%i", b->index);
	}
	ft_printf("\n");
	t_list *a_next = a ? a->next : NULL;
	t_list *b_next = b ? b->next : NULL;
	if (a_next || b_next)
		stack_full_screen(a_next, b_next);
}

void	print_full_stacks(t_stacks *s)
{
	for (int i = 0; i < 111; i++)
		write(1, "-", 1);
	ft_printf("\n\t*    Stack A\t*\t\t\t\t|   *  Stack B\t*\n\t*\t\t*\t\t\t\t|   *\t\t*\n");
	stack_full_screen(s->stack_a, s->stack_b);
	for (int i = 0; i < 111; i++)
		write(1, "-", 1);
	write(1, "\n", 1);
}

void	printarr(int *index, int sz)
{
	int	i = 0;
	
	while(i < sz)
	{
		ft_printf("Arr %i: %i\n", i, index[i]);
		i++;
	}
}
