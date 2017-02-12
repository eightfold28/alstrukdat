/* Nama/ NIM		:
 * Nama file		: 
 * Topik			: 
 * Tanggal			: 
 * Deskripsi		:
*/

#ifndef LISTREKURSIF_H
#define LISTREKURSIF_H
#include "boolean.h"

/* List rekursif direpresentasi dengan pointer */
#define Nil NULL
typedef char Infotype;
typedef struct tElmtList *Address;
typedef struct tElmtList {
	Infotype 	info;
	Address		next;
} ElmtList;

typedef Address List;

/*
	PERHATIAN

	Bila terdapat perbedaan antara header ini dengan modul, ikutilah header ini
*/

//macro define
#define First(L) L
#define Info(P) (P)->info
#define Next(P) (P)->next

/** Manajemen Memori **/
Address Alokasi (Infotype X);
/*	Mengirimkan Address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka Address tidak Nil, dan misalnya menghasilkan P,
	maka Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/

void Dealokasi (Address *P);
/* 	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian Address P
*/

/** Primitif-primitif yang harus direalisasikan **/
/** Selektor **/
Infotype FirstElmt (List L);
/*	Mengirimkan elemen pertama sebuah list L yang tidak kosong */

List Tail (List L);
/* Mengirimkan list L yang tidak kosong tanpa elemen pertamanya */

/** Konstruktor **/
List Konso (Infotype e, List L);
/* 	Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
List Konsdot (List L, Infotype e);
/* 	Mengirimkan list L dengan tambahan e sebagai elemen terakhir
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/

/** Predikat **/
boolean IsListEmpty (List L);
/* 	Mengirimkan true jika list kosong, false jika tidak kosong
	Mungkin yang dikirimkan adalah sebuah list kosong
*/

/** Operasi Lain **/
List Copy (List L);
/* 	Mengirimkan salinan list L (menjadi list baru)
	Jika ada alokasi gagal, mengirimkan L
*/

List Concat (List L1, List L2);
/*	Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
	Jika ada alokasi gagal, menghasilkan Nil
*/

void Printlist (List L);
/*	I.S. L terdefinisi. 
	F.S. Setiap elemen list dicetak.
	Format mencetak: "el1, el2, el3" (no trailing space - ingat berikan newline pada akhir)
	Jika list kosong, tidak perlu mencetak apapun
*/

int NBElmtList (List L);
/*	Mengirimkan banyaknya elemen list L, Nol jika L kosong */

boolean Search (List L, Infotype X);
/*	Mengirim true jika X adalah anggota list, false jika tidak 
	L boleh kosong
*/


#endif
