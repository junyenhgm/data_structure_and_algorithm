/*

Inorder Traversal:
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the node.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)

 */


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int get_node_counts(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }

    return get_node_counts(root->left) + get_node_counts(root->right) + 1;
}

void inorder_travese(struct TreeNode *root, int **arr, int *size)
{
    /* base case */
    if (root != NULL) {
        /* visit left child */
        inorder_travese(root->left, arr, size);

        /* visit cur */
        (*arr)[(*size)] = root->val;
        (*size)++;

        /* visit right child */
        inorder_travese(root->right, arr, size);
    }
}

int *inorder_traversal(struct TreeNode *root, int *returnSize)
{
    /* Count the numbers of the node int the tree */
    int node_counts = get_node_counts(root);

    /* Declare return array */
    int *res = (int *) malloc(node_counts * sizeof(int));

    *returnSize = 0;

    /* inorder traverse */
    /* Givern the root fill the res array, record returned size */
    inorder_travese(root, &res, returnSize);

    return res;
}


/*

Given a tree, travese every node in inorder.

    1
   / \
  2   3
 / \   \
4   5   6

*/



int main(void)
{
    struct TreeNode tree_root = {.val = 1, .left = NULL, .right = NULL};
    struct TreeNode tree_node1 = {.val = 2, .left = NULL, .right = NULL};
    struct TreeNode tree_node2 = {.val = 3, .left = NULL, .right = NULL};
    struct TreeNode tree_node3 = {.val = 4, .left = NULL, .right = NULL};
    struct TreeNode tree_node4 = {.val = 5, .left = NULL, .right = NULL};
    struct TreeNode tree_node5 = {.val = 6, .left = NULL, .right = NULL};
    struct TreeNode tree_node6 = {.val = 7, .left = NULL, .right = NULL};

    struct TreeNode *tree = &tree_root;
    tree->left = &tree_node1;
    tree->right = &tree_node2;

    tree->left->left = &tree_node3;
    tree->left->right = &tree_node4;

    // tree->right->left = &tree_node5;
    tree->right->right = &tree_node5;

    int i = 0;
    int size = 0;
    int *res = inorder_traversal(&tree_root, &size);

    for (i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
