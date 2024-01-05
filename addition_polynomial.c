#include <stdlib.h>
#include <stdio.h>

struct node{
    float coefficient;
    int exponent;
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

void polyAdd(struct node *head1, struct node *head2){
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *head3 = NULL;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->exponent == temp2->exponent){
            head3 = insert(head3, temp1->coefficient + temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->exponent > temp2->exponent){
            head3 = insert(head3, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        else if(temp1->exponent < temp2->exponent){
            head3 = insert(head3, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
    }
    
    while(temp1 != NULL){
        head3 = insert(head3, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        head3 = insert(head3, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }
    print(head3);
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

int main(){
    struct node *head1 = NULL, *head2 = NULL;
    printf("Enter the first polynomial\n");
    head1 = create(head1);
    printf("Enter the second polynomial\n");
    head2 = create(head2);

    printf("---\nBefore the multiplication---\nFirst polynomial: "); print(head1);
    printf("\nSecond polynomial: "); print(head2);
    
    printf("\n---\nAfter the multiplication---\n");
    polyAdd(head1, head2);

    return 0;
}

