#include <stdlib.h>
#include <stdio.h>

struct point {
    int x, y;
};

struct point* fun(int a, int b){
    struct point *ptr = (struct point*)malloc(sizeof(struct point));
    ptr->x = a;
    ptr->y = b + 5;
    return ptr;
}

void print(struct point *ptr){
    printf("%d %d\n", ptr->x, ptr->y);
}

int main(){
    struct point *ptr1, *ptr2; 
    ptr1 = fun(2, 3);
    ptr2 = fun(6, 9);
    print(ptr1); print(ptr2);
    free(ptr1); free(ptr2);
    return 0;
}

/*
İlk olarak, <stdlib.h> ve <stdio.h> başlık dosyalarını programınıza dahil ediyorsunuz. Bu başlık dosyaları, dinamik bellek tahsis etmek (malloc ve free) ve ekrana çıktı vermek (printf) için gereken fonksiyonları içerir.

struct point adında bir veri yapısı (struct) tanımlıyorsunuz. Bu veri yapısı, iki tamsayı değerini (x ve y koordinatları) içerir.

fun adında bir fonksiyon tanımlıyorsunuz. Bu fonksiyon, iki tamsayı argümanı alır ve bir struct point işaretçisi (struct point*) döndürür. Fonksiyon şunları yapar:

Dinamik bellek tahsisi için malloc kullanarak bir struct point boyutunda bellek alanı ayırır.
Bu bellek alanını işaret eden bir işaretçi (ptr) oluşturur.
İşaretçinin x değerini verilen 'a' argümanı ile ayarlar.
İşaretçinin y değerini verilen 'b' argümanı üzerine 5 ekleyerek ayarlar.
Oluşturulan işaretçiyi döndürür.
print adında başka bir fonksiyon tanımlıyorsunuz. Bu fonksiyon, bir struct point işaretçisi alır ve bu işaretçinin işaret ettiği verileri ekrana yazdırır.

main fonksiyonunda, iki struct point işaretçisi olan ptr1 ve ptr2 tanımlıyorsunuz. Bu işaretçiler başlangıçta boş (NULL) işaret eder.

ptr1 ve ptr2 işaretçilerini fun fonksiyonu aracılığıyla tanımlıyorsunuz. İlk olarak, fun fonksiyonunu 2, 3 ve 6, 9 argümanları ile çağırarak iki ayrı struct point işaretçisi oluşturursunuz. Bu işlev, her bir işaretçiyi ayrı bellek alanına tahsis eder, bu işaretçilerin x ve y değerlerini ayarlar ve işaretçileri döndürür.

Oluşturulan ptr1 ve ptr2 işaretçilerini kullanarak print fonksiyonunu çağırırsınız, bu sayede her bir işaretçinin işaret ettiği struct point verilerini ekrana yazdırırsınız.

Son olarak, artık ihtiyacınız olmayan bellek alanını serbest bırakmak için free fonksiyonunu kullanırsınız. Bu, bellek sızıntılarını önlemek ve gereksiz bellek kullanımını temizlemek için önemlidir.

Program sona erdiğinde, main fonksiyonunda return 0; kullanarak başarıyla sona erdiğini belirtirsiniz.
*/