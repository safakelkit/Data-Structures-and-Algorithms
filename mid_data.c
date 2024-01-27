#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *new_node(int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    return ptr;
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

struct node *insert(struct node *head, int data){
    if(head == NULL) head = new_node(data);
    else{
        add_at_end(head, data);
    }
    return head;
}

void find_min(struct node *head){
    struct node *temp = head, *temp2 = head;

    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    int pos = count;
    pos /= 2;
    while(pos > 1){
        temp2 = temp2->next;
        pos--;
    }

    if(count % 2 == 0){
        printf("Datas in the middle are: %d - %d\n", temp2->data, temp2->next->data);
    }
    else temp2 = temp2->next; printf("Data in the middle is: %d\n", temp2->data);
}

struct node *reverse(struct node *head){
    
}

int main(){
    struct node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);

    //find_min(head);
    return 0;
}

//1-2-3-4-5-6-7