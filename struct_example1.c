#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[50];
    int age;
    int roll_no;
    float marks;
};

void print(char name[], int age, int roll, float mark){
    printf("\n%s %d %d %.2f", name, age, roll, mark);
    printf("\n\n\n");
}

int main(){
    struct student s1 = {"Nick", 16, 50, 72.5};
    print(s1.name, s1.age, s1.roll_no, s1.marks);
    return 0;
}

//struct yapısı içerisinden argüman olarak almak