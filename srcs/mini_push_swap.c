/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:04:06 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 21:41:49 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ORDENADOR PARA ENTRADA DE TRÊS NÚMEROS
 * Versão otimizada que utiliza no máximo dois movimentos para ordenar.
 * Baseado na posição do maior índice, no exemplo abaixo, o 2:
 *		 0 	 1 	|2|	sorted
 *		 1 	 0 	|2|	sa
 *		 0 	|2|	 1 	rra (requer mais um movimento 'sa', por isso o while)
 *		 1 	|2|	 0 	rra
 *		|2|	 1 	 0 	ra (requer mais um movimento 'sa', por isso o while)
 *		|2|	 0 	 1 	ra
 */
void	sort_three(t_stacks *stks)
{
	int	max;

	max = greater_index(stks->stack_a);
	while (!is_ascending(stks->stack_a))
	{
		if (stks->stack_a->next->next->index == max)
			sa(stks);
		else if (stks->stack_a->next->index == max)
			rra(stks);
		else if (stks->stack_a->index == max)
			ra(stks);
	}
}

/* ORDENADOR PARA ENTRADA DE QUATRO NÚMEROS
 * Versão preguiçosa similar ao sort five.
 *		Até 3 ra e 1 pb para enviar índice 0 para B;
 *		Até 2 moves chamando sort_three;
 *		1 pa para devolver B para A.
 */
void	sort_four(t_stacks *stks)
{
	if (!is_sorted(stks->stack_a))
	{
		while (stks->b_size != 1)
		{
			if (stks->stack_a->index == 0)
				pb(stks);
			else
				ra(stks);
		}
		sort_three(stks);
		pa(stks);
	}
}

/* ORDENADOR PARA ENTRADA DE CINCO NÚMEROS
 * Versão preguiçosa que utiliza no máximo onze movimentos,
 * mas também utiliza mais movimentos em casos que poderiam
 * ser resolvidos com apenas um.
 *		Até 4 ra e 2 pb para enviar índices 0 e 1 para B;
 *		1 sb se necessário;
 *		Até 2 moves chamando sort_three;
 *		2 pa para devolver B para A.
 */
void	sort_five(t_stacks *stks)
{
	if (!is_sorted(stks->stack_a))
	{
		while (stks->b_size != 2)
		{
			if (stks->stack_a->index == 0 || stks->stack_a->index == 1)
				pb(stks);
			else
				ra(stks);
		}
		if (stks->stack_b->index < stks->stack_b->next->index)
			sb(stks);
		sort_three(stks);
		pa(stks);
		pa(stks);
	}
}
