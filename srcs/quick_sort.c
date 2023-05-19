#include <stdio.h>

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
	i = start - 1;
	while (start < end)
	{
		if (arr[start] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[start]);
		}
		start++;
	}
	ft_swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

/*
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
*/

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
