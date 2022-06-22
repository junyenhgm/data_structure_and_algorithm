/*

Use 2d matrix to implement hash map with negatives allowed

*/

#include <stdio.h>
#include <string.h>

#define SIZE 100000

void hashmap_put(int hashmap[SIZE][2], int key, int value)
{
    if (key >= 0) {
        hashmap[key][0] = value;
    } else {
        hashmap[abs(key)][1] = value;
    }
}

int hashmap_search(int hashmap[SIZE][2], int key)
{
    int value = 0;
    if (key >= 0) {
        value = hashmap[key][0];
    } else {
        value = hashmap[abs(key)][1];
    }

    return value;
}

int main(void)
{
    int arr[] = {3, -9, 6, 3, -8, 6, -3, 1, 9, 9, 6, -4, 8, 5, -9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    int hashmap[SIZE][2] = {0};
    memset(hashmap, 0, sizeof(hashmap));

    int value = 0;

    for (i = 0; i < arr_size; i++) {
        /* Fill in hash map */
        value = hashmap_search(hashmap, arr[i]);
        hashmap_put(hashmap, arr[i], value + 1);
    }

    for (i = -5; i < 10; i++) {
        value = hashmap_search(hashmap, i);
        printf("key %d is ", i);
        if (value > 0) {
            printf("present, value is %d \n", value);
        } else {
            printf("not present\n");
        }
    }
}
