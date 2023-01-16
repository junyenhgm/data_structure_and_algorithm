#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int val;
    struct list_node *next;
} list_node_t;

typedef struct {
    list_node_t *node;
    size_t size;
} stack_t;

void stack_push(stack_t *obj, int val)
{
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->val = val;
    new_node->next = obj->node;
    obj->node = new_node;
    obj->size++;
}

int stack_pop(stack_t *obj)
{
    int res = 0;

    if (obj->size > 0) {  // if not empty
        res = obj->node->val;
        list_node_t *tmp = obj->node;
        obj->node = obj->node->next;
        free(tmp);
    }

    return res;
}

int stack_size(stack_t *obj)
{
    return obj->size;
}

void stack_dump(stack_t *obj)
{
    list_node_t *head = obj->node;
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}


int stack_peek_top(stack_t *obj)
{
    int res = 0;

    if (obj->size > 0) {
        res = obj->node->val;
    }

    return res;
}

void stack_free(stack_t *obj)
{
    while (obj->node != NULL) {
        list_node_t *tmp = obj->node;
        obj->node = obj->node->next;
        free(tmp);
    }
}

int main(void)
{
    stack_t stack = {.node = NULL, .size = 0};

    stack_push(&stack, 1);
    stack_push(&stack, 3);
    stack_push(&stack, 5);
    stack_push(&stack, 7);
    stack_push(&stack, 9);
    stack_push(&stack, 11);
    stack_push(&stack, 13);
    stack_push(&stack, 15);

    printf("%d\n", stack_size(&stack));

    stack_dump(&stack);

    printf("pop %d\n", stack_pop(&stack));
    printf("pop %d\n", stack_pop(&stack));
    printf("pop %d\n", stack_pop(&stack));
    printf("pop %d\n", stack_pop(&stack));

    stack_dump(&stack);

    stack_push(&stack, 16);
    stack_push(&stack, 18);
    stack_push(&stack, 20);

    stack_dump(&stack);

    stack_free(&stack);

    return 0;
}
