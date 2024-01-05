#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void add_at_end(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    while(temp->next != NULL){
        temp = temp->next;
    }
    ptr->prev = temp;
    temp->next = ptr;
}

struct node *del_first(struct node *head){
    struct node *temp = head;
    temp = head->next;
    free(head);
    head = temp;
    return head;
}

struct node *del_last(struct node *head){
    struct node *temp = head, *temp2 = head;
    while(temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
    temp = NULL;
    return head;
}

struct node *del_at_pos(struct node *head, int pos){
    struct node *temp = head, *temp2 = head;

    if(pos == 1){
        head = del_first(head);
        return head;
    }
    if(temp->next == NULL){
        head = del_last(head);
    }
    while(pos != 1){
        temp = temp->next;
        pos--;
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2->next;
    free(temp);
    temp = NULL;
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;
    add_at_end(head, 20);
    add_at_end(head, 30);
    add_at_end(head, 40);
    add_at_end(head, 50);
    add_at_end(head, 60);
    head = del_first(head);
    head = del_last(head);
    head = del_at_pos(head, 2);

    struct node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    return 0;
}