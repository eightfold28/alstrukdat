/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01g.c
	Topik: Pengulangan
	Tanggal: 28 Agustus 2015
	Deskripsi: { Menjumlahkan dan mencacah (melakukan counting) nilai-nilai X yang dibaca. Mark = 9999 }
 */

/*Program SUMNBilX
 { Menjumlahkan dan mencacah (melakukan counting) nilai-nilai X yang dibaca. Mark = 9999 }*/

#include <stdio.h>

/*
 KAMUS
 i : integer { banyaknya nilai integer yang akan dibaca }
 X : integer { sekumpulan bilangan integer yang dibaca, diakhiri dengan 9999}
 Sum : integer { jumlah }
 ￼*/

int i, x, sum;


int main ()
{
	i = 0; //inisialisasi awal
	sum= 0;
	printf("Masukkan nilai x, akhiri dg 9999=\n");
	scanf("%d", &x);
	if (x == 9999)
		{
			printf("Banyaknya bilangan = 0 dan hasil penjumlahan = 0");
		}
	else 
		do
			{
				sum= sum + x;
				i= i + 1;
				scanf("%d", &x);
			}	while (x != 9999); //lakukan selama bukan 9999
		printf("Jumlah: %d \n", sum); //output sum
		printf("Banyaknya bilangan: %d \n", i ); //output i

	return 0;
}