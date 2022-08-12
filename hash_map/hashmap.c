
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    bool is_set;
    int val;
} hash_arr_t;

typedef struct {
    hash_arr_t *arr;
} hash_map_t;


hash_map_t *hash_map_create(void)
{
    hash_map_t *res = (hash_map_t *) malloc(sizeof(hash_map_t));
    res->arr = (hash_arr_t *) calloc(1000000, sizeof(hash_arr_t));

    return res;
}

void hash_map_put(hash_map_t *obj, int key, int value)
{
    obj->arr[key].val = value;
    obj->arr[key].is_set = true;
}

int hash_map_search(hash_map_t *obj, int key)
{
    if (obj->arr[key].is_set != true) {
        return -1;
    }

    return obj->arr[key].val;
}

bool hash_map_is_set(hash_map_t *obj, int key)
{
    return obj->arr[key].is_set;
}

void hash_map_remove(hash_map_t *obj, int key)
{
    obj->arr[key].val = 0;
    obj->arr[key].is_set = false;
}

void hash_map_free(hash_map_t *obj)
{
    free(obj->arr);
    free(obj);
}

int main(void)
{
    char arr[] = "wioefhweoaigbauigheauifrhegiuah";
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    hash_map_t *hashmap = hash_map_create();

    int value = 0;

    for (i = 0; i < arr_size; i++) {
        /* Fill in hash map */
        value = hash_map_search(hashmap, arr[i]);
        if (value == -1) {
            value = 0;
        }
        /* Record the number of existed char */
        hash_map_put(hashmap, arr[i], value + 1);
    }

    char *a2z = "abcdefghijklmnopqrstuvwxyz";
    int len = strlen(a2z);

    for (i = 0; i < len; i++) {
        value = hash_map_search(hashmap, a2z[i]);
        bool is_key_set = hash_map_is_set(hashmap, a2z[i]);

        printf("key %c is ", a2z[i]);
        if (is_key_set) {
            printf("present, value is %d \n", value);
        } else {
            printf("not present\n");
        }
    }
}
