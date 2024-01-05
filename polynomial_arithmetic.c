#include <stdlib.h>
#include <stdio.h>

struct node{
    int exponent;
    float coefficient;
    struct node *next;
};

struct node *insert(struct node *head, float coef, int expo){
    struct node *temp;
    struct node *ptr = malloc(sizeof(struct node));
    ptr->exponent = expo;
    ptr->coefficient = coef;
    ptr->next = NULL;

    if(head == NULL || expo > head->exponent){
        ptr->next = head;
        head = ptr;
    }
    else{
        temp = head;
        while(temp->next != NULL && temp->next->exponent > expo){
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return head;
}

struct node *create(struct node *head){
    int n;
    int i = 1;
    float coef;
    int expo;

    printf("Enter the number of terms :");
    scanf("%d", &n);

    while(i <= n){
        printf("Enter the coefficient of term %d: ",i);
        scanf("%f", &coef);
        printf("Enter the exponent of term %d: ",i);
        scanf("%d", &expo);
        
        head = insert(head, coef, expo);
        i++;
    }
    return head;
}

void print(struct node *head){
    struct node *temp = head;
    
    if(head == NULL){
        printf("No polinomial\n");
    }
    else{
        while(temp != NULL){
            printf("(%.1fx^%d)", temp->coefficient, temp->exponent);
            temp = temp->next;
            if(temp != NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}

int main(){
    struct node *head = NULL;
    printf("Enter the polynomial\n");
    head = create(head);
    print(head);

    return 0;
}