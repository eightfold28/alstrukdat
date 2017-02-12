

#include "matriks.h" 

/*
 * NIM/Nama  : 13514028/ Dharma Kurnia Septialoka
   	Nama file : mMatriks.c
   	Topik     : ADT Matriks
   	Tanggal   : 17 September 2015
   	Deskripsi : Praktikum matriks
*/

int main(){
    MATRIKS M;
    indeks N, T; //N= baris; T= Kolom
    
    
    scanf("%d %d", &N, &T);
    BacaMATRIKS(&M, N, T);
    
    TulisMATRIKS(M);
    printf("Test-Max T%d Avg=%.2f\n", RataTestTertinggi(M), RataNIlai(M, RataTestTertinggi(M)));
    TulisStatistikTest(M);
    TulisMatriks1(M);

    return 0;
}
