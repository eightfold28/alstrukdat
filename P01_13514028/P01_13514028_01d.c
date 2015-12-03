/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01d.c
	Topik: Analisis Kasus
	Tanggal: 28 Agustus 2015
	Deskripsi: { Dibaca T(integer), temperatur air (dalam oC) pada tekanan atmosfir }
                { Harus dituliskan wujud air pada temperatur T: Beku, Cair atau Uap }
 */

//program wujudcair

#include <stdio.h>

int T; //kamus

int main ()
{
    printf("Masukkan nilai temperatur= ");
	scanf("%d", &T); //baca nilai T
	if (T <= 0)
		{
			printf("beku \n");		
		}
	else if (T> 0 && T<= 100)
		{
			printf("cair \n");
		}
	else
		{
			printf("uap \n");
		}
    return 0;

}