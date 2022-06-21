/**
 * Implement stack using array
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *buffer;
    int idx;
    int max_size;
} stack_int_t;

stack_int_t *stack_create(int size)
{
    stack_int_t *res = (stack_int_t *) malloc(sizeof(stack_int_t));
    res->buffer = (int *) malloc(size * sizeof(int));
    res->idx = -1;  // -1 denotes empty
    res->max_size = size;

    return res;
}

bool stack_is_full(stack_int_t *obj)
{
    if (obj->idx == (obj->max_size - 1)) {
        return true;
    }
    return false;
}

bool stack_is_empty(stack_int_t *obj)
{
    if (obj->idx < 0) {
        return true;
    }
    return false;
}

void stack_push(stack_int_t *obj, int val)
{
    if (!stack_is_full(obj)) {
        obj->buffer[++obj->idx] = val;
    }
}

int stack_pop(stack_int_t *obj)
{
    int res = 0;
    if (!stack_is_empty(obj)) {
        res = obj->buffer[obj->idx--];
    }
    return res;
}

int stack_peek_top(stack_int_t *obj)
{
    if (!stack_is_empty(obj)) {
        return obj->buffer[obj->idx];
    }

    return -1;
}

void stack_free(stack_int_t *obj)
{
    free(obj->buffer);
    free(obj);
}

int main(void)
{
    stack_int_t *stack = stack_create(16);
    int i = 0;

    for (i = 0; i < 16; i++) {
        printf("push %d\n", i);
        stack_push(stack, i);
    }

    printf("\n");

    int res = 0;
    for (i = 0; i < 16; i++) {
        res = stack_pop(stack);
        printf("pop %d\n", res);
    }

    stack_free(stack);

    return 0;
}
