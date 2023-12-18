#include "sort.h"

/**
 * swap_node - Swaps a node with its previous one.
 * @node: The node to be swapped.
 * @list: Pointer to the doubly linked list.
 * Return: The node that was inserted.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
    listint_t *back = node->prev, *current = node;

    back->next = current->next;
    if (current->next != NULL)
        current->next->prev = back;
    current->next = back;
    current->prev = back->prev;
    back->prev = current;
    if (current->prev != NULL)
        current->prev->next = current;
    else
        *list = current;

    return (current);
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: Pointer to the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        while (current->prev != NULL && current->prev->n > current->n)
        {
            current = swap_node(current, list);
            print_list(*list);
        }
        current = current->next;
    }
}
