#include <stdlib.h>
#include <stdio.h>

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

struct node *insert(struct node *root, int data){
    if(root == NULL){
        root = create_new_node(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

int find_min_iterative(struct node *root){
    if(root == NULL){
        printf("The Tree is Empty\n");
        return -1;
    }

    struct node *temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int find_max_iterative(struct node *root){
    if(root == NULL){
        printf("The Tree is Empty\n");
        return -1;
    }

    struct node *temp = root;
    
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int find_min_recursive(struct node *root){
    if(root == NULL){
        printf("The Tree is Empty\n");
        return -1;
    }
    else if(root->left == NULL) return root->data;

    return find_min_recursive(root->left);
}

int find_max_recursive(struct node *root){
    if(root == NULL){
        printf("The Tree is Empty\n");
        return -1;
    }
    else if(root->right == NULL) return root->data;

    return find_max_recursive(root->right);
}

int main(){
    struct node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    printf("\nThe min value in BST is(iterative): %d\nThe max value in BST is(iterative): %d\n", find_min_iterative(root), find_max_iterative(root));
    printf("\nThe mix value in BST is(recursive): %d\nThe max value in BST is(recursive): %d\n", find_min_recursive(root), find_max_recursive(root));
    return 0;
}