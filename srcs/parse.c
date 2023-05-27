/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:30:31 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/26 21:04:21 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* VERIFICAÇÃO DE CARACTERES NUMÉRICOS
 * Verifica se o valor recebido possui apenas caracteres
 * numéricos ou sinais (+ e -).
 */
static void	is_all_digits(int n, char **numbers, int *index)
{
	int	j;

	j = 0;
	while (--n)
	{
		if (numbers[n][j] == '+' || numbers[n][j] == '-')
			j++;
		if (!numbers[n][j])
			exit_program(1, "Error\n", NULL, index);
		while (numbers[n][j])
		{
			if (numbers[n][j] < '0' || numbers[n][j] > '9')
				exit_program(1, "Error\n", NULL, index);
			j++;
		}
		j = 0;
	}
}

/* VERIFICAÇÃO DE NÚMEROS REPETIDOS
 * Cada número será comparado aos números anteriores
 * já salvos na lista linkada para evitar repetição.
 */
static void	is_repeated_num(int n, t_list *lst, int *index)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		while (lst)
		{
			if (lst->num == n)
				exit_program(1, "Error\n", lst, index);
			lst = lst->prev;
		}
	}
}

/* DISTRIBUIÇÃO DE NÚMEROS NA LISTA E NO ARRAY
 * Insere os números recebidos pelo argv em nodos
 * de uma lista linkada.
 */
t_list	*parse_list(int total, char **num, int *index)
{
	t_list	*lst;
	int		i;
	long	n;

	lst = NULL;
	i = 1;
	is_all_digits(total, num, index);
	while (i < total)
	{
		n = ft_atol(num[i]);
		if (n <= I_MIN || n >= I_MAX)
			exit_program(1, "Error\n", lst, index);
		is_repeated_num(n, lst, index);
		lst = ft_newnode(n, lst, index);
		index[i - 1] = n;
		i++;
	}
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
	}
	return (lst);
}

/* DISTRIBUIÇÃO DE ÍNDICES NA LISTA
 * Coloca o índice dos números ordenados na variável
 * index da lista.
 */
void	parse_index(int *index, t_list *lst, int sz)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < sz)
		{
			if (lst->num == index[i])
				lst->index = i;
			i++;
		}
		lst = lst->next;
	}
}
