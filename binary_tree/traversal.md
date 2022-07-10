```
    1
   / \
  2   3
 / \   \
4   5   6

```

preorder traverval ：[1 2 4 5 3 6]

    visit node
    traverse left 
    traverse right

inorder traverval ：[4 2 5 1 3 6]

    traverse left 
    visit node
    traverse right

postorder traverval : [4 5 2 6 3 1]

    traverse left 
    traverse right
    visit node


## Preorder traverval

```c
void preorder_travese(struct TreeNode* root)
{
    /* base case */
    if (root != NULL) {

        /* visit cur */
        visit(root);

        /* visit left child */
        preorder_travese(root->left);

        /* visit right child */
        preorder_travese(root->right);
    } 
}

```

## Inorder traverval

```c
void inorder_travese(struct TreeNode* root)
{
    /* base case */
    if (root != NULL) {

        /* visit left child */
        preorder_travese(root->left);

        /* visit cur */
        visit(root);

        /* visit right child */
        preorder_travese(root->right);
    } 
}

```



## Postorder traverval

```c
void postorder_travese(struct TreeNode* root)
{
    /* base case */
    if (root != NULL) {

        /* visit left child */
        preorder_travese(root->left);

        /* visit right child */
        preorder_travese(root->right);

        /* visit cur */
        visit(root);
    } 
}

```