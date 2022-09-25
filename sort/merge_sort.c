#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int *nums, int left, int mid, int right)
{
    int len_left = mid - left + 1;
    int len_right = right - mid;

    int arr_left[len_left];
    int arr_right[len_right];
    
    memcpy(arr_left, &nums[left], len_left * sizeof(int));
    memcpy(arr_right, &nums[mid + 1], len_right * sizeof(int));
    
    int l = 0, r = 0;
    int index = left;
    
    while (l < len_left && r < len_right) {
        if (arr_left[l] <= arr_right[r]) {
            nums[index++] = arr_left[l++];
        } else {
            nums[index++] = arr_right[r++];
        }
    }
    
    while (l < len_left) {
        nums[index++] = arr_left[l++];
    }
    
    while (r < len_right) {
        nums[index++] = arr_right[r++];
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
