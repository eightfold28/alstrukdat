/* 
*	NIM/Nama	:
*	Nama file	:
*	Topik		:
*	Tanggal		:
*	Deskripsi 	:
*/
 
#ifndef MESINKAR_H
#define MESINKAR_H
#include "boolean.h"
#include <stdio.h>
#define mark '.'

/*
	DESKRIPSI

	Buatlah mesin karakter yang mengakuisisi input sampai ditemukan mark (end). 
	Input akan di-supply dari standard input-output dalam bahasa C (stdin), contoh input adalah
	"praktikum if2110."
	"   praktikum     if2110    ."
	Dijamin selalu terdapat tanda akhir input yaitu mark "." pada akhir input
	Input merupakan kombinasi karakter yang merupakan anggota dari {a-z, A-Z, 0-9, ' ', '.'}

	Ikutilah Header ini karena telah disesuaikan untuk autograding

*/

//definisi states
char CC;

void START();
/* 	I.S. sembarang
	F.S. CC adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/

void ADV();
/*	I.S. CC!=mark
	F.S. CC adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila CC menunjuk 'I', maka CC berikutnya adalah 'F' 
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/

boolean EOP();
/*	true jika CC==mark */

#endif

