/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:20 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/07 22:15:52 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void print_list(t_list *lst)
{
	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		ft_printf("%i\n", lst->num);
		lst = lst->next;
	}
}
/* TESTER: PRINT LIST
 */
 
static void	num_validator(int total, char **num)
{
	int	i;

	i = 1;
	while (i < total)
	{
		if (!ft_isalldigit(num[i]))
			exit_program(1, "Error\n", NULL);
		i++;
	}
}

static void	repeat_num_validator(int n, t_list *lst)
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
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

int	main(int argc, char **argv)
{
	t_list *lst;
	
	if (argc == 1)
		exit_program(1, "", NULL);
	num_validator(argc, argv);
	lst = parse_list(argc, argv);
	print_list(lst);
	return (0);
}
