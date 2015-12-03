/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01h.c
	Topik: Pengulangan
	Tanggal: 28 Agustus 2015
	Deskripsi: { Menghitung deret S = 1 - 1/2 + 1/3 - 1/4 + ... + 1/999 - 1/1000 }
 */

/*
 Program HITUNGDERET
 { Menghitung deret S = 1 - 1/2 + 1/3 - 1/4 + ... + 1/999 - 1/1000 }
 */

#include <stdio.h>

//kamus
int n = 1000; //konstanta
int i, tanda;
float s; //jumlah deret


int main ()
{
	tanda= 1;
	s= 1;
	i= 2; //suku berikutnya yang akan dihitung
    while (i<= n)
	{
		tanda= -tanda;
        s+= (double)tanda/i;
		i++;
	}
	printf("%f", s);
	return 0;
}