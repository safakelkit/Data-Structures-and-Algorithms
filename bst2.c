#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

void preorder(struct node *root){
    if(root == NULL) return;
    printf("\t\t  %d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("\t\t  %d\n", root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("\t\t  %d\n", root->data);
}

struct node *insert(struct node *root, int data){
    if(root == NULL){
        root = create_new_node(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else root->right = insert(root->right, data);

    return root;
}

bool search(struct node *root, int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left, data);
    else return search(root->right, data);
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

    int num;
    printf("Enter the number you want to search in BST: ");
    scanf("%d", &num);
    if(search(root, num) == true) printf("Data is found\n");
    else printf("Data is not found\n");

    printf("\n\t---Preorder Traversal---\n\n");
    preorder(root);
    printf("\n\t---Inorder Traversal---\n\n");
    inorder(root);
    printf("\n\t---Postorder Traversal---\n\n");
    postorder(root);

    return 0;
}   