/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:35:17 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/08 12:51:45 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* FUNÇÃO SWAP
 * Inverte a posição dos dois primeiros elementos de uma mesma pilha.
 * Usada para os movimentos 'sa', 'sb' e 'ss'.
 */
void	ft_swap(t_list *itemA, t_list *itemB)
{
	t_list	*temp;

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

/* FUNÇÃO PUSH
 * Coloca o primeiro elemento de uma pilha no topo da outra pilha.
 * Lembrando que existe a possibilidade de ainda não existir lstB,
 * denotando que ela está vazia.
 * Usada para os movimentos 'pa' e 'pb'.
 */
void	ft_push(t_list *stks)
{
	t_list	*temp;
	
	if (stks->stackA->next)
		stks->stackA->next->prev = NULL;
	if (stks->stackB)
		stks->stackB->prev = stks->stackA;
	temp = stks->stackA->next;
	stks->stackA->next = stks->stackB;
	stks->stackB = stks->stackA;
	stks->stackA = temp;
}

/* FUNÇÃO ROTATE
 * Coloca o primeiro elemento de uma pilha no final dela
 * (último elemento da lista no início dela).
 * Usada para os movimentos 'ra', 'rb' e 'rr'.
 */
void	ft_rotate(t_list *itemA)
{
	t_list	*itemZ;

	itemZ = itemA;
	while (itemZ->next)
		itemZ = itemZ->next;
	itemZ->prev->next = NULL;
	itemZ->prev = NULL;
	itemZ->next = itemA;
	itemA->prev = itemZ;
}

/* FUNÇÃO REVERSE ROTATE
 * Coloca o último elemento de uma pilha no início dela.
 * (primeiro elemento da lista no final dela).
 * Usada para os movimentos 'rra', 'rrb' e 'rrr'.
 */
void	ft_revrotate(t_list *itemA)
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
