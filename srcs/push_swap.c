/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:46:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 21:43:00 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ORDENADOR DESCENDENTE PARA ENTRADA DE TRÊS NÚMEROS
 * Versão reversa do sort de três números
 */
static void	sort_three_reverse(t_stacks *stks)
{
	int	min;

	min = smaller_index(stks->stack_b);
	while (!is_descending(stks->stack_b))
	{
		if (stks->stack_b->next->next->index == min)
			sb(stks);
		else if (stks->stack_b->next->index == min)
			rrb(stks);
		else if (stks->stack_b->index == min)
			rb(stks);
	}
}

/* ENCONTRA O NÚMERO MAIS PRÓXIMO
 * Encontra o número mais próximo da pilha para colocar
 * no topo da pilha oposta mantendo a ordem da pilha oposta.
 * Fora desta função haverá outro while que passa item por item
 * de uma pilha, passando o índice (index) de cada um desses itens
 * para comparar com todos os itens da pilha oposta (lst).
 * index é de uma pilha e lst é da pilha oposta à do index.
 */
int	find_closest_number(int index, t_list *lst)
{
	int	closest;

	closest = -1;
	while (lst)
	{
		if (lst->index < index && \
		(closest == -1 || index - lst->index < index - closest))
			closest = lst->index;
		lst = lst->next;
	}
	if (closest == -1)
		return (greater_index(lst));
	return (closest);
}

/* PRIMEIROS PASSOS
 * Enviar 3 elementos para B
 * ordenar descendentemente
 * Buscar sempre pelo melhor número a ser transferido para B
 */
void	push_swap(t_stacks *stks)
{
	pb(stks);
	pb(stks);
	pb(stks);
	sort_three_reverse(stks);
	while (stks->stack_a)
	{
		find_closest_number(stks->stack_a->index, stks->stack_a);
		stks->stack_a = stks->stack_a->next;
	}
}
