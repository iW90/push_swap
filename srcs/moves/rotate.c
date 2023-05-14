/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:12 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 10:43:04 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* FUNÇÃO ROTATE
 * Coloca o primeiro elemento de uma pilha no final dela
 * (último elemento da lista no início dela).
 * Usada para os movimentos 'ra', 'rb' e 'rr'.
 */
static void	ft_rotate(t_list *itemA)
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

void	ra(t_stacks stack)
{
	ft_rotate(stack->stackA);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks stack)
{
	ft_rotate(stack->stackB);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stacks stack)
{
	ft_rotate(stack->stackA);
	ft_rotate(stack->stackB);
	ft_putstr_fd("rr\n", 1);
}
