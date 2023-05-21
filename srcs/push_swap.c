/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:46:49 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/21 19:28:50 by inwagner         ###   ########.fr       */
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

/* CALCULADORA DE CUSTO
 * Calcula o menor custo.
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
		return (-(size - min_cost)); // Calcula de baixo para cima
	return (min_cost);
}

/* SOMA DE CUSTOS
 * Calcula o total de movimentos, levando em consideração
 * movimentos que podem ser executados dos dois lados ao
 * mesmo tempo (rrr, rr).
 */
int	sum_cost(int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
	{
		if (a_cost > b_cost)
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

/* PRIMEIROS PASSOS
 * Enviar 3 elementos para B
 * ordenar descendentemente
 * Buscar sempre pelo melhor número a ser transferido para B
 */
void	push_swap(t_stacks *stks)
{
	t_list	*lst_a;
	int		target;
	int		a_cost;
	int		b_cost;
	int		t_cost;

	pb(stks);
	pb(stks);
	pb(stks);
	sort_three_reverse(stks);
	pb(stks);
	pb(stks);
	pb(stks);
	print_full_stacks(stks);
	lst_a = stks->stack_a;
	while (lst_a)
	{
		target = find_closest_number(lst_a->index, stks->stack_b);
		ft_printf("\nCostA:\nIndex: %i ", lst_a->index);
		a_cost = calculate_cost(lst_a->index, stks->stack_a, stks->a_size);
		ft_printf("MinCost: %i\n", a_cost);
		ft_printf("CostB:\nIndex: %i ", target);
		b_cost = calculate_cost(target, stks->stack_b, stks->b_size);
		ft_printf("MinCost: %i\n", b_cost);
		t_cost = sum_cost(a_cost, b_cost);
		ft_printf("TotalCost: %i\n\n", t_cost);
		lst_a = lst_a->next;
	}
}
