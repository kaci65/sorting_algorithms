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
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_int;

	for (i = 0; i < size - 1; i++)
	{
		/* find minimum integer */
		min_int = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_int])
			{
				min_int = j;
			}
		}
		if (i != min_int)
		{
			swap_elems(&array[min_int], &array[i]);
			print_array(array, size);
		}
	}
}
