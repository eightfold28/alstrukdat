/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01b.c
	Topik: Sekuens
	Tanggal: 28 Agustus 2015
	Deskripsi: Dibaca arus I dan hambatan R, dihitung besarnya tegangan V = I * R dan dituliskan hasilnya
 */

//program tegangan;
//Dibaca arus I dan hambatan R, dihitung besarnya tegangan V = I * R dan dituliskan hasilnya


#include <stdio.h>

/*
KAMUS
I : real  { arus listrik, ampere }
R : real  { hambatan, ohm }
V : real  { tegangan listrik, volt } */

float i, r;

int main ()
{
	printf("Masukkan nilai arus= ");
	scanf("%f", &i);
	printf("Masukkan nilai hambatan= ");
	scanf("%f", &r);
	printf("Maka nilai tegangan listrik= %.2f volt \n", i*r); // output V = i * r
	return 0;
}