
#include <stdio.h>

int binary_search(int *nums, int size, int target)
{
    int left_index = 0;
    int right_index = size - 1;

    int middle_index;
    int middle_num;

    while (left_index <= right_index) {
        middle_index = left_index + ((right_index - left_index) >> 1);
        middle_num = nums[middle_index];

        if (target == middle_num) {
            return middle_index;
        } else if (target > middle_num) {
            /* target lands on the right side */
            left_index = middle_index + 1;
        } else { /* target < middle_num */
            /* target lands on the left side */
            right_index = middle_index - 1;
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int len = sizeof(arr) / sizeof(arr[0]);

    int index = 0;
    index = binary_search(arr, len, 5);

    printf("index %d\n", index);

    return 0;
}
