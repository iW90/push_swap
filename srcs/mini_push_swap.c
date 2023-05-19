/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:04:06 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/19 18:31:27 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* PUSH SWAP ESPECÍFICO PARA TRÊS NÚMEROS
 * Utiliza no máximo dois movimentos para ordenar:
 * Baseado na posição do maior índice, no caso o 2:
 *		 0 	 1 	|2|	sorted
 *		 1 	 0 	|2|	sa
 *		 0 	|2|	 1 	rra (requer mais um movimento, por isso o while)
 *		 1 	|2|	 0 	rra
 *		|2|	 1 	 0 	ra (requer mais um movimento, por isso o while)
 *		|2|	 0 	 1 	ra
 */
void	push_swap_for_three(t_stacks *stks)
{
	while (!is_sorted(stks->stack_a))
	{
		if (stks->stack_a->next->next->index == 2)
			sa(stks);
		else if (stks->stack_a->next->index == 2)
			rra(stks);
		else if (stks->stack_a->index == 2)
			ra(stks);
	}
}
