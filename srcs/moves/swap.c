/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 10:19:48 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* FUNÇÃO SWAP
 * Inverte a posição dos dois primeiros elementos de uma mesma pilha.
 * Usada para os movimentos 'sa', 'sb' e 'ss'.
 */
static void	ft_swap(t_list *itemA, t_list *itemB)
{
	t_list	*temp;

	if (!itemA || !itemB)
		return ;
	if (itemA->prev)
		itemA->prev->next = itemB;
	if (itemB->next)
		itemB->next->prev = itemA;
	temp = itemB->next;
	itemB->next = itemA;
	itemA->next = temp;
	temp = itemA->prev;
	itemA->prev = itemB;
	itemB->prev = temp;
}

void	sa(s_stacks *stacks)
{
	ft_swap(stacks->stackA, stacks->stackA->next);
	ft_putstr_fd("sa\n", 1);
}

void	sb(s_stacks *stacks)
{
	ft_swap(stacks->stackB, stacks->stackB->next);
	ft_putstr_fd("sb\n", 1);
}

void	ss(s_stacks *stacks)
{
	ft_swap(stacks->stackA, stacks->stackA->next);
	ft_swap(stacks->stackB, stacks->stackB->next);
	ft_putstr_fd("ss\n", 1);
}
