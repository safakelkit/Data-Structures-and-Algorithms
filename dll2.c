#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *addToEmpty(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    head = ptr;
    return head;
}

void addAtEnd(struct node *head, int data){
    struct node *temp = head;
    struct node *ptr = malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    while(temp->next != NULL){
        temp = temp->next;
    }
    ptr->prev = temp;
    temp->next = ptr;
}

struct node* create_list(struct node *head){
    int n, data, i;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    if(n == 0){
        return head;
    }
    printf("Enter the element for node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for(i = 1; i < n; i++){
        printf("Enter the element for node %d: ", i + 1);
        scanf("%d", &data);
        addAtEnd(head, data);
    }
    return head;
}   

int main(){
    struct node *head = NULL;
    head = create_list(head);
    struct node *ptr = head;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}  