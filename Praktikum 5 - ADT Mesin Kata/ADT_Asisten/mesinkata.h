/* 
*	NIM/Nama 	:
*	Nama file 	:
*	Topik 		:
*	Tanggal 	:
*	Deskripsi 	:
*/

#ifndef MESINKATA_H
#define MESINKATA_H
#define mark '.'
#define blank ' '
#define NMax 50
#include "mesinkarakter.h"

//definisi tipe kata
typedef struct {
	char TabKata[NMax];
	int	 Length;
} Kata;

//definisi state mesin kata
boolean EndKata;
Kata	CKata;

/*
	DESKRIPSI

	Buatlah mesin kata yang mengakuisisi input sampai ditemukan mark (end). 
	Input akan di-supply dari standard input-output dalam bahasa C (stdin), contoh input adalah
	"praktikum if2110."
	"   praktikum     if2110    ."
	Dijamin selalu terdapat tanda akhir input yaitu mark "." pada akhir input
	Input merupakan kombinasi karakter yang merupakan anggota dari {a-z, A-Z, 0-9, ' ', '.'}

	[ATTENTION]
	Ikutilah Header ini karena telah disesuaikan untuk autograding

*/

/* Primitif-primitif mesin kata */
void Ignore_Blank();
/*	Mengabaikan satu atau beberapa BLANK
	I.S. : CC sembarang
	F.S. : CC != BLANK atau CC == MARK
*/

void STARTKATA();
/*	I.S. : CC sembarang
	F.S  : Salah satu dari dua kondisi dibawah.
		1. EndKata = true dan CC == Mark
		2. EndKata = false, CKata adalah kata yang sudah diakuisisi, dan CC adalah satu karakter setelah karakter terakhir kata

		Keterangan: CC mengacu pada yang disebut pada mesinkarakter
*/

void ADVKATA();
/*	I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
	dari kata yg sudah diakuisisi
	F.S. : Jika CC == MARK, maka EndKata == true
	atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
	CC karakter pertama sesudah karakter terakhir kata
*/

void SalinKata();
/*	Mengakuisisi kata, menyimpan dalam CKata
	I.S. : CC adalah karakter pertama dari kata
	F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
	NMax, sisa "kata" dibuang; CC == BLANK atau CC == MARK; CC adalah
	karakter sesudah karakter terakhir yang diakuisisi
*/

/* Operasi Lain */
boolean IsKataSama(Kata K1, Kata K2);
/*	Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
	urutan karakter yang menyusun kata juga sama. Sensitif terhadap uppercase dan lowercase
*/

#endif
