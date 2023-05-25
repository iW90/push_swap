/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:46:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/25 13:42:44 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* EXECUTA OS MOVIMENTOS CONCOMITANTEMENTE
 * Executa rr se os custos necessários para A e B forem positivos,
 * e executa rrr se os custos de ambos forem negativos.
 */
static void	do_moves_a_and_b(t_cost *cost, t_stacks *stks)
{
	if ((cost->a > 0 && cost->b < 0) || (cost->a < 0 && cost->b > 0))
		return ;
	while (cost->a && cost->b)
	{
		if (cost->a > 0 && cost->b > 0)
		{
			rr(stks);
			cost->a--;
			cost->b--;
		}
		if (cost->a < 0 && cost->b < 0)
		{
			rrr(stks);
			cost->a++;
			cost->b++;
		}
	}
}

/* EXECUTA OS MOVIMENTOS INDIVIDUALMENTE
 * Executa ra ou rb se o custo necessário for positivo,
 * e executa rra ou rrb se o custo for negativo.
 */
static void	do_moves_a_or_b(t_cost *cost, t_stacks *stks)
{
	while (cost->a || cost->b)
	{
		if (cost->a > 0)
		{
			ra(stks);
			cost->a--;
		}
		if (cost->a < 0)
		{
			rra(stks);
			cost->a++;
		}
		if (cost->b > 0)
		{
			rb(stks);
			cost->b--;
		}
		if (cost->b < 0)
		{
			rrb(stks);
			cost->b++;
		}
	}
}

/* EXECUTA OS MOVIMENTOS
 */
static void	do_moves(t_cost *cost, t_stacks *stks)
{
	do_moves_a_and_b(cost, stks);
	do_moves_a_or_b(cost, stks);
	pb(stks);
}

/* PRIMEIROS PASSOS
 * Enviar 3 elementos para B e ordenar B ao contrário.
 * Buscar sempre pelo melhor número a ser transferido para B
 * de acordo com o custo calculado.
 */
void	push_swap(t_stacks *stks)
{
	t_cost	cost;

	cost = (t_cost){0};
	pb(stks);
	pb(stks);
	pb(stks);
	sort_three_reverse(stks);
	while (stks->a_size)
	{
		cost.total = I_MAX;
		get_cost(&cost, stks);
		do_moves(&cost, stks);
	}
	while (stks->b_size)
		pa(stks);
	cost.a = calculate_cost(0, stks->stack_a, stks->a_size);
	if (cost.a > 0)
		while (cost.a--)
			ra(stks);
	else if (cost.a < 0)
		while (cost.a++)
			rra(stks);
}
