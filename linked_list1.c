#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 20;
    current->next = NULL;
    head->next = current;
    return 0;
}