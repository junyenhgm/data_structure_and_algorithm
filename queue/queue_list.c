/*

Implement queue using linked list

                     f
                     |
 N<-O-O-O-O-O-O-O-O<-O
    |
    r

Push to rear
Pop from front

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int val;
    struct list_node *next;
} list_node_t;

typedef struct {
    list_node_t *front;
    list_node_t *rear;
    int counts;
} queue_list_t;

queue_list_t *queue_create(void)
{
    queue_list_t *obj = malloc(sizeof(queue_list_t));
    obj->front = NULL;
    obj->rear = NULL;
    obj->counts = 0;
    return obj;
}


bool queue_is_full(queue_list_t *obj) {}

bool queue_is_empty(queue_list_t *obj)
{
    return (obj->front == NULL);
}

/* Push to rear */
void queue_push(queue_list_t *obj, int val)
{
    list_node_t *node = malloc(sizeof(list_node_t));
    node->val = val;
    node->next = NULL;

    /* If empty */
    if (obj->front == NULL) {
        obj->rear = node;
        obj->front = node;
    } else {
        /* make the next pointer of rear point to new node */
        obj->rear->next = node;
        /* Let rear pointer be the created new node */
        obj->rear = obj->rear->next;
    }
    obj->counts += 1;
}

/* Pop from front */
int queue_pop(queue_list_t *obj)
{
    int res = -1;
    /* if empty */
    if (obj->front == NULL) {
        res = -1;
    } else {
        res = obj->front->val;

        /* Delete node */
        list_node_t *ptr = obj->front;
        obj->front = obj->front->next;
        free(ptr);

        obj->counts -= 1;
    }

    return res;
}

int queue_get_count(queue_list_t *obj)
{
    return obj->counts;
}

int queue_peek(queue_list_t *obj)
{
    int res = -1;
    /* if empty */
    if (obj->front == NULL) {
        res = -1;
    } else {
        res = obj->front->val;
    }

    return res;
}

void queue_free(queue_list_t *obj)
{
    while (!queue_is_empty(obj)) {
        queue_pop(obj);
    }
    free(obj);
}

int main(void)
{
    queue_list_t *queue = queue_create();
    int i = 0;

    for (i = 0; i < 16; i++) {
        queue_push(queue, i);
    }

    int res = 0;

    res = queue_peek(queue);
    printf("peek %d\n", res);

    for (i = 0; i < 16; i++) {
        res = queue_pop(queue);
        printf("pop %d\n", res);
    }

    queue_free(queue);

    return 0;
}
