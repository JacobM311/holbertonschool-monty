#include "monty.h"
/**
 * freeList - free a certain list
 *
 * @head: start of list
 */
void freeList(stack_t **head)
{
	stack_t *temp;

	if (!head)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}