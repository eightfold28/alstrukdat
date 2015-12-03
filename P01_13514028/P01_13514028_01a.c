/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01a.c
	Topik: Sekuens
	Tanggal: 28 Agustus 2015
	Deskripsi: Menulis "HELLO" berikut nama yang diberikan dari piranti masukan ke piranti keluaran
*/

//Program HELLOX
//{ Menulis "HELLO" berikut nama yang diberikan dari piranti masukan ke piranti keluaran }

#include <stdio.h> 

char name [20]; //Panjang string pesan pada saat deklarasi di kamus sudah diketahui yaitu 20.

int main ()
{
    scanf("%s", name); //input name
    printf("hello, %s \n", name); // output hello, name
    return 0;
}