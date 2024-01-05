#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node* del_list(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        free(head);
        head = temp;
    }
    return head;
}

struct node* reverse(struct node *head){
    struct node *prev = NULL, *next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

struct node* del_first(struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
    }
    else{
        struct node* temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    return head;
}

void del_node(struct node *head){
    if(head == NULL){
        printf("Linked list is already empty\n");
    }
    else if(head->next == NULL){
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
}

struct node *del_at_pos(struct node *head, int pos){
    struct node *temp = head, *temp2 = head;
    pos--;

    while(pos != 1){
        temp = temp->next;
    }
}

void del_at_pos(struct node **head, int position){
    struct node *current = *head, *previous = *head;
    if (*head == NULL){
        printf("Linked list is empty");
    }  
    else if(position == 1){
        *head = current->next;
        free(current);
        current = NULL;
    }
    else{
        while (position != 1){
            previous = current;
            current = current->next;
            position--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

void del_node_singleptr(struct node *head){
    if(head == NULL){
        printf("Linked list is already empty\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        while(temp->next->next   != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void add_node(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 100;
    head->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 200;
    current->next = NULL;
    head->next = current;

    int position = 3; 

    add_node(head, 300);
    add_node(head, 400);
    add_node(head, 500);
    add_node(head, 600);
    //del_node_singleptr(head);
    //del_at_pos(&head, position);
    //head = del_first(head);
    //head = del_list(head);
    head = reverse(head);

    if(head == NULL){
        printf("List is deleted\n");
    }

    struct node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}