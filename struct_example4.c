#include <stdlib.h>
#include <stdio.h>

struct point {
    int x;
    int y;
};

void print(struct point *ptr){
    printf("%d %d\n", ptr->x, ptr->y);
}

int main(){
    struct point p1 = {25, 50};
    struct point p2 = {75, 100};
    print(&p1);
    print(&p2);
    return 0;
}