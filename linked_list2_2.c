#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

void add_beg(struct node **head, int new_data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = new_data;
    ptr->next = *head;
    *head = ptr;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 10.,
    head->next = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 20;
    ptr->next = NULL;
    head->next = ptr;

    int new_data = 30;
    add_beg(&head, new_data);
    ptr = head;

    int count = 0;
    while(ptr != NULL){
        count++;
        printf("%d.Node Data: %d\n", count, ptr->data);
        ptr = ptr->next;
    }
    return 0;
}