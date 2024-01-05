#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

void add_node(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

struct node *del_first(struct node *head){
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    return head;
}

struct node *del_last(struct node *head){
    if(head != NULL){
        printf("Linked list is already empty");
    }
    else if(head->next != NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head, *temp2 = head;
        while(temp->next != NULL){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    add_node(head, 20);
    add_node(head, 30);
    add_node(head, 40);
    add_node(head, 50);
    add_node(head, 60);
    head = del_first(head);
    head = del_first(head);
    
    struct node *ptr = head;

    int count = 0;
    while(ptr != NULL){
        count++;
        printf("%d.Node Data: %d\n", count, ptr->data);
        ptr = ptr->next;
    }
}