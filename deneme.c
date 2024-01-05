#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *add_beg(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = ptr; 

    return head;
}

void add_at_end(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
}

struct node *add_at_pos(struct node *head, int data, int pos){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if(pos == 1){
    ptr->next = head;
    head = ptr; 

    return head;
    }

    struct node *temp = head;

    pos--;
    while(pos != 1){
        temp = temp->next;
        pos--;
    }
    ptr->next = temp->next;
    temp->next = ptr;

    return head;
}

struct node *del_last(struct node *head){
    if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }
    else{
        struct node *temp = head;
        struct node *temp2 = temp;

        while(temp->next != NULL){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;

        return head;
    }
}

struct node *del_first(struct node *head){
    struct node *temp = head;
    head = temp->next;
    free(temp);
    temp = NULL;

    return head;
}

struct node *del_at_pos(struct node *head, int pos){
    if(head->next == NULL){
        free(head);
        head = NULL;

        return head;
    }
    else{
        struct node *temp = head, *temp2 = head;
        while(pos != 1){
            temp2 = temp;
            temp = temp->next;
            pos--;
        }
        temp2->next = temp->next;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 2;
    ptr->next = NULL;
    head->next = ptr;

    head = add_beg(head, 3);
    add_at_end(head, 4);
    add_at_end(head, 5);
    head = add_at_pos(head, 6, 4);
    head = del_first(head);
    head = del_last(head);
    head = del_at_pos(head, 3);

    struct node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    return 0;
}