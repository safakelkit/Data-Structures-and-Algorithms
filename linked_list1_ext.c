#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

void add_node(struct node *head, int new_data){
    struct node *ptr, *temp;
    ptr = head;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = new_data;
    temp->next = NULL;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void count_node(struct node *head){     //node sayısını hesaplama
    int count = 0;
    if(head == NULL){
        printf("Linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;

    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    printf("---\nNodes: %d\n---\n", count);
}

void print_data(struct node *head){     //node'lardaki verileri okuma
    int count = 0;
    if(head == NULL){
        printf("Linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        printf("%d.Node Data: %d\n", count, ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 20;
    current->next = NULL;
    head->next = current;

    current = malloc(sizeof(struct node));
    current->data = 30;
    current->next = NULL;
    head->next->next = current;

    current = malloc(sizeof(struct node));
    current->data = 40;
    current->next = NULL;
    head->next->next->next = current;

    add_node(head, 50);
    count_node(head);
    print_data(head);
    return 0;
}

