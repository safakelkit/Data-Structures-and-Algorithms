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

void print_nth_last(struct node *head, int pos){
    struct node *temp = head, *temp2 = head;
    int count = 0, i = 0, n;

     while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(pos > 0 && pos <= count){
        n = count - pos;
        while(i < n){
            temp2 = temp2->next;
            i++;
        }
        printf("%d. Data(%d.Node From the Last): %d\n", n + 1, pos, temp2->data);
    }
    else printf("This is not a valid position! == %d\n", pos);
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

    print_nth_last(head, 2);
    print_nth_last(head, 5);
    print_nth_last(head, 1);
    print_nth_last(head, 0);
    print_nth_last(head, -16);
    print_nth_last(head, 10);

    return 0;
}