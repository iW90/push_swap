/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:58:01 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 20:33:04 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Cria um novo item e adiciona à lista
t_list	*ft_newnode(int num, t_list *previous)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		exit_program(1, "Error\n", previous);
	*newnode = (t_list){0};
	newnode->num = num;
	newnode->prev = previous;
	if (previous)
		previous->next = newnode;
	return (newnode);
}

// Pega o último elemento da lista
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Deleta toda a lista a partir do último elemento da lista
void	ft_lstclear(t_list *lst)
{
	t_list	*aux;

	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		while (lst)
		{
			aux = lst->prev;
			free(lst);
			lst = aux;
		}
	}
}

// Pega o maior índice da lista
int	is_greater_index(t_list *lst)
{
	int	greater;

	greater = 0;
	while (lst)
	{
		if (lst->index > greater)
			greater = lst->index;
		lst = lst->next;
	}
	return (greater);
}

// Pega o menor índice da lista
int	is_smaller_index(t_list *lst)
{
	int	smaller;

	smaller = lst->index;
	while (lst)
	{
		if (lst->index < smaller)
			smaller = lst->index;
		lst = lst->next;
	}
	return (smaller);
}
