#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*  Build a balanced BST from an array of numbers*/

struct TreeNode *build_balance_bst(int *arr, int left, int right)
{
    if (left > right) {
        return NULL;
    }

    int mid = left + ((right - left) >> 1);

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = arr[mid];

    root->left = build_balance_bst(arr, left, mid - 1);
    root->right = build_balance_bst(arr, mid + 1, right);

    return root;
}

void free_tree(struct TreeNode *root)
{
    if (root == NULL) {
        return;
    }

    /* Post order */
    free_tree(root->left);
    free_tree(root->right);

    free(root);
}

void traverse_inorder(struct TreeNode *root)
{
    if (root == NULL) {
        return;
    }

    traverse_inorder(root->left);
    printf("%d ", root->val);
    traverse_inorder(root->right);
}

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int main(void)
{
    int nums[] = {1, 3, 5, 6, 7, 8, 10, 11, 12};  // sorted array

    struct TreeNode *root = build_balance_bst(nums, 0, ARRAY_SIZE(nums) - 1);

    traverse_inorder(root);

    free_tree(root);
    root = NULL;

    return 0;
}
