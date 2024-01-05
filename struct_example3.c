#include <stdlib.h>
#include <stdio.h>

struct point {
    int x;
    int y;
};

void print(struct point p){
    printf("%d %d\n", p.x, p.y);
}

int main(){
    struct point p1 = {15,30};
    struct point p2 = {45,60};

    print(p1);
    print(p2);
    return 0;
}

//Birden fazla bilinmeyeni tek argüman olarak fonksiyona gönderme
//passing structure variable as argument
