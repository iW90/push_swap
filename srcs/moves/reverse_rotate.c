/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:07 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 10:46:32 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* FUNÇÃO REVERSE ROTATE
 * Coloca o último elemento de uma pilha no início dela.
 * (primeiro elemento da lista no final dela).
 * Usada para os movimentos 'rra', 'rrb' e 'rrr'.
 */
static void	ft_reverse_rotate(t_list *itemA)
{
	t_list	*itemZ;

	itemZ = itemA;
	while (itemZ->next)
		itemZ = itemZ->next;
	itemA->next->prev = NULL;
	itemA->next = NULL;
	itemA->prev = itemZ;
	itemZ->next = itemA;
}

void	rra(t_stacks stack)
{
	ft_rotate(stack->stackA);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks stack)
{
	ft_rotate(stack->stackB);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks stack)
{
	ft_rotate(stack->stackA);
	ft_rotate(stack->stackB);
	ft_putstr_fd("rrr\n", 1);
}
