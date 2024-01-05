#include <stdlib.h>
#include <stdio.h>

int main(){
    int *ptr = (int *)malloc(2*sizeof(int));
    int i;

    if (ptr == NULL){
        printf("Memory not allocated");
        exit(1);
    }

    printf("Enter two numbers: \n");
    for(i = 0; i < 2; i++){
        scanf("%d", ptr + i);
    }

    ptr = (int *)realloc(ptr, 4*sizeof(int));
    if (ptr == NULL){
        printf("Memory not allocated");
        exit(1);
    }

    printf("Enter two more numbers: \n");

    for (i = 2; i < 4; i++)
    {
        scanf("%d", ptr + i);
    }

    for (i = 0; i < 4; i++){
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    return 0;
}