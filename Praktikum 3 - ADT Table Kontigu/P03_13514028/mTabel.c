#include <stdio.h>
#include <stdlib.h>
#include "ADT_TABEL_KONTIGU.h"

/*Nim/ Nama = 13514028/ Dharma Kurnia Septialoka*/

int main()
{
    /* Kamus lokal */
    TabInt T;
    IdxType i;
    ElType X, Y, Z, A;

    /*Algoritma*/
    //MakeEmpty(&T);
    BacaIsi(&T);
    InsSortAsc(&T);
    TulisIsiTab(T);
    printf("%d\n", SumTab(T));
    scanf("%d %d", &X, &i);
    UpdateElmt(&T, i, X);
    TulisIsiTab(T);
    scanf("%d", &Y);
    Del1Urut(&T, Y);
    TulisIsiTab(T);
    scanf("%d", &Z);
    DelAllX(&T, Z);
    TulisIsiTab(T);
    scanf("%d", &A);
    if (SearchUrutB(T, A) == true)
    {
        printf("1\n");
    }
    else
        printf("0\n");
    return 0;
}
