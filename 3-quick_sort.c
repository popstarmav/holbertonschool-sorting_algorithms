#include <stdio.h>

void print_array(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return;

    for (size_t i = 0; i < size; ++i)
    {
        printf("%d", array[i]);

        if (i < size - 1)
            printf(", ");
    }

    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low - 1;

    for (size_t j = low; j <= high - 1; ++j)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, size);

    return i + 1;
}

void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t partition_index = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, partition_index - 1, size);
        quick_sort_recursive(array, partition_index + 1, high, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
