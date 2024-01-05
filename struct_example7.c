#include <stdlib.h>
#include <stdio.h>

struct point{
    int x, y;
};

void print(struct point arr[]){
    int i;
    for(i=0; i<2; i++){
        printf("%d %d\n", arr[i].x + 5, arr[i].y - 2);
    }
}

int main(){
    struct point arr[2] = {{3, 5}, {10, 24}};
    print(arr);
    return 0;
}