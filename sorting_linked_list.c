#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *add_to_empty(int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void add_at_end(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->data = data;
    ptr->next = NULL;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
}

struct node *create_ll(struct node *head){
    int n, data, i = 2;
    printf("Enter the number of elements you want in Linked List: ");
    scanf("%d", &n);

    if(n == 0){
        return head;
    }
    printf("Enter the element number 1: ");
    scanf("%d", &data);
    head = add_to_empty(data);

    while(i <= n){
        printf("Enter the element number %d: ", i);
        scanf("%d", &data);
        add_at_end(head, data);
        i++;
    }
    return head;
}

struct node *add_sorted(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    struct node *temp = head;
    struct node *temp2 = temp;

    do{
        if(temp->data < data){
            temp2 = temp;
            temp = temp->next;
        }
        else{
            temp2->next = ptr;
            ptr->next = temp;
            break;
        }
    }while(temp != NULL);

    if(temp == NULL){
        temp2->next = ptr;
        ptr->next = NULL;
    }
    return head;
}

void print_list(struct node *head){
    struct node *temp = head;
    int i = 1;
    while(temp != NULL){
        printf("%d. Node Data: %d\n", i, temp->data);
        i++;
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;
    head = create_ll(head);
    printf("\n---Before Insertion as Sorted---\n\n");
    print_list(head);
    printf("\n---After Insertion as Sorted---\n\n");
    head = add_sorted(head, 30);
    head = add_sorted(head, 50);
    head = add_sorted(head, 60);
    print_list(head);

    return 0;
}