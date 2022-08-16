/*

index i, j

i is from 1 to (len-1)

j is from (i - 1) to 0

compare j-th number with (j+1)-thnum

Ascending order
if arr[j] > arr[j+1], swap them,

Descending order
if arr[j] < arr[j+1], swap them,

Time: O(N^2)
Space: O(1)

*/

#include <stdio.h>

#define SWAP(a, b) \
    do {           \
        a = a ^ b; \
        b = a ^ b; \
        a = a ^ b; \
    } while (0)


void insertion_sort(int *arr, int size)
{
    int i, j;

    for (i = 1; i < size; i++) {
        for (j = i - 1; j >= 0; j--) {
            /* Ascending order */
            if (arr[j] < arr[j + 1]) {
                /*
                Since current arr[j] is the greatest number of the sorted
                sub-array, so if arr[j] is less than arr[j + 1], then we can say
                the sub-array from 0 to (j+1) is sorted. No need to swap.
                */
                break;
            }
            SWAP(arr[j], arr[j + 1]);
        }
    }
}

// A utility function to print an array of size n
void show_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main(void)
{
    // int arr[] = {12, 11, 13, 5, 6};
    int arr[] = {
        0xf6, 0x46, 0xa3, 0xd7, 0xa7, 0x4b, 0x9b, 0xc6, 0x21, 0x7b,
        0xe8, 0xab, 0xfa, 0x2f, 0x83, 0xd8, 0xda, 0x4b, 0x96, 0x53,
        0xb7, 0x07, 0x41, 0x19, 0xdf, 0xa2, 0xca, 0x34, 0x99, 0xb6,
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    show_array(arr, n);
    insertion_sort(arr, n);
    show_array(arr, n);

    return 0;
}