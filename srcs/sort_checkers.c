/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:26:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 21:38:33 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* VERIFICAÇÃO DE LISTA EM ORDEM CRESCENTE
 * Se estiver ordenada do menor pro maior, retorna 'true'.
 * Os números devem ser sequenciais, sem pular número no meio.
 */
int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->index != lst->next->index - 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/* VERIFICAÇÃO DE LISTA EM ORDEM DECRESCENTE
 * Se estiver ordenada do maior pro menor, retorna 'true'.
 * Os números devem ser sequenciais, sem pular número no meio.
 */
int	is_sorted_reverse(t_list *lst)
{
	while (lst->next)
	{
		if (lst->index != lst->next->index + 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/* VERIFICAÇÃO DE LISTA EM ORDEM CRESCENTE
 * Se estiver ordenada do menor pro maior, retorna 'true'.
 * Os números devem ser sequenciais, mas podem faltar números no meios.
 */
int	is_ascending(t_list *lst)
{
	while (lst->next)
	{
		if (lst->index > lst->next->index)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/* VERIFICAÇÃO DE LISTA EM ORDEM DECRESCENTE
 * Se estiver ordenada do maior pro menor, retorna 'true'.
 * Os números devem ser sequenciais, mas podem faltar números no meios.
 */
int	is_descending(t_list *lst)
{
	while (lst->next)
	{
		if (lst->index < lst->next->index)
			return (0);
		lst = lst->next;
	}
	return (1);
}
