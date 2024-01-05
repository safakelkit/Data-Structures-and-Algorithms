#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *add_to_empty(int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = ptr;
    return ptr;
}

struct node *add_at_end(struct node *tail, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;
    
    return tail;
}

struct node *create_cll(struct node *tail){
    int n, data;
    int i = 2;
    printf("Enter the number of elements that you want in your cll: ");
    scanf("%d", &n);

    if(n == 0){
        return tail;
    }
    printf("Enter the element number 1: ");
    scanf("%d", &data);
    tail = add_to_empty(data);

    while(i <= n){
        printf("Enter the element number %d: ", i);
        scanf("%d", &data);
        tail = add_at_end(tail, data);
        i++;
    }
    return tail;
}


int main(){
    struct node *tail = NULL;
    tail = create_cll(tail);
    if(tail == NULL)
        printf("No node in the list\n");
    else{
        struct node *temp = tail->next;
        do
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
    
}