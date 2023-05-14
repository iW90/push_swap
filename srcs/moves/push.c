/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:23 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 10:39:04 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* FUNÇÃO PUSH
 * Coloca o primeiro elemento de uma pilha no topo da outra pilha.
 * Lembrando que existe a possibilidade de ainda não existir lstB,
 * denotando que ela está vazia.
 * Usada para os movimentos 'pa' e 'pb'.
 */
static void	ft_push(t_list *src, t_list *dst)
{
	t_list	*temp;
	
	if (!src)
		return ;
	if (src->next)
		src->next->prev = NULL;
	if (dst)
		dst->prev = src;
	temp = src->next;
	src->next = dst;
	dst = src;
	src = temp;
}

//Pega o primeiro elemento do topo da pilha B e coloca no topo da pilha A.
void	pa(s_stacks *stacks)
{
	ft_push(stacks->stackA, stacks->stackB);
	ft_putstr_fd("pa\n", 1);
}

//Pega o primeiro elemento do topo da pilha A e coloca no topo da pilha B.
void	pb(s_stacks *stacks)
{
	ft_push(stacks->stackB, stacks->stackA);
	ft_putstr_fd("pb\n", 1);
}