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
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array to be sorted
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size == 0)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_elems(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
