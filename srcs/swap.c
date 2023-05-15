/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 20:14:59 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* FUNÇÃO SWAP
 * Inverte a posição dos dois primeiros elementos de uma mesma pilha.
 * Usada para os movimentos 'sa', 'sb' e 'ss'.
 */
static t_list	*ft_swap(t_list *item_a, t_list *item_b)
{
	t_list	*temp;

	if (!item_a || !item_b)
		return (0);
	if (item_a->prev)
		item_a->prev->next = item_b;
	if (item_b->next)
		item_b->next->prev = item_a;
	temp = item_b->next;
	item_b->next = item_a;
	item_a->next = temp;
	temp = item_a->prev;
	item_a->prev = item_b;
	item_b->prev = temp;
	return (item_b);
}

void	sa(t_stacks *stacks)
{
	stacks->stack_a = ft_swap(stacks->stack_a, stacks->stack_a->next);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	stacks->stack_b = ft_swap(stacks->stack_b, stacks->stack_b->next);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	stacks->stack_a = ft_swap(stacks->stack_a, stacks->stack_a->next);
	stacks->stack_b = ft_swap(stacks->stack_b, stacks->stack_b->next);
	ft_putstr_fd("ss\n", 1);
}
