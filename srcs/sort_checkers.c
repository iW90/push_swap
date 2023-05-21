/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:26:16 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 20:30:15 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
