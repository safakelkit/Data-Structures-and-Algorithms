#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *add_to_empty(struct node *head, int data){
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

struct node *create_ll(struct node *head){
    int data, n = 2;
    printf("Press 0 to quit\nEnter the element number 1: "); scanf("%d", &data);
    head = add_to_empty(head, data);

    do{
        printf("Enter the element number %d: ", n++); scanf("%d", &data);
        if(data != 0) add_at_end(head, data);
    }while(data != 0);

    return head;
}

void print_ll(struct node *head){
    struct node *temp = head;

    while(temp != NULL){
        printf("%d", temp->data);
        if(temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
}

struct node *empty_merge(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    return ptr;
}

void add_merge(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    
    struct node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
}

struct node *merge_ll(struct node *head, struct node *head2){
    struct node *temp = head, *temp2 = head2;
    struct node *merge = NULL;

    int data;
    while(temp != NULL || temp2 != NULL){
        if(temp != NULL && temp2 != NULL) data = temp->data + temp2->data;
        printf("%d\n", data);
        if(merge == NULL) merge = empty_merge(merge, data); 
        else if(temp != NULL && temp2 != NULL) add_merge(merge, data);

        if(temp != NULL) temp = temp->next;
        if(temp2 != NULL) temp2 = temp2->next;

        if(temp != NULL && temp2 == NULL) add_merge(merge, temp->data);
        else if (temp2 != NULL && temp == NULL) add_merge(merge, temp2->data);
        }
    }

    return merge;
}

int main(){
    struct node *head = NULL;
    printf("---Enter the First Linked List---\n");
    head = create_ll(head);

    printf("\n=> Linked List No. 1 = "); print_ll(head); printf("\n\n");

    printf("---Enter the Second Linked List---\n");
    struct node *head2 = NULL;
    head2 = create_ll(head);

    printf("\n=> Linked List No. 2 = "); print_ll(head2); printf("\n\n");

    struct node *merge = NULL;
    merge = merge_ll(head, head2);
    if(merge == NULL) printf("\n\nERR\n"); 
    print_ll(merge); printf("\n\n");
    
    return 0;
}
