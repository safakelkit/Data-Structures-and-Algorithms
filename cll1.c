#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *add_at_beg(struct node *tail, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = tail->next;
    tail->next = ptr;

    return tail;
}

struct node *add_at_end(struct node *tail, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = tail->next;

    tail->next = ptr;
    tail = tail->next;
    return tail;
}

struct node *add_at_pos(struct node *tail, int data, int pos){
    struct node *ptr = malloc(sizeof(struct node));
    struct node *temp = tail->next;
    ptr->data = data;
    ptr->next = NULL;
    
    pos--;
    while(pos > 1){
        temp = temp->next;
        pos--;
    }
        ptr->next = temp->next;
        temp->next = ptr;
    if(temp == tail){
        tail = tail->next;
    }
    return tail;
}

struct node *del_at_beg(struct node *tail){
    if(tail == NULL)
        return tail;
    if(tail->next == NULL){
        free(tail);
        tail = NULL;
        return tail;
    }
    
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}

struct node *del_at_end(struct node *tail){
    if(tail == NULL){
        return tail;
    }
    if(tail->next == NULL){
        free(tail);
        tail = NULL;
        return tail;
    }
    
    struct node *temp = tail->next;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return temp;
}

struct node *del_at_pos(struct node *tail, int pos){
    if(tail == NULL){
        return tail;
    }
    if(tail->next == NULL){
        free(tail);
        tail = NULL;
        return tail;
    }

    struct node *temp = tail->next;
    pos--;
    while(pos > 1){
        temp = temp->next;
        pos--;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    temp2 = NULL;
    return tail;
}

void count_elements(struct node *tail){
    int count = 0;
    struct node *temp = tail->next;

    while(temp != tail){
        count++;
        temp = temp->next;
    }
    count++;
    printf("\nNumber of elements: %d\n\n", count);
}

void traverse_cll(struct node *tail){
    struct node *ptr = tail->next;
    int n = 1;
    printf("\n");
    do
    {
        printf("%d. Data: %d\n", n, ptr->data);
        n++;
        ptr = ptr->next;
    } while (ptr != tail->next);
}

int search_an_element(struct node *tail, int data){
    struct node *ptr = tail->next;
    int i = 1;
    do{ 
        if(ptr->data == data){
            return i;
        }
        ptr = ptr->next;
        i++;
    }while(ptr != tail->next);
    return 0;
}

int main(){
    struct node *tail = malloc(sizeof(struct node));
    tail->data = 1;
    tail->next = tail;

    tail = add_at_beg(tail, 2);
    tail = add_at_beg(tail, 3);
    tail = add_at_beg(tail, 4);
    tail = add_at_end(tail, 10);
    tail = add_at_end(tail, 20);
    tail = add_at_end(tail, 32);
    tail = add_at_pos(tail , 6, 3);
    //tail = del_at_beg(tail);
    //tail = del_at_end(tail);
    //tail = del_at_pos(tail, 3);
    traverse_cll(tail);
    count_elements(tail);

    int element, index;
    printf("->Enter the element you want to search: ");
    scanf("%d", &element);
    
    index = search_an_element(tail, element);
    if(index == 0){
        printf("Element not found!\n\n");
    }
    else{
        printf("Element found at %d. Node\n\n", index);
    }

    return 0;
}