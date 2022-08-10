#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int idx;  // current index
    int max_size;
} max_heap_t;

#define SWAP(a, b) \
    do {           \
        a = a ^ b; \
        b = a ^ b; \
        a = a ^ b; \
    } while (0);

max_heap_t *heap_create(int size)
{
    max_heap_t *res = (max_heap_t *) malloc(sizeof(max_heap_t));
    res->idx = -1;
    res->max_size = size;
    res->arr = (int *) malloc(size * sizeof(int));

    return res;
}

int heap_left_child(int i)
{
    return 2 * i + 1;
}

int heap_right_child(int i)
{
    return 2 * i + 2;
}

int heap_parent(int i)
{
    return (i - 1) / 2;
}

int heap_peek_max(max_heap_t *obj)
{
    return obj->arr[0];
}

/**
 * time: O(logN)
 * which N is the counts of the heap
 */
void heap_insert(max_heap_t *obj, int val)
{
    /* Check if full */
    if (obj->idx >= obj->max_size) {
        return;
    }

    obj->arr[++obj->idx] = val;
    int cur_idx = obj->idx;

    // Reconstruct binary heap after inserting new element
    // root node has no parent
    // if child is greater than parent, then swap them
    while (cur_idx != 0 && obj->arr[cur_idx] > obj->arr[heap_parent(cur_idx)]) {
        SWAP(obj->arr[cur_idx], obj->arr[heap_parent(cur_idx)]);
        cur_idx = heap_parent(cur_idx);
    }
}

void heap_max_heapify(max_heap_t *obj, int i)
{
    int left_child = heap_left_child(i);
    int right_child = heap_right_child(i);
    int greatest_idx = i;

    // Get the greatest one among parent, left child and right child
    // the greatest one needs to be put on the top.
    if (left_child <= obj->idx && obj->arr[left_child] > obj->arr[i]) {
        greatest_idx = left_child;
    }

    if (right_child <= obj->idx && obj->arr[right_child] > obj->arr[greatest_idx]) {
        greatest_idx = right_child;
    }

    // Swap current with the greatest one and keep heapifying if parent is not the
    // greatest
    if (greatest_idx != i) {
        SWAP(obj->arr[i], obj->arr[greatest_idx]);
        heap_max_heapify(obj, greatest_idx);
    }
}

/**
 * time: O(logN)
 * which N is the counts of the heap
 */
int heap_pop_max(max_heap_t *obj)
{
    /* The first element is maximum num of the array */
    int res = obj->arr[0];
    /*
     * Swap the first with the last element and do heapify to reconstruct binary
     * heap.
     */
    SWAP(obj->arr[0], obj->arr[obj->idx]);
    /* Decrease number by 1 */
    obj->idx -= 1;
    /* Down heapify from the root */
    heap_max_heapify(obj, 0);

    return res;
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

    max_heap_t *max_heap = heap_create(arr_size);
    int i = 0;

    /* build max binary heap */
    for (i = 0; i < arr_size; i++) {
        heap_insert(max_heap, arr[i]);
    }

    printf("Before sorting\n");
    show_array(arr, arr_size);

    printf("After sorting\n");
    int max_num = 0;
    for (i = 0; i < arr_size; i++) {
        max_num = heap_pop_max(max_heap);
        printf("%d ", max_num);
    }
    printf("\n");

    return 0;
}
