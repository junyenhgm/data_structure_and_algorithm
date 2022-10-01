#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

typedef struct word_list {
    char *word;
    struct word_list *next;
} word_list_t;

typedef struct {
    word_list_t *word_node;
} trie_t;

trie_t *trie_create(void)
{
    trie_t *obj = malloc(sizeof(trie_t));
    obj->word_node = malloc(sizeof(word_list_t));
    obj->word_node->word = "";
    obj->word_node->next = NULL;
    return obj;
}

void trie_insert(trie_t *obj, char *word)
{
    if (obj->word_node->word == "") {
        obj->word_node->word = word;
    } else {
        word_list_t *new_word_node = malloc(sizeof(word_list_t));
        new_word_node->word = word;
        new_word_node->next = obj->word_node;
        obj->word_node = new_word_node;
    }
}

bool trie_search(trie_t *obj, char *word)
{
    word_list_t *crawler = obj->word_node;

    while (crawler != NULL) {
        if (strcmp(crawler->word, word) == 0) {
            return true;
        }

        crawler = crawler->next;
    }

    return false;
}

bool trie_start_with(trie_t *obj, char *prefix)
{
    word_list_t *crawler = obj->word_node;

    while (crawler != NULL) {
        if (strncmp(crawler->word, prefix, strlen(prefix)) == 0) {
            return true;
        }

        crawler = crawler->next;
    }

    return false;
}

int trie_print_suggestions(trie_t *obj, char *prefix)
{
    int nums = 0;
    word_list_t *crawler = obj->word_node;

    while (crawler != NULL) {
        if (strncmp(crawler->word, prefix, strlen(prefix)) == 0) {
            printf("%s\n", crawler->word);
            nums++;
        }

        crawler = crawler->next;
    }

    return nums;
}

// O(N), where N is number of words
int trie_get_elected_string(trie_t *obj, char *prefix)
{
    word_list_t *crawler = obj->word_node;

    while (crawler != NULL) {
        if (strncmp(crawler->word, prefix, strlen(prefix)) == 0) {
            strcpy(prefix, crawler->word);
            return 0;
        }

        crawler = crawler->next;
    }

    return -1;
}

static void find_longest_common_prefix(char **strs, int str_count, char *out)
{
    if (str_count == 0) {
        return;
    }

    for (int c = 0; c < strlen(strs[0]); c++) {
        for (int s = 1; s < str_count; s++) {
            if (strs[s][c] != strs[0][c]) {
                // output longest common prefix without modifying original input
                strncpy(out, strs[0], c);
                return;
            }
        }
    }
}

// Input string will be updated if common prefix is longer among suggestions
int trie_autocomplete(trie_t *obj, char *prefix)
{
    int nums = 0;
    word_list_t *crawler = obj->word_node;

    while (crawler != NULL) {
        if (strncmp(crawler->word, prefix, strlen(prefix)) == 0) {
            nums++;
        }

        crawler = crawler->next;
    }

    if (nums == 1) {
        // if there is only one candidate,
        trie_get_elected_string(obj, prefix);
        return nums;
    }

    // Find common prefix among candidates
    char *suggested_words[nums];
    int i = 0;

    crawler = obj->word_node;
    while (crawler != NULL) {
        if (strncmp(crawler->word, prefix, strlen(prefix)) == 0) {
            suggested_words[i++] = crawler->word;
        }

        crawler = crawler->next;
    }

    // find longest common prefix and update it
    find_longest_common_prefix(suggested_words, nums, prefix);

    return nums;
}

void trie_free(trie_t *obj)
{
    if (obj == NULL) {
        return;
    }
    if (obj->word_node == NULL) {
        return;
    }
    word_list_t *crawler = obj->word_node;
    while (crawler != NULL) {
        word_list_t *tmp = crawler;
        crawler = crawler->next;
        free(tmp);
    }
    free(obj);
}

int main(void)
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a",  "there", "answer",
                      "any", "by", "bye",   "their"};

    char output[][32] = {"Not present in trie", "Present in trie"};


    trie_t *root = trie_create();

    // Construct trie
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++) {
        trie_insert(root, keys[i]);
    }

    // Search for different keys
    printf("%s --- %s\n", "the", output[trie_search(root, "the")]);
    printf("%s --- %s\n", "these", output[trie_search(root, "these")]);
    printf("%s --- %s\n", "their", output[trie_search(root, "their")]);
    printf("%s --- %s\n", "thaw", output[trie_search(root, "thaw")]);

    trie_insert(root, "hello");
    trie_insert(root, "dog");
    trie_insert(root, "hell");
    trie_insert(root, "cat");
    trie_insert(root, "a");
    trie_insert(root, "help");
    trie_insert(root, "helps");
    trie_insert(root, "helping");

    char query_str[20] = "h";
    int nums = trie_print_suggestions(root, query_str);

    trie_autocomplete(root, query_str);
    printf("-> %s\n", query_str);

    if (nums == 1) {
        trie_get_elected_string(root, query_str);
        printf("elected_string: %s\n", query_str);
    }

    trie_free(root);
    root = NULL;

    return 0;
}
