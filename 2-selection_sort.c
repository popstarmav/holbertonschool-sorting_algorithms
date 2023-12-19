#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                   using the Selection sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i, j, min_index;
    int temp;

    i = 0;
    while (i < size)
    {
        min_index = i;
        j = i + 1;

        while (j < size)
        {
            if (array[j] < array[min_index])
                min_index = j;
            j++;
        }

        if (min_index != i)
        {
            /* Swap elements */
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;

            /* Print the array after each swap */
            print_array(array, size);
        }

        i++;
    }
}
