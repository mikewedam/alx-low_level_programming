#include "lists.h"

/**
 * sum_listint - Calculates the sum of all data values in a listint_t linked list.
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The sum of all data values in the linked list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
