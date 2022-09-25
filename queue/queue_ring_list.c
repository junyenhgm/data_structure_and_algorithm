typedef struct _list_node {
    int val;
    struct _list_node *next;
} list_node_t;

typedef struct {
    list_node_t *front;
    list_node_t *rear;
    int counts;
    bool is_full;
    bool is_empty;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    if (k == 0) {
        return NULL;
    }
    MyCircularQueue *obj = malloc(sizeof(MyCircularQueue));
    obj->front = NULL;
    obj->rear = NULL;
    obj->counts = k;
    obj->is_full = false;
    obj->is_empty = true;

    while (k--) {
        list_node_t *new_node = malloc(sizeof(list_node_t));
        if (obj->front == NULL) {
            obj->front = new_node;
            obj->rear = new_node;
        } else {
            obj->front->next = new_node;
            obj->front = obj->front->next;
        }
    }

    obj->front->next = obj->rear;
    obj->front = obj->rear;

    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (obj->is_full) {
        return false;
    }

    if (obj->is_empty) {
        obj->is_empty = false;
        obj->front->val = value;
    } else {
        obj->front = obj->front->next;
        obj->front->val = value;
    }

    if (obj->front->next == obj->rear) {
        obj->is_full = true;
    }

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (obj->is_empty) {
        return false;
    }

    if (obj->is_full) {
        obj->is_full = false;
        obj->rear = obj->rear->next;
    } else {
        if (obj->rear == obj->front) {
            obj->is_empty = true;
            return true;
        }

        obj->rear = obj->rear->next;
    }


    return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (obj->is_empty) {
        return -1;
    }

    return obj->rear->val;
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (obj->is_empty) {
        return -1;
    }
    return obj->front->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    return obj->is_empty;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    return obj->is_full;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    while (obj->front != NULL) {
        list_node_t **tmp = &obj->front;
        obj->front = obj->front->next;
        free(*tmp);
        *tmp = NULL;
    }
}
