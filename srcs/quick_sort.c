#include <stdio.h>

static void	swap(int *a, int *b)
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
			swap(&arr[i], &arr[start]);
		}
		start++;
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
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


int main(void)
{
	int arr[] = {10, 0, 7, 6, 1, 8, 4, 5, 2, 3, 9};
	int n = 11;

	for (int i = 0; i < n; i++)
		printf("%i ", arr[i]);
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%i ", arr[i]);
	printf("\n");
}

