/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:23 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 21:50:30 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* FUNÇÃO PUSH
 * Coloca o primeiro elemento de uma pilha no topo da outra pilha.
 * Usada para os movimentos 'pa' e 'pb'.
 */
static t_list	*ft_push(t_list *src, t_list *dst, t_list *temp)
{
	if (src->next)
		src->next->prev = NULL;
	if (dst)
		dst->prev = src;
	src->next = dst;
	dst = src;
	src = temp;
	return (dst);
}

/* PARA A: 
 * Pega o primeiro elemento do topo da pilha B
 * e coloca no topo da pilha A.
 */
void	pa(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->stack_b)
	{
		temp = stacks->stack_b->next;
		stacks->stack_a = ft_push(stacks->stack_b, stacks->stack_a, temp);
		stacks->stack_b = temp;
		stacks->a_size++;
		stacks->b_size--;
		ft_putstr_fd("pa\n", 1);
	}
}

/* PARA B: 
 * Pega o primeiro elemento do topo da pilha A
 * e coloca no topo da pilha B.
 */
void	pb(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->stack_a)
	{
		temp = stacks->stack_a->next;
		stacks->stack_b = ft_push(stacks->stack_a, stacks->stack_b, temp);
		stacks->stack_a = temp;
		stacks->a_size--;
		stacks->b_size++;
		ft_putstr_fd("pb\n", 1);
	}
}
