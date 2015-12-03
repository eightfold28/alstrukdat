/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01f.c
	Topik: Prosedur
	Tanggal: 28 Agustus 2015
	Deskripsi: { Program yang membaca 3 buah integer dan “memutar” 3 buah integer tsb. } 
                ( Jika inputnya: a=A dan b=B, dan c=C, maka outputnya: a=C, b=A, c=B }
 */


/* Program PUTARBIL
 { Program yang membaca 3 buah integer dan “memutar” 3 buah integer tsb. } ( Jika inputnya: a=A dan b=B, dan c=C, maka outputnya: a=C, b=A, c=B }
 */

#include <stdio.h>

void proctukar (int *a, int *b)
{
	int temp;
	temp = *a; //a disimpan dalam temp
	*a = *b; //nilai b diassign ke a
	*b = temp; //nilai temp diassign ke b
}

int main ()
{
	int a, b, c;
	printf("Masukkan nilai a= ");
	scanf("%d", &a);
	printf("Masukkan nilai b= ");
	scanf("%d", &b);
	printf("Masukkan nilai c= ");
	scanf("%d", &c);
	proctukar(&a,&c); //panggil procedure tukar
	proctukar(&b,&c); //panggil procedure tukar
	printf("%d, %d, %d\n", a, b, c);


	return 0;
}