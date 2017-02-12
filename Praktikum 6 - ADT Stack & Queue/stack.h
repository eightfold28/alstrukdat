/* 
*	NIM/Nama	:
*	Nama file	:
*	Topik		:
*	Tanggal		:
*	Deskripsi 	:
*/

#ifndef STACK_H
#define STACK_H

/* 	Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik
	dan ukuran sama. TOP adalah alamat elemen puncak
*/

#define Nil 0
#define MaxEl 10
#include "boolean.h"
#include <stdio.h>

typedef int infotype;
typedef int address;

typedef struct {
	infotype 	T[MaxEl+1];
	address 	top;
} Stack;

#define GetTop(S) (S).top
#define InfoTop(S) (S).T[GetTop(S)]

/*
Definisi stack S kosong : S.TOP = Nil
Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl]
Jika S adalah Stack maka akses elemen :
S.T[(S.TOP)] untuk mengakses elemen TOP
S.TOP adalah alamat elemen TOP
Definisi akses dengan Selektor : Isilah dengan selektor yang tepat
*/

//konstruktor
void CreateEmpty(Stack *s);
/*	I.S. Sembarang
	F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
	jadi indeksnya antara 1..MaxEl
	Ciri stack kosong : TOP bernilai Nil
*/

//predikat untuk test keadaan koleksi
boolean IsEmpty(Stack s);
/*	Mengirim true jika Stack kosong: lihat definisi di atas */

boolean IsFull(Stack s);
/*	Mengirim true jika tabel penampung nilai elemen stack penuh */

//operator dasar stack
void Push(Stack *s, infotype X);
/* 	Menambahkan X sebagai elemen Stack S.
	I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. X menjadi TOP yang baru, TOP bertambah 1
*/

void Pop(Stack *s, infotype *X);
/*	Menghapus X dari Stack S.
	I.S. S tidak kosong
	F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1
*/

#endif
