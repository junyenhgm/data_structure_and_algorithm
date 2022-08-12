#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int idx;  // current index
    int max_size;
} min_heap_t;

#define SWAP(a, b) \
    do {           \
        a = a ^ b; \
        b = a ^ b; \
        a = a ^ b; \
    } while (0);

min_heap_t *heap_create(int size)
{
    min_heap_t *res = (min_heap_t *) malloc(sizeof(min_heap_t));
    res->idx = -1;
    res->max_size = size;
    res->arr = (int *) malloc(size * sizeof(int));

    return res;
}

int heap_left(int i)
{
    return 2 * i + 1;
}

int heap_right(int i)
{
    return 2 * i + 2;
}

int heap_parent(int i)
{
    return (i - 1) / 2;
}

int heap_peek_min(min_heap_t *obj)
{
    return obj->arr[0];
}

void heap_insert(min_heap_t *obj, int val)
{
    /* Check if full */
    if (obj->idx >= obj->max_size) {
        return;
    }

    obj->arr[++obj->idx] = val;
    int cur_idx = obj->idx;

    // Reconstruct binary heap after inserting new element
    // root node has no parent
    while (cur_idx != 0 && obj->arr[cur_idx] < obj->arr[heap_parent(cur_idx)]) {
        SWAP(obj->arr[cur_idx], obj->arr[heap_parent(cur_idx)]);
        cur_idx = heap_parent(cur_idx);
    }
}

void heap_min_heapify(min_heap_t *obj, int i)
{
    int l = heap_left(i);
    int r = heap_right(i);
    int min_idx = i;

    if (l <= obj->idx && obj->arr[l] < obj->arr[i]) {
        min_idx = l;
    }

    if (r <= obj->idx && obj->arr[r] < obj->arr[min_idx]) {
        min_idx = r;
    }

    if (min_idx != i) {
        SWAP(obj->arr[i], obj->arr[min_idx]);
        heap_min_heapify(obj, min_idx);
    }
}

int heap_pop_min(min_heap_t *obj)
{
    /* The first element is minimum num of the array */
    int res = obj->arr[0];
    /*
     * Swap the first with the last element and do heapify to reconstruct binary
     * heap.
     */
    SWAP(obj->arr[0], obj->arr[obj->idx]);
    obj->idx -= 1;
    heap_min_heapify(obj, 0);

    return res;
}

void heap_free(min_heap_t *obj)
{
    free(obj->arr);
    free(obj);
}

void show_array(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {3, 2, 1, 5, 6, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    min_heap_t *min_heap = heap_create(arr_size);
    int i = 0;

    /* build min binary heap */
    for (i = 0; i < arr_size; i++) {
        heap_insert(min_heap, arr[i]);
    }

    printf("Before sorting\n");
    show_array(arr, arr_size);

    printf("After sorting\n");
    int min_num = 0;
    for (i = 0; i < arr_size; i++) {
        min_num = heap_pop_min(min_heap);
        printf("%d ", min_num);
    }
    printf("\n");

    return 0;
}
