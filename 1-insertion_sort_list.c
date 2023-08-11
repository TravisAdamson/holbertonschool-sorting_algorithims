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
	listint_t *now;
	listint_t *before;

	if ((!list) || (!*list))
		return;
	now = *list;
	while ((now = now->next))
	{
		after = now;
		while (after->prev && after->n < after->prev->n)
		{
			before = now->prev;
			if (now->next)
				after->next->prev = before;
			if (before->prev)
				before->prev->next = after;
			else
				*list = after;
			before->next = after->next;
			after->prev = before->prev;
			after->next = before;
			before->prev = after;
			print_list(*list);
		}
	}
}
