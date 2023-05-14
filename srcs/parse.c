/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:30:31 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 18:17:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* VERIFICAÇÃO DE CARACTERES NUMÉRICOS
 * Verifica se o valor recebido possui apenas caracteres
 * numéricos ou sinais (+ e -).
 */
static void	is_all_digits(int n, char **numbers)
{
	int	j;

	j = 0;
	while (--n)
	{
		if (numbers[n][j] == '+' || numbers[n][j] == '-')
			n++;
		while (numbers[n][j])
		{
			if (numbers[n][j] < '0' || numbers[n][j] > '9')
				exit_program(1, "Error\n", NULL);
			j++;
		}
		j = 0;
	}
}

/* VERIFICAÇÃO DE NÚMEROS REPETIDOS
 * Cada número será comparado aos números anteriores
 * já salvos na lista linkada para evitar repetição.
 */
static void	is_repeated_num(int n, t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		while (lst)
		{
			if (lst->num == n)
				exit_program(1, "Error\n", lst);
			lst = lst->prev;
		}
	}
}

/* DISTRIBUIÇÃO DE NÚMEROS
 * Insere os números recebidos pelo argv em nodos
 * de uma lista linkada.
 */
t_list	*parse_list(int total, char **num)
{
	t_list	*lst;
	int		i;
	long	n;

	lst = NULL;
	i = 1;
	is_all_digits(total, num);
	while (i < total)
	{
		n = ft_atol(num[i]);
		if (n <= I_MIN || n >= I_MAX)
			exit_program(1, "Error\n", lst);
		is_repeated_num(n, lst);
		lst = ft_newnode(n, lst, i);
		i++;
	}
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
	}
	return (lst);
}
