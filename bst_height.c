#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node *create_new_node(int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;

    return ptr;
}

int find_height(struct node *root){
    if(root == NULL){
        return -1;
    }

    int left_height = find_height(root->left);
    int right_height = find_height(root->right);

    return MAX(left_height, right_height) + 1;
}

struct node *insert(struct node *root, int data){
    if(root == NULL) root = create_new_node(data);
    else if(data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

int main(){
    struct node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);

    printf("The height of BST is %d\n", find_height(root));

    return 0;
}