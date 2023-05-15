/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:12 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 20:48:18 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* FUNÇÃO REVERSE ROTATE
 * Coloca o último elemento de uma pilha no início dela.
 * (primeiro elemento da lista no final dela).
 * Usada para os movimentos 'rra', 'rrb' e 'rrr'.
 */
static t_list	*ft_reverse_rotate(t_list *item_a)
{
	t_list	*item_z;

	item_z = item_a;
	while (item_z->next)
		item_z = item_z->next;
	item_z->prev->next = NULL;
	item_z->prev = NULL;
	item_z->next = item_a;
	item_a->prev = item_z;
	return (item_z);
}

void	rra(t_stacks *stacks)
{
	if (stacks->stack_a && stacks->stack_a)
	{
		stacks->stack_a = ft_reverse_rotate(stacks->stack_a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stacks *stacks)
{
	if (stacks->stack_b && stacks->stack_b->next)
	{
		stacks->stack_b = ft_reverse_rotate(stacks->stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stacks *stacks)
{
	if (stacks->stack_a && stacks->stack_a->next && \
		stacks->stack_b && stacks->stack_b->next)
	{
		stacks->stack_a = ft_reverse_rotate(stacks->stack_a);
		stacks->stack_b = ft_reverse_rotate(stacks->stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}
