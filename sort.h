#ifndef SORT_H
#define SORT_H

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* compiling functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* sorting algorithms functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* helper functions */
void swap_elems(int *m, int *n);
int lomuto_partition(int *array, int low, int high, size_t size);
void sort_elems(int *array, int low, int high, size_t size);

#endif /* #ifndef SORT_H */
