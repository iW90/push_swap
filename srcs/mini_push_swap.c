/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:04:06 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 12:20:18 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ORDENADOR PARA ENTRADA DE TRÊS NÚMEROS
 * Versão otimizada que utiliza no máximo dois movimentos para ordenar:
 * Baseado na posição do maior índice, no caso o 2:
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

	max = is_greater_index(stks->stack_a);
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

/* ORDENADOR PARA ENTRADA DE CINCO NÚMEROS
 * Versão preguiçosa que utiliza no máximo onze movimentos,
 * mas também utiliza mais movimentos em casos que poderiam
 * ser resolvidos com apenas um.
 *		Até 4 ra e 2 pb para enviar índices 0 e 1 para B;
 *		1 sb se necessário;
 *		Até 2 moves chamando sort_three;
 *		2 pa para devolver B para A.
 */
/*
void	sort_five(t_stacks *stks)
{
	if (!is_sorted(stks->stack_a))
	{
		while (stks->b_size != 2)
		{
			if (stks->stack_a->index == 0 || stks->stack_a->index == 1)
				pb(stks);
			if (stks->stack_a->index != 0 || stks->stack_a->index != 1)
				ra(stks);
		}
		if (stks->stack_b->index < stks->stack_b->next->index)
			sb(stks);
		sort_three(stks);
		pa(stks);
		pa(stks);
	}
}
*/
/* TENTATIVA 1 DE OTIMIZAÇÃO DO SORT 5 - FAILED
*/
void	sort_five(t_stacks *stks)
{
	pb(stks);
	pb(stks);
	sort_three(stks);
	if (stks->stack_b->index < stks->stack_b->next->index)
		sb(stks);
	if (stks->stack_b->index == stks->i_max && \
		(stks->stack_a->index == 0 || stks->stack_a->index == 1))
		pa(stks);
	while (stks->b_size && !is_sorted(stks->stack_a))
	{
		if (stks->stack_b->index == stks->stack_a->index - 1)
			pa(stks);
		if (stks->stack_b->index == stks->stack_a->index - 1)
			pa(stks);
		if (is_sorted(stks->stack_a))
			break ;
		
		/* PROBLEMA A SER RESOLVIDO: Looping infinito
			A	B
			3	0
			4
			1
			2			
				O if abaixo serve para gastar menos movimentos
				rotacionando para cima ou para baixo. No caso
				específico acima, ele entraria em um looping
				infinito. O que eu posso colocar no if para
				impedir sem que eu perca a funcionalidade?
				
			index: 3 > 2, logo 'rra'
				2 3 4 1
			index: 2 >= 2, logo 'ra'
				3 4 1 2
		*/ 
		
		if (stks->stack_a->index > 2)
			rra(stks);
		else
			ra(stks);
	}
}
