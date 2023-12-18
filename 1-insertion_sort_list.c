#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: Pointer to the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *back, *next_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        next_node = current->next;
        back = current->prev;

        while (back != NULL && back->n > current->n)
        {
            if (back->prev != NULL)
                back->prev->next = current;
            else
                *list = current;
            current->prev = back->prev;
            back->prev = current;
            back->next = next_node;
            if (next_node != NULL)
                next_node->prev = back;

            print_list(*list);
            back = current->prev;
        }

        current = next_node;
    }
}

/**
 * swap_node - Swaps a node with its previous node.
 * @node: The node to be swapped.
 * @list: Pointer to the doubly linked list.
 * Return: The node that was inserted.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
    listint_t *back = node->prev, *current = node;

    back->next = current->next;
    if (current->next)
        current->next->prev = back;
    current->next = back;
    current->prev = back->prev;
    back->prev = current;
    if (current->prev)
        current->prev->next = current;
    else
        *list = current;

    return (current);
}
