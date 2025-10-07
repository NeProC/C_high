#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <malloc.h>

typedef struct tree
{
    int32_t key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
    uint8_t height;
} tree;

void btUpView(tree *root);
void insert(tree **root, int32_t key, tree *pt);
void inorder_right(tree *root);
void inorder_left(tree *root);
void inorder(tree *root);
tree *findBrother(tree *root, int key);

int main()
{
    tree *tr = NULL;
    insert(&tr, 10, NULL);
    insert(&tr, 5, NULL);
    insert(&tr, 15, NULL);
    insert(&tr, 3, NULL);
    insert(&tr, 7, NULL);
    insert(&tr, 13, NULL);
    insert(&tr, 18, NULL);
    insert(&tr, 1, NULL);
    insert(&tr, 6, NULL);
    insert(&tr, 14, NULL);

    inorder(tr);
    printf("\n");
    inorder_left(tr);
    printf("\n");
    inorder_right(tr);
    printf("\n");
    btUpView(tr);
    printf("\n");
    tree *bro = findBrother(tr, 3);
    if (bro)
    {
        printf("Bro %d \n", bro->key);
    }
    else
    {
        printf("No bro\n");
    }

    printf("\n");
    return 0;
}

tree *findBrother(tree *root, int key)
{
    if (root->key == key)
    {
        return 0;
    }

    while (root && key != root->key)
    {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    if (root == NULL)
        return 0;

    tree *parent = root->parent;
    if (parent->left == NULL || parent->right == NULL)
    {
        return 0;
    }

    if (root == parent->left)
    {
        return parent->right;
    }
    else
    {
        return parent->left;
    }
}

void inorder_right(tree *root)
{
    static uint8_t flag = 0;
    if (root == NULL)
    {
        return;
    }
    if (!flag)
    {
        flag++;
        inorder_right(root->right);
    }
    if (root->right && flag)
    {
        printf("%d ", root->key);
        inorder_right(root->right);
    }
}

void inorder_left(tree *root)
{
    if (root == NULL)
        return;
    if (root->left)
        inorder_left(root->left);
    printf("%d ", root->key);
}

void inorder(tree *root)
{
    if (root == NULL)
        return;
    if (root->left)
        inorder(root->left);
    printf("%d ", root->key);
    if (root->right)
        inorder(root->right);
}

void insert(tree **root, int32_t key, tree *pt)
{
    if (!(*root))
    {
        *root = calloc(1, sizeof(tree));
        if (root == NULL)
            exit(1);
        (*root)->key = key;
        (*root)->parent = pt;
        return;
    }

    else if (key < (*root)->key)
    {
        insert(&(*root)->left, key, *root);
    }
    else if (key > (*root)->key)
    {
        insert(&(*root)->right, key, *root);
    }
    else
    {
        return;
    }
}

void btUpView(tree *root)
{
    if (!root)
        return;

    tree *path[512];
    int depth = 0;
    tree *curr = root;

    while (curr)
    {
        path[depth] = curr;
        depth++;
        if (curr->left)
            curr = curr->left;
        else
            break;
    }

    for (int i = depth - 1; i >= 0; i--)
        printf("%d ", path[i]->key);

    curr = root->right;
    while (curr)
    {
        printf("%d ", curr->key);
        if (curr->right)
            curr = curr->right;
        // else if (curr->left)
        //     curr = curr->left;
        else
            break;
    }

    printf("\n");
}