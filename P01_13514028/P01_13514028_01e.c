/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01e.c
	Topik: Fungsi
	Tanggal: 28 Agustus 2015
	Deskripsi: program UbahdanPeriksaKar
 { Program membaca sebuah karakter, dan melakukan konversi ke nilai integer serta menuliskannya, jika karakter mewakili angka, bernilai ['0'..'9']. Jika yang diketik bukan bernilai ['0'..'9'], program memeriksa apakah karakter itu A atau bukan kemudian menuliskan pesan }
 */

#include <stdio.h>


int KarakterToInteger (char x) //function mengubah karakter ke integer
{
	return x-'0'; //logikanya karakter 0,1,2 pasti punya ascii yang berurutan, maka tinggal dikurang ascii karakter '0'

}

int IsAnaA (char x)
{
	if (x == 'A')
	{
		return 1; //1 artinya true
	}
	else
	{
		return 0; //0 artinya false
	}
}

int main ()
{
	char a,x;
	printf("Masukkan karakter= ");
	scanf("%c", &a); //input karakter yg akan diubah ke integer
	printf("%d\n", KarakterToInteger(a)); //panggil function mengubah karakter ke integer
	printf("Periksa karakter a= ");
	scanf("%c", &x); //input karakter yg diperiksa
	printf("%d\n", IsAnaA(x)); //panggil function apakah A
    return 0;

}