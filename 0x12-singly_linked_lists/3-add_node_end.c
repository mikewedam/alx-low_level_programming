#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newElement;
	unsigned int len = 0;

	while (str[len])
		len++;

	newElement = malloc(sizeof(list_t));
	if (!newElement)
		return (NULL);

	newElement->str = strdup(str);
	if (!newElement->str)
	{
		free(newElement);
		return (NULL);
	}

	newElement->len = len;
	newElement->next = *head;
	*head = newElement;

	return (newElement);
}

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newElement;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	newElement = malloc(sizeof(list_t));
	if (!newElement)
		return (NULL);

	newElement->str = strdup(str);
	if (!newElement->str)
	{
		free(newElement);
		return (NULL);
	}

	newElement->len = len;
	newElement->next = NULL;

	if (*head == NULL)
	{
		*head = newElement;
		return (newElement);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = newElement;

	return (newElement);
}
