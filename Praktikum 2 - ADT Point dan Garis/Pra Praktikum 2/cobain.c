#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main()
{
    POINT p1;
    POINT p2;
    float dx, dy;

    printf("Baca Point \n \n");
    BacaPoint(&p1);
    BacaPoint(&p2);

    printf("Tulis Point \n \n");
    TulisPoint(p1);
    TulisPoint(p2);

    printf("Tambah Point \n \n");
    TulisPoint(Tambah(p1, p2));

    return 0;
}
