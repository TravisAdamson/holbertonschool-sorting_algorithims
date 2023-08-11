#include "sort.h"

/**
 * bubble_sort - Implements a bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: No return
 */

void bubble_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0, j = 0;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
