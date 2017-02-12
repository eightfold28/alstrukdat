//
//  stack.c
//  
//
//  Created by Dharma Kurnia Septialoka on 10/6/15.
//
//

#include "stack.h"

//konstruktor
void CreateEmpty(Stack *s) {
/*	I.S. Sembarang
	F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl
	jadi indeksnya antara 1..MaxEl
	Ciri stack kosong : TOP bernilai Nil
 */
    GetTop(*s) = Nil;
}

//predikat untuk test keadaan koleksi
boolean IsEmpty(Stack s) {
/*	Mengirim true jika Stack kosong: lihat definisi di atas */
    return (GetTop(s) == Nil);
}

boolean IsFull(Stack s) {
/*	Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (GetTop(s) == MaxEl);
}

//operator dasar stack
void Push(Stack *s, infotype X) {
/* 	Menambahkan X sebagai elemen Stack S.
	I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. X menjadi TOP yang baru, TOP bertambah 1
 */
    GetTop(*s) ++;
    InfoTop(*s) = X;
}

void Pop(Stack *s, infotype *X) {
/*	Menghapus X dari Stack S.
	I.S. S tidak kosong
	F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1
 */
    *X= InfoTop(*s);
    GetTop(*s)--;
}