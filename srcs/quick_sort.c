/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:13:56 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/20 11:22:53 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partitionator(int *arr, int start, int end)
{
	int	pivot;
	int	i;

	pivot = arr[end];
	i = start;
	while (start < end)
	{
		if (arr[start] < pivot)
		{
			ft_swap(&arr[i], &arr[start]);
			i++;
		}
		start++;
	}
	ft_swap(&arr[i], &arr[end]);
	return (i);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partitionator(arr, start, end);
		quick_sort(arr, start, pivot - 1);
		quick_sort(arr, pivot + 1, end);
	}
}

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
