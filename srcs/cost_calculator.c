/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:30:12 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/22 20:58:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ENCONTRA O NÚMERO MAIS PRÓXIMO
 * Encontra o número mais próximo da pilha para colocar
 * no topo da pilha oposta mantendo a ordem da pilha oposta.
 * Fora desta função haverá outro while que passa item por item
 * de uma pilha, passando o índice (index) de cada um desses itens
 * para comparar com todos os itens da pilha oposta (lst).
 * index é de uma pilha e lst é da pilha oposta à do index.
 */
static int	find_closest_number(int index, t_list *lst)
{
	int		closest;
	t_list	*head;

	head = lst;
	closest = -1;
	while (lst)
	{
		if (lst->index < index && \
		(closest == -1 || index - lst->index < index - closest))
			closest = lst->index;
		lst = lst->next;
	}
	if (closest == -1)
		return (greater_index(head));
	return (closest);
}

/* CALCULADORA DE CUSTO INDIVIDUAL
 * Calcula o menor custo de cada item de uma lista.
 * index, lst e size são da mesma lista.
 * Quando o item da lista encontrar ele mesmo, o looping é interrompido
 * com o valor de menor custo. Calculo a distância do index até o topo.
 */
int	calculate_cost(int index, t_list *lst, int size)
{
	int	min_cost;

	min_cost = 0;
	while (lst)
	{
		if (lst->index == index)
			break ;
		min_cost++;
		lst = lst->next;
	}
	if (min_cost > size / 2)
		return (-(size - min_cost));
	return (min_cost);
}

/* SOMA DE CUSTOS
 * Calcula o total de movimentos, levando em consideração
 * movimentos que podem ser executados dos dois lados ao
 * mesmo tempo (rrr, rr).
 */
static int	sum_cost(int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
	{
		if (a_cost < b_cost)
			return (abs(a_cost));
		return (abs(b_cost));
	}
	else if (a_cost > 0 && b_cost > 0)
	{
		if (a_cost > b_cost)
			return (a_cost);
		return (b_cost);
	}
	else
		return (abs(a_cost) + abs(b_cost));
}

/* CALCULA A MELHOR ROTA
 * Soma os custos de A e B e 'salva' o primeiro que tiver
 * o menor custo para que este seja executado.
 */
void	get_cost(t_cost *cost, t_stacks *stks)
{
	t_list	*lst_a;
	int		target;
	int		cost_a;
	int		cost_b;
	int		total;

	lst_a = stks->stack_a;
	while (lst_a)
	{
		target = find_closest_number(lst_a->index, stks->stack_b);
		cost_a = calculate_cost(lst_a->index, stks->stack_a, stks->a_size);
		cost_b = calculate_cost(target, stks->stack_b, stks->b_size);
		total = sum_cost(cost_a, cost_b);
		if (total < cost->total)
		{
			cost->a = cost_a;
			cost->b = cost_b;
			cost->total = total;
		}
		lst_a = lst_a->next;
	}
}
