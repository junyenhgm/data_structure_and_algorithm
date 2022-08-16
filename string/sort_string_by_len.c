
/*

Input string: "Abc abcdef ab abcde abcdefg"

Sort string by length of word

Output:
"Ab abc abcde abcdef abcdefg"



input_str = "Abc abcdef ab abcde abcdefg"

convert to 2D array,

char *words_arr[word_nums] = {"Abc", "abcdef", "ab", "abcde", "abcdefg"}

Sort by length of words_arr[row]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b)     \
    do {               \
        char *tmp = a; \
        a = b;         \
        b = tmp;       \
    } while (0)

void sort_array(char **s, int n)
{
    /* Sort by length using insertion sort */
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (strlen(s[j]) <= strlen(s[j + 1])) {
                break;
            }
            SWAP(s[j], s[j + 1]);
        }
    }
}

void sort_string(char *str)
{
    int i = 0;
    int len = strlen(str);
    int word_nums = 0;

    /* Split by space */
    /* The number of words is (space_num + 1) */
    for (i = 0; str[i] != '\0'; i++) {
        /* Change to lowercase */
        str[i] |= (1 << 5);

        if (' ' == str[i]) {
            word_nums += 1;
        }
    }
    word_nums += 1;

    char *words_arr[word_nums];
    int cur_word_num = 0;
    int rear_idx = 0;
    int word_size = 0;
    for (i = 0; i <= len; i++) {
        if (' ' == str[i] || '\0' == str[i]) {
            word_size = i - rear_idx + 1;  // +1 is size of empty char '\0'

            char *new_word = malloc(word_size * sizeof(char));
            memcpy(new_word, &str[rear_idx], word_size);
            rear_idx = i + 1;

            new_word[word_size - 1] = '\0';
            words_arr[cur_word_num++] = new_word;
        }
    }

    sort_array(words_arr, word_nums);

    int cur_idx = 0;
    for (i = 0; i < word_nums; i++) {
        memcpy(&str[cur_idx], words_arr[i], strlen(words_arr[i]));
        cur_idx += strlen(words_arr[i]);
        /* Add space */
        str[cur_idx++] = ' ';
        
        free(words_arr[i]);
    }

    /* Convert the first char to uppercase */
    str[0] &= ~(1 << 5);
    str[len] = '\0';
}

int main(void)
{
    char input_str[] = "Abc abcdef ab abcde abcdefg";
    int n = sizeof(input_str) / sizeof(input_str[0]);

    printf("%s\n", input_str);
    sort_string(input_str);
    printf("%s\n", input_str);
    return 0;
}
