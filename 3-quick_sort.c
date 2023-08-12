#include "sort.h"

/**
 * quick_sort - Implements quick sort using lomunto partition
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: No return value
 */
void quick_sort(int *array, size_t size)
{
	int piv, high, low;

	if (size < 2)
		return;
	high = high_low(array, size, 1);
	low = high_low(array, size, 0);
	if (low < high)
	{
		piv = make_partition(array, low, high, size);
		quick_sort2(array, low, piv - 1, size);
		quick_sort2(array, piv + 1, high, size);
	}
}

/**
 * quick_sort2 - Sorts parts of array after partitioning
 * @array: The array to sort
 * @low: The location of low value
 * @high: The location of high value
 * @size: The overall size of array
 *
 * Return: No Return value
 */
void quick_sort2(int *array, int low, int high, size_t size)
{
	int piv;

	if (low < high)
	{
		piv = make_partition(array, low, high, size);
		quick_sort2(array, low, piv - 1, size);
		quick_sort2(array, piv + 1, high, size);
	}
}
/**
 * make_partition - Finds pivot and makes partition
 * @array: The array to be sorted
 * @low: The low value's location
 * @high: The high value's location
 * @size: The size of the array
 *
 * Return: No return
 */
int make_partition(int *array, int low, int high, size_t size)
{
	int index, pivot, index2;

	pivot = array[high];
	index = (low - 1);
	for (index2 = low; index2 <= high - 1; index2++)
	{
		if (array[index2] < pivot)
		{
			index++;
			swap_elem(&array[index], &array[index2]);
			print_array(array, size);
		}
	}
	swap_elem(&array[index + 1], &array[high]);
	print_array(array, size);
	return (index + 1);
}

/**
 * high_low - Gets the high or low value based on request
 * @array: The array to evaluate
 * @size: The size of the array
 * @h_l: The flag indicator of high or low
 *
 * Return: The high or low value
 */
int high_low(int *array, size_t size, int h_l)
{
	int value = array[0], index = 1, temp_size = 0;
	int array_index = 0;

	temp_size = (int)size;
	for (index = 1; index <= temp_size; index++)
	{
		if (h_l == 0)
		{
			if (array[index] < value)
			{
				value = array[index];
				array_index = index;
			}
		}
		else
		{
			if (array[index] > value)
			{
				value = array[index];
				array_index = index;
			}
		}
		index++;
	}
	return (array_index);
}

/**
 * swap_elem - Swaps given elements of the array
 * @arr_a: First element - to be made second
 * @arr_b: Second element - to be made first
 *
 * Return: No return value
 */
void swap_elem(int* arr_a, int* arr_b)
{
	int temp;

	temp = *arr_a;
	*arr_a = *arr_b;
	*arr_b = temp;
}
