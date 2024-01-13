#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
};

struct node * create_new_node(int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->leftChild = NULL;
    ptr->rightChild = NULL;

    return ptr;
}

struct node* insert(struct node *root, int data){
    if(root == NULL){
        root = create_new_node(data);
    }
    else if(data <= root->data){
        root->leftChild = insert(root->leftChild, data);
    }
    else{
        root->rightChild = insert(root->rightChild, data);
    }
    return root;
}

bool search(struct node *root, int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->leftChild, data);
    else return search(root->rightChild, data);
}

int main(){
    struct node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    int num;
    printf("Enter a number to search in BST: ");
    scanf("%d", &num);
    if(search(root, num) == true) printf("Data is found\n");
    else printf("Data is not found\n");

    return 0;
}