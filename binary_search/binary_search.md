# Iteration

```c
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


```



# Recursion

```c
int binary_search(int* nums, int target, int left, int right)
{
    if (left > right) {
        return -1;
    }
    
    int mid = left + ((right - left) >> 1);
    
    if (nums[mid] == target) {
        return mid;
    }
    
    if (target > nums[mid]) {
        return binary_search(nums, target, mid + 1, right);
    } else {
        return binary_search(nums, target, left, mid - 1);
    }

}

```
