/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:58:01 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/08 09:57:40 by inwagner         ###   ########.fr       */
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