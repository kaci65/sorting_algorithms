#include <stdio.h>
#include "sort.h"

/**
 * swap_elems - swaps the elements of the array
 * @m: element to be swapped
 * @n: element to be swapped
 * Return: Nothing
 */
void swap_elems(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * lomuto_partition - chooses last element as 'pivot' from array and
 * partitions other elements into two sub-arrays according to whether
 * they are less than or greater than the pivot
 * smaller than elements placed to left of pivot
 * greater than elements placed to right of pivot
 * @array: array of integers
 * @low: elements lower than pivot
 * @high: elements higher than pivot
 * @size: size of the array
 * Return: position of pivot in the array
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_elems(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * sort_elems - sort integers using low/high
 * @array: array of integers to be sorted
 * @low: element to the left of the pivot
 * @high: element to the right of the pivot
 * @size: size of array
 * Return: Nothing
 */
void sort_elems(int *array, int low, int high, size_t size)
{
	int aux;

	if (low < high)
	{
		aux = lomuto_partition(array, low, high, size);
		sort_elems(array, low, aux - 1, size);
		sort_elems(array, aux + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int lo = 0;
	int hi = size - 1;

	if (array == NULL || size == 0)
	{
		return;
	}
	sort_elems(array, lo, hi, size);
}
