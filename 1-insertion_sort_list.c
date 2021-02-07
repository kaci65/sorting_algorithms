#include <stdio.h>
#include "sort.h"

/**
 * swap_dnodes - insert a new node through sorting
 * @head: pointer to head of listint_t elements
 * @new_node: node to be inserted
 * @curr: current node
 * Return: Nothing
 */
void swap_dnodes(listint_t **head, listint_t *curr, listint_t *new_node)
{

	/* swap head node */
	if (curr->prev == NULL)
	{
		*head = curr->next;
	}
	else
	{
		curr->prev->next = new_node;
	}

	if (new_node->next)
	{
		new_node->next->prev = curr;
	}
	new_node->prev = curr->prev;
	curr->next = new_node->next;
	curr->prev = new_node;
	new_node->next = curr;
}
/**
 * insertion_sort_list - sorts doubly linked list of ints in ascending order
 * @list: doubly linked list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (*list == NULL || list == NULL)
	{
		return;
	}
	curr = *list;

	while (curr->next)
	{
		if (curr->n > curr->next->n)
		{
			swap_dnodes(list, curr, curr->next);
			print_list(*list);
			tmp = curr->prev;

			while (tmp->prev && tmp->n < tmp->prev->n)
			{
				swap_dnodes(list, tmp->prev, tmp);
				print_list(*list);
			}
		}
		else
		{
			/* update current node */
                	curr = curr->next;
		}
	}
}
