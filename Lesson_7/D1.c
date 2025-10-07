#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <malloc.h>

typedef struct tree{
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

int main() {
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
    insert(&tr, 30, NULL);

    inorder(tr);
    printf("\n");
    inorder_left(tr);
    printf("\n");
    inorder_right(tr);
    printf("\n");
    return 0;
}

void btUpView(tree *root)
{
    if (root == NULL) {
        return;
    }

}

void inorder_right(tree *root)
{
    static uint8_t flag = 0;
    if(root == NULL){
        return;
    }
    if(!flag){
        flag++;
        inorder_right(root->right);
    }
    if(root->right && flag){
        printf("%d ", root->key);
        inorder_right(root->right);
    }
    
}

void inorder_left(tree *root) 
{
    if(root == NULL)
        return;
    if(root->left)
        inorder_left(root->left);
    printf("%d ",root->key);
    
}

void inorder(tree *root) 
{
    if(root == NULL)
        return;
    if(root->left)
        inorder(root->left);
    printf("%d ",root->key);
    if(root->right)
        inorder(root->right);

}

void insert(tree **root, int32_t key, tree *pt)
{
    if(!(*root)){
        *root = calloc(1, sizeof(tree));
        (*root)->key = key;
        (*root)->parent = pt;
    }
    
    else if (key < (*root)->key){
        insert(&(*root)->left, key, *root);
    }
    else{
        insert(&(*root)->right, key, *root);
    }
}