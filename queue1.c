#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node *front;
    struct node *rear;
};

struct queue *create_queue(){
    struct queue *queue = malloc(sizeof(struct queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void enqueue(struct queue *queue, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;

    if(queue->rear == NULL) queue->front = queue->rear = ptr;
    else{
        queue->rear->next = ptr;
        queue->rear = ptr;
    }
}

int dequeue(struct queue *queue, bool *ptr_bool){
    if(queue->front == NULL) return -1;
    
    struct node *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    free(temp);
    temp = NULL;

    *ptr_bool = true;
    return data;
}

bool isempty(struct queue *queue){
    if(queue == NULL) return true;
    else return false;
}

void print_queue(struct queue *queue){
    struct node *temp = queue->front;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct queue *queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    bool check_dequeue = false;
    bool *ptr_bool = &check_dequeue;
    if(isempty(queue) == false) printf("Bos Degil\n");

    print_queue(queue);

    int dequeue_data = dequeue(queue, ptr_bool);

    if(*ptr_bool == true) printf("Dequeued data is: %d\n", dequeue_data);
    else printf("There is no data in the queue\n");
    print_queue(queue);

    dequeue_data = dequeue(queue, ptr_bool);
    if(*ptr_bool == true) printf("Dequeued data is: %d\n", dequeue_data);
    else printf("There is no data in the queue\n");
    print_queue(queue);

    return 0;
}