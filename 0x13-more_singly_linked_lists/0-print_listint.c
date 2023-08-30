#include "lists.h"

/**
 * print_listint - Prints the elements of a linked list and counts them.
 * @head: Pointer to the head of the linked list (of type listint_t).
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		printf("%d\n", head->n);
		count++;
		head = head->next;
	}

	return (count);
}
