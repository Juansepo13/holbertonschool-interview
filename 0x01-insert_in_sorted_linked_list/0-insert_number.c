#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a number into a sorted singly linked list
 * @head: pointer to the linked list
 * @number: the number that will be inserted
 *
 * Return: a pointer.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux;
	listint_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	aux = *head;
	if (aux->n > new->n)
	{
		new->next = aux;
		*head = new;
		return (*head);
	}
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			new->next = NULL;
			aux->next = new;
			break;
		}
		if (aux->next->n > number)
		{
			new->next = aux->next;
			aux->next = new;
			break;
		}
		aux = aux->next;
	}
	return (aux);
}