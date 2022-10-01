
There are many different versions of quickSort that pick pivot in different

ways.

Always pick the first element as a pivot.

Always pick the last element as a pivot.

Pick a random element as a pivot.

Pick median as the pivot.


![](image/quick_sort/quick_sort_partition_animation.gif)


Always pick the first element as a pivot.

Always pick the last element as a pivot.

```

```



### Pick median as the pivot.

```c
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
```





### Pick a random element as a pivot.

```c
int partition(int *arr, int left, int right, int pivot)
{
    int last = right;
    while (left < right) {
        while (arr[left] <= arr[pivot] && left < last) {
            left++;
        }

        while (arr[right] > arr[pivot]) {
            right--;
        }

        if (left < right) {
            SWAP(arr[left], arr[right]);
        }
    }

    SWAP(arr[pivot], arr[right]);

    return right;
}

void quicksort(int *arr, int left, int right)
{
    if (left >= right) {
        return;
    }

    int pivot = rand() % (right - left + 1) + left;

    /* divide index */
    int index = partition(arr, left, right, pivot);

    quicksort(arr, left, index - 1);
    quicksort(arr, index + 1, right);
}
```
