#include "sort.h"

/**
 * selection_sort - Implements a selection sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: No return
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, index;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
				index = j;
		}
		temp = array[index];
		array[index] = array[i];
		array[i] = temp;
		if (index != i)
			print_array(array, size);
	}
}
