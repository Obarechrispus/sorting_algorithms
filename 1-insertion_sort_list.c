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

	listint_t *current = (*list)->next;
	listint_t *temp = current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		
		while (temp->prev != NULL && temp ->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}
		current = current->next;
	}
}	
