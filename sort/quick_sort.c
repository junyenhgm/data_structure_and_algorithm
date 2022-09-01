/*

There are many different versions of quickSort that pick pivot in different
ways.

Always pick the first element as a pivot.
Always pick the last element as a pivot.
Pick a random element as a pivot.
Pick median as the pivot.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a, b)   \
    do {             \
        int tmp = a; \
        a = b;       \
        b = tmp;     \
    } while (0)

int partition(int *arr, int left, int right, int pivot)
{
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }

        while (arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            SWAP(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(int *arr, int left, int right)
{
    if (left >= right) {
        return;
    }

    /* Pick median as the pivot. */
    int pivot = arr[left + ((right - left) >> 1)];
    /* divide index */
    int index = partition(arr, left, right, pivot);
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}


void show_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int a[] = {2, 5, 4, 1, 3, 8, 6, 7, 2, 3};

    int len = sizeof(a) / sizeof(a[0]);

    srand(time(NULL));

    /* Before */
    show_arr(a, len);

    quicksort(a, 0, len - 1);

    /* After */
    show_arr(a, len);

    return 0;
}