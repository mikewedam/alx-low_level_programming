#include "lists.h"

/**
 * find_listint_loop - Detects a loop in a linked list and returns the node where the loop starts.
 * @head: Pointer to the linked list to search for a loop.
 *
 * Return: Address of the node where the loop starts, or NULL if no loop is detected.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (!head)
		return (NULL);

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}

	return (NULL);
}
