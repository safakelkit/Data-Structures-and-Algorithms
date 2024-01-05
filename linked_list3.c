#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node* add_beg(struct node* head, int new_data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = new_data;
    ptr->next = head;
    head = ptr;
    return head;
}

void print_list(struct node* head){
    int count = 0;  
    if(head == NULL){
        printf("Linked list is empty\n");
    }
    struct node *ptr = head;
    while(ptr != NULL){
        count++;
        printf("%d.Node Count: %d\n", count, ptr->data);
        ptr = ptr->next;
    }
}

void add_at_pos(struct node* head, int new_data, int pos){
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = new_data;
    ptr2->next = NULL;
    
    pos--;
    while(pos != 1){
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
}

void add_at_end(struct node *head, int new_data){
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

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 20;
    head->next = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 30;
    ptr->next = NULL;
    head->next = ptr;

    int new_data = 10, new_data2 = 0, new_data3 = 60, new_data4 = 70;
    int new_data5 = 40, new_data6 = 50, pos = 5;

    add_at_end(head,new_data3);
    add_at_end(head,new_data4);
    head = add_beg(head, new_data);
    head = add_beg(head, new_data2);
    add_at_pos(head, new_data6, pos);
    add_at_pos(head, new_data5, pos);
    print_list(head);
    
    return 0;
}