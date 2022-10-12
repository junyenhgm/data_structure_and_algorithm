#include <limits.h>
#include <stdio.h>

int find_min(int *arr, size_t size, int k)
{
    if (k > size) {
        return k;
    }

    int min_val = INT_MAX;
    int min_idx = -1;

    for (int i = 0; i < k; i++) {
        if (min_val > arr[i]) {
            min_val = arr[i];
            min_idx = i;
        }
    }

    return min_idx;
}

int main(void)
{
    int arr[] = {81, 27, 34, 71, 98, 11, 42, 16, 69, 70, 90, 80, 62, 57,
                 12, 51, 83, 30, 33, 10, 77, 64, 19, 35, 39, 38, 23, 59};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int k = 1; k < size; k++) {
        printf("%d\n", find_min(arr, size, k));
    }

    return 0;
}
