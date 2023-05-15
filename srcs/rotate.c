/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:07 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 20:26:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* FUNÇÃO ROTATE
 * Coloca o primeiro elemento de uma pilha no final dela
 * (último elemento da lista no início dela).
 * Usada para os movimentos 'ra', 'rb' e 'rr'.
 */
static t_list	*ft_rotate(t_list *item_a)
{
	t_list	*item_z;
	t_list	*first;

	item_z = item_a;
	while (item_z->next)
		item_z = item_z->next;
	item_a->next->prev = NULL;
	first = item_a->next;
	item_a->next = NULL;
	item_a->prev = item_z;
	item_z->next = item_a;
	return (first);
}

void	ra(t_stacks *stacks)
{
	if (stacks->stack_a->next)
	{
		stacks->stack_a = ft_rotate(stacks->stack_a);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stacks *stacks)
{
	if (stacks->stack_b->next)
	{
		stacks->stack_b = ft_rotate(stacks->stack_b);
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stacks *stacks)
{
	if (stacks->stack_a->next && stacks->stack_b->next)
	{
		stacks->stack_a = ft_rotate(stacks->stack_a);
		stacks->stack_b = ft_rotate(stacks->stack_b);
		ft_putstr_fd("rr\n", 1);
	}
}
