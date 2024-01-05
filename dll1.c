#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *addToEmpty(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node *add_at_beg(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

void add_at_end(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
}

void add_at_pos(struct node *head, int data, int pos){
    struct node *temp = head, *temp2 = NULL;
    struct node *ptr = malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    pos--;
    while(pos != 1){
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL){
        temp->next = ptr;
        ptr->prev = temp;
    }
    else{
        temp2 = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
        temp2->prev = ptr;
        ptr->next = temp2;
    }
}

int main(){
    struct node *head = NULL;
    head = addToEmpty(head, 45);
    head = add_at_beg(head, 34);
    head = add_at_beg(head, 40);
    add_at_end(head, 20);
    add_at_end(head, 100);
    add_at_pos(head, 200, 2);


    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}