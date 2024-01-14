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
    if(root == NULL) root = create_new_node(data);
    else if(data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

struct node *find_min(struct node *root){
    if(root->left != NULL) root = root->left;
    return root;
}

struct node *delete(struct node *root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = delete(root->left, data);
    else if(data > root->data) root->right = delete(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL){ //NO CHILD
        free(root);
        root = NULL;
        }
        else if(root->left == NULL){ //1 CHILD (RIGHT)
            struct node *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }
        else if(root->right == NULL){ //1 CHILD (LEFT)
            struct node *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }
        else{
            struct node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void preorder(struct node *root){
    if(root == NULL) return;
    printf("%d-", root->data);;
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d-", root->data);;
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d-", root->data);
}

int main(){
    struct node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 17);
    

    root = delete(root, 1);
    root = delete(root, 15);
    printf("\n<-");
    preorder(root);
    printf("> Preorder\n");
    printf("<-");
    inorder(root);
    printf("> Inorder\n");
    printf("<-");
    postorder(root);
    printf("> Preorder\n\n");

    return 0;
}