#include "sort.h"

/**
 * insertion_sort_list - Implements a insertion sort on the list
 * @list: The list to sort
 *
 * Return: No return
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *after = NULL;
	listint_t *now = *list;
	listint_t *before;
	listint_t *earlier = NULL;
	listint_t *printer = NULL;

	while (now != NULL)
	{
		before = now->next;

		if (after == NULL || after->n > now->n)
		{
			now->next = after;
			if (after != NULL)
				after->prev = now;
			after = now;
			if (after->prev != NULL)
				printer = after->prev;
			else
				printer = after;
			print_list(printer);
		}
		else
		{
			earlier = after;
			while (earlier->next != NULL && earlier->next->n <= now->n)
			{
				earlier = earlier->next;
			}
			now->next = earlier->next;
			if (earlier->next != NULL)
					earlier->next->prev = now;
			earlier->next = now;
			now->prev = earlier;
			if (earlier->prev != NULL)
                                printer = earlier->prev;
                        else
                                printer = earlier;
                        print_list(printer);
		}
		now = before;
	}
	*list = after;
}
