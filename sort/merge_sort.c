#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int *arr, int l, int m, int r)
{
    int len_l = m - l + 1;
    int len_r = r - m;

    int arr_l[len_l];
    int arr_r[len_r];

    memcpy(arr_l, arr + l, len_l * sizeof(int));
    memcpy(arr_r, arr + m + 1, len_r * sizeof(int));

    int i = 0, j = 0;
    int index = l;

    /* From 0 to len_l */
    /* From 0 to len_r */
    while (i < len_l && j < len_r) {
        if (arr_l[i] <= arr_r[j]) {
            arr[index] = arr_l[i];
            i++;
            index++;
        } else {
            arr[index] = arr_r[j];
            j++;
            index++;
        }
    }

    while (i < len_l) {
        arr[index] = arr_l[i];
        i++;
        index++;
    }

    while (j < len_r) {
        arr[index] = arr_r[j];
        j++;
        index++;
    }
}

void merg_sort(int *arr, int left, int right)
{
    if (left < right) {
        /* Same as (l+r)/2, but avoids overflow */
        int mid = left + (right - left) / 2;

        merg_sort(arr, left, mid);
        merg_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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
    int a[8] = {2, 5, 4, 1, 3, 8, 6, 7};
    int len = sizeof(a) / sizeof(a[0]);

    /* Before */
    show_arr(a, len);

    merg_sort(a, 0, len - 1);

    /* After */
    show_arr(a, len);

    return 0;
}
