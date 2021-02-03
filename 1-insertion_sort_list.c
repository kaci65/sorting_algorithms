#include <stdio.h>
#include "sort.h"

/**
 * node_sorted_insert - insert a new node through sorting
 * @head: pointer to head of listint_t elements
 * @new_node: node to be inserted
 * Return: Nothing
 */
void node_sorted_insert(listint_t **head, listint_t *new_node)
{
	listint_t *curr;

	/* list is empty */
	if (*head == NULL)
	{
		*head = new_node;
	}
	/* if node to be added at beginning of list */
	else if ((*head)->n >= new_node->n)
	{
		new_node->next = *head;
		new_node->next->prev = new_node;
		*head = new_node;
	}
	else
	{
		curr = *head;
		/* find node after which new node will be inserted */
		while (curr->next != NULL && curr->next->n < new_node->n)
		{
			curr = curr->next;
		}
		/* link nodes */
		new_node->next = curr->next;

		/* if new node not inserted at the end of list */
		if (curr->next != NULL)
		{
			new_node->next->prev = new_node;
		}
		curr->next = new_node;
		new_node->prev = curr;
	}

}
/**
 * insertion_sort_list - sorts doubly linked list of ints in ascending order
 * @list: doubly linked list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sort_nodes, *current, *next;

	sort_nodes = NULL;
	current = *list;

	while (current != NULL)
	{
		/* store tmp node */
		next = current->next;

		/* current as new node for insertion */
		current->prev = current->next = NULL;

		/*insert current in sorted list */
		node_sorted_insert(&sort_nodes, current);

		/* print doubly linked list */
		print_list(*list);

		/* update current node */
                current = next;
	}
	/* head node(list) pointing to sorted list */
	*list = sort_nodes;
}
