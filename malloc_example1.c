#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int *ptr = (int* )malloc(n*sizeof(int));  //Kullanıcının girdiği sayı(n) * int değişkenin byte büyüklüğü kadar yer ayrıldı
    //(int*) - Typecasting = malloc'un void olarak döndürdüğü pointer int türüne çevrildi

    if (ptr == NULL){
        printf("Memory not available.\n");  //Burada ptr'nin içerisinde bir adres olup olmadığı kontrol edildi.
        exit(1); //Eğer içerisinde bir adres yoksa programdan çıkıldı.
    }
    for (i=0; i<n; i++){  //Burada i, n'e kadar arttırılarak kullanıcının istediği kadar integer değeri alındı.
        printf("Enter an integer: ");  //Kullanıcıdan integer değerlerinin girilmesi istendi.
        scanf("%d", ptr + i);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));  //Kullanıcının girdiği integer değerleri ekrana yazdırıldı.
    }
    return 0;
}