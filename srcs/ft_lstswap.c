/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:40:37 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/07 18:23:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstswap(t_list lstA, t_list lstB)
{
	t_list	*temp;
	
	if (lstA->prev)
		lstA->prev->next = lstB;
	if (lstB->next)
		lstB->next->prev = lstA;
	temp = lstB->next;
	lstB->next = lstA;
	lstA->next = temp;
	temp = lstA->prev;
	lstA->prev = lstB;
	lstB->prev = temp;
}

void	ft_lstpush(t_list lstA, t_list lstB)
{
	lstB->next->prev = NULL;
	lstB->next = lstA;
	lstA->prev = lstB;
}

