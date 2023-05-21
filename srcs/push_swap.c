/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:46:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 20:37:27 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_reverse(t_stacks *stks)
{
	int	min;

	min = is_smaller_index(stks->stack_b);
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


/* PRIMEIROS PASSOS
 * Enviar 3 elementos para B e ordenar descendentemente.
		static int	best_way()
		{
			
		}
 */
void	push_swap(t_stacks *stks)
{
	pb(stks);
	pb(stks);
	pb(stks);
	sort_three_reverse(stks);
}
