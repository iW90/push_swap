/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 13:57:09 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* TESTER: PRINT LIST
 * Imprime os números da lista linkada.
 */
static void print_list(t_list *lst)
{
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
		while (lst)
		{
			ft_printf("%i\t", lst->num);
			lst = lst->next;
		}
		ft_printf("\n");
	}
}

/* VERIFICAÇÃO DE CARACTERES NUMÉRICOS
 * Verifica se o valor recebido possui apenas caracteres
 * numéricos ou sinais (+ e -).
 */
static void	num_validator(int total, char **num)
{
	int	i;

	i = 1;
	while (i < total)
	{
		if (!ft_isnumber(num[i]))
			exit_program(1, "Error\n", NULL);
		i++;
	}
}

/* VERIFICAÇÃO DE NÚMEROS REPETIDOS
 * Cada número será comparado aos números anteriores
 * já salvos na lista linkada para evitar repetição.
 */
static void	repeat_num_validator(int n, t_list *lst)
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
static t_list *parse_list(int total, char **num)
{
	t_list	*lst;
	int		i;
	long	n;
	
	lst = NULL;
	i = 1;
	while (i < total)
	{
		n = ft_atol(num[i]);
		if (n <= I_MIN || n >= I_MAX)
			exit_program(1, "Error\n", lst);
		repeat_num_validator(n, lst);
		lst = ft_newnode(n, lst);
		i++;
	}
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	t_stacks stks;
	
	if (argc == 1)
		exit_program(1, "", NULL);
	num_validator(argc, argv);
	stks = (t_stacks){0};
	stks.stackA = parse_list(argc, argv);
	print_list(stks.stackA);
	exit_program(0, "", stks.stackA);
	return (0);
}
