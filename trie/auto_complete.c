#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int) c - (int) 'a')
#define INDEX_TO_CHAR(n) ((char) n + (char) 'a')

// Trie node
typedef struct trie_node {
    struct trie_node *children[ALPHABET_SIZE];
    bool is_end;
} trie_node_t;

trie_node_t *new_node(void)
{
    trie_node_t *node = NULL;

    node = (trie_node_t *) malloc(sizeof(trie_node_t));

    if (node) {
        node->is_end = false;

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }

    return node;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
// O(len(key))
void insert(trie_node_t *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    trie_node_t *crawler = root;

    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        if (!crawler->children[index])
            crawler->children[index] = new_node();

        crawler = crawler->children[index];
    }

    // mark last node as leaf
    crawler->is_end = true;
}

// Returns true if key presents in trie, else false
// O(len(key))
bool search(trie_node_t *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *crawler = root;

    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);

        if (!crawler->children[index])
            return false;

        crawler = crawler->children[index];
    }

    return (crawler->is_end);
}

bool is_last_node(trie_node_t *root)
{
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            return false;
        }
    }
    return true;
}

// Recursive function to print auto-suggestions for given
// node.
void print_suggestions(trie_node_t *root, char *cur_prefix, int *num)
{
    // found a string in Trie with the given prefix
    if (root->is_end) {
        (*num)++;
        printf("%s\n", cur_prefix);
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            // child node character value
            char child = INDEX_TO_CHAR(i);
            strncat(cur_prefix, &child, 1);
            size_t len = strlen(cur_prefix);
            print_suggestions(root->children[i], cur_prefix, num);
            cur_prefix[len - 1] = '\0';
        }
    }
}

// print suggestions for given query prefix.
int auto_suggestions(trie_node_t *root, char *query)
{
    trie_node_t *crawler = root;
    size_t len = strlen(query);
    int i;
    for (i = 0; i < len; i++) {
        int ind = CHAR_TO_INDEX(query[i]);

        // no string in the Trie has this prefix
        if (!crawler->children[ind]) {
            return 0;
        }

        crawler = crawler->children[ind];
    }
    // If prefix is present as a word, but
    // there is no subtree below the last
    // matching node.
    if (is_last_node(crawler)) {
        printf("%s\n", query);
        return -1;
    }
    int sugs_num = 0;
    print_suggestions(crawler, query, &sugs_num);
    return sugs_num;
}

void free_trie_children(trie_node_t *root)
{
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            free_trie_children(root->children[i]);
            free(root->children[i]);
            root->children[i] = NULL;
        }
    }
}

void free_trie(trie_node_t *root)
{
    free_trie_children(root);
    free(root);
}

int main(void)
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a",  "there", "answer",
                      "any", "by", "bye",   "their"};

    char output[][32] = {"Not present in trie", "Present in trie"};


    trie_node_t *root = new_node();

    // Construct trie
    for (int i = 0; i < ARRAY_SIZE(keys); i++) {
        insert(root, keys[i]);
    }

    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    char query_str[20] = "a";
    int comp = auto_suggestions(root, query_str);

    printf("Number: %d\n", comp);

    if (comp == -1) {
        printf("No other strings found with this prefix\n");
    }

    else if (comp == 0) {
        printf("No string found with this prefix\n");
    }

    // traverse_trie(root);
    free_trie(root);
    root = NULL;

    return 0;
}