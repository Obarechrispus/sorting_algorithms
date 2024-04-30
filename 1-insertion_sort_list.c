#include "sort.h"
#include "stdlib.h"
/*
 *insertion_sort_list - sorts a doubly linked of intergers in ascending order
 *
 *
 *
 *list: The list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *unsorted;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		 return;
    current = (*list)->next; /* Start with the second node */
    while (current != NULL)
    {
        sorted = current->prev; /* Start from the last sorted node */
        unsorted = current;     /* Node to be inserted into the sorted part */

        /* Move the unsorted node to its correct position in the sorted part */
        while (sorted != NULL && sorted->n > unsorted->n)
        {
            /* Swap unsorted and sorted nodes */
            if (unsorted->next != NULL)
                unsorted->next->prev = sorted;
            if (sorted->prev != NULL)
                sorted->prev->next = unsorted;
            else
                *list = unsorted;
            sorted->next = unsorted->next;
            unsorted->prev = sorted->prev;
            unsorted->next = sorted;
            sorted->prev = unsorted;

            print_list(*list); /* Print the list after each swap */
            sorted = unsorted->prev; /* Update sorted pointer */
        }

        current = current->next; /* Move to the next unsorted node */
    }
}
