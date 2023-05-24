/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:58:01 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/23 22:06:44 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/* NOVO NODE
 * Cria um novo item e adiciona à lista
 */
t_list	*ft_newnode(int num, t_list *previous)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		exit_program(1, "Error\n", previous, NULL);
	*newnode = (t_list){0};
	newnode->num = num;
	newnode->prev = previous;
	if (previous)
		previous->next = newnode;
	return (newnode);
}

/* ÚLTIMO ELEMENTO
 * Pega o último elemento da lista
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* DELETAR LISTA
 * Deleta toda a lista a partir do último elemento da lista.
 */
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

/* VERIFICAÇÃO DE LISTA EM ORDEM CRESCENTE
 * Se estiver ordenada do menor pro maior, retorna 'true'.
 * Os números devem ser sequenciais, sem pular número no meio.
 */
int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}
