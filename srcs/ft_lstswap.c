/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:40:37 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/07 18:41:44 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list itemA, t_list itemB)
{
	t_list	*temp;

	if (itemA->prev)
		itemA->prev->next = itemB;
	if (itemB->next)
		itemB->next->prev = itemA;
	temp = itemB->next;
	itemB->next = itemA;
	itemA->next = temp;
	temp = itemA->prev;
	itemA->prev = itemB;
	itemB->prev = temp;
}

void	ft_push(t_list lstA, t_list lstB)
{
	lstB->next->prev = NULL;
	lstB->next = lstA;
	lstA->prev = lstB;
}

void	ft_rotate(t_list itemZ)
{
	t_list	*itemA;

	itemA = &itemZ;
	while (itemZ->next)
		itemZ = itemZ->next;
	itemA->next->prev = NULL;
	itemA->next = NULL;
	itemA->prev = itemZ;
	itemZ->next = itemA;
}

void	ft_revrotate(t_list itemZ)
{
	t_list	*itemA;

	itemA = &itemZ;
	while (itemZ->next)
		itemZ = itemZ->next;
	itemZ->prev->next = NULL;
	itemZ->prev = NULL;
	itemZ->next = itemA;
	itemA->prev = itemZ;
}
