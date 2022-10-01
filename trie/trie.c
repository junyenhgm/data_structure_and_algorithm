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
    // isEndOfWord is true if the node
    // represents end of a word
    bool is_end;
} trie_node_t;

// Every character of the input key is inserted as an individual Trie node
// Returns new trie node (initialized to NULLs)
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
        if (!crawler->children[index]) {
            crawler->children[index] = new_node();
        }

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

        if (!crawler->children[index]) {
            return false;
        }

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

bool is_end_of_word(trie_node_t *root)
{
    return root->is_end;
}

// function to display the content of Trie
void display(trie_node_t *root, char *str, int level)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (is_end_of_word(root)) {
        str[level] = '\0';
        printf("%s\n", str);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->children[i]) {
            str[level] = INDEX_TO_CHAR(i);
            display(root->children[i], str, level + 1);
        }
    }
}

void traverse_trie(trie_node_t *root)
{
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            traverse_trie(root->children[i]);
            printf("%c\n", INDEX_TO_CHAR(i));
        }
    }
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
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++) {
        insert(root, keys[i]);
    }

    // Search for different keys
    printf("%s --- %s\n", "the", output[search(root, "the")]);
    printf("%s --- %s\n", "these", output[search(root, "these")]);
    printf("%s --- %s\n", "their", output[search(root, "their")]);
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")]);

    char buf[20] = {0};

    display(root, buf, 0);

    traverse_trie(root);
    free_trie(root);
    root = NULL;

    return 0;
}