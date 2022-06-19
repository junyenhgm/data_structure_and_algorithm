/**
 * Implement queue using circular buffer
 *
 */



#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *buffer;
    int write_idx;
    int read_idx;
    int max_size;
} queue_int_t;

queue_int_t *queue_create(int size)
{
    queue_int_t *res = malloc(sizeof(queue_int_t));
    res->write_idx = 0;
    res->read_idx = 0;
    res->max_size = size;
    res->buffer = malloc(size * sizeof(int));

    return res;
}

bool queue_is_full(queue_int_t *handle)
{
    return (((handle->write_idx + 1) % handle->max_size) == handle->read_idx);
}

bool queue_is_empty(queue_int_t *handle)
{
    return (handle->write_idx == handle->read_idx);
}

void queue_push(queue_int_t *handle, int val)
{
    if (!queue_is_full(handle)) {
        handle->buffer[handle->write_idx] = val;

        handle->write_idx = ((handle->write_idx + 1) % handle->max_size);
    }
}

int queue_pop(queue_int_t *handle)
{
    int res = 0;

    if (!queue_is_empty(handle)) {
        res = handle->buffer[handle->read_idx];
        handle->read_idx = ((handle->read_idx + 1) % handle->max_size);
    }

    return res;
}

int queue_peek(queue_int_t *handle)
{
    int res = handle->buffer[handle->read_idx];

    return res;
}

int queue_get_count(queue_int_t *handle)
{
    if (handle->write_idx > handle->read_idx) {
        return (handle->write_idx - handle->read_idx);
    } else {
        return (handle->max_size - (handle->read_idx - handle->write_idx));
    }
}

int main(void)
{
    queue_int_t *queue = queue_create(16);
    int i = 0;

    for (i = 0; i < 16; i++) {
        queue_push(queue, i);
    }

    int res = 0;
    for (i = 0; i < 16; i++) {
        res = queue_pop(queue);
        printf("pop %d\n", res);
    }

    return 0;
}
