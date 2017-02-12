/* Nama/ NIM		: Dharma Kurnia Septialoka/ 13514028
 * Nama file		: listrekursif.c
 * Topik			: List Rekursif
 * Tanggal			: 18 November 2015
 * Deskripsi		: List rekrusif ADT
*/

#include "listrekursif.h"
#include <stdio.h>
#include <stdlib.h>

/** Manajemen Memori **/
Address Alokasi (Infotype X) {
	Address P;
	P= (Address) malloc (sizeof(ElmtList));
	if (P!= Nil) {
		Info(P)= X;
		Next(P)= Nil;
	}
	return P;
}
/*	Mengirimkan Address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka Address tidak Nil, dan misalnya menghasilkan P,
	maka Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/

void Dealokasi (Address *P) {
	free(*P);
}
/* 	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian Address P
*/

/** Primitif-primitif yang harus direalisasikan **/
/** Selektor **/
Infotype FirstElmt (List L) {
	Infotype X;

	X= Info(First(L));
	return X;
}
/*	Mengirimkan elemen pertama sebuah list L yang tidak kosong */

List Tail (List L) {
	List X;

	X= Next(L);
	return X;
}
/* Mengirimkan list L yang tidak kosong tanpa elemen pertamanya */

/** Konstruktor **/
List Konso (Infotype e, List L) {
	Address P;

	P= Alokasi(e);
	if (P == Nil) {
		return L;
	} else {
		Next(P)= L;
		return P;
	}
}
/* 	Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
List Konsdot (List L, Infotype e) {
	Address P, P1;

	P= Alokasi(e);
	if (P == Nil) {
		return L;
	} else {
		if (IsListEmpty(L)) {
			return P;
		} else {
			Next(L)= Konsdot(Tail(L), e);
			return L;
		}
	}
}
/* 	Mengirimkan list L dengan tambahan e sebagai elemen terakhir
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/

/** Predikat **/
boolean IsListEmpty (List L) {
	if (L == Nil) {
		return true;
	} else {
		return false;
	}
}
/* 	Mengirimkan true jika list kosong, false jika tidak kosong
	Mungkin yang dikirimkan adalah sebuah list kosong
*/

/** Operasi Lain **/
List Copy (List L) {
	List LTemp;

	if (IsListEmpty(L)) {
		return Nil;
	} else {
		LTemp= Konso(FirstElmt(L), Copy(Tail(L)));
		return LTemp;
	}
}
/* 	Mengirimkan salinan list L (menjadi list baru)
	Jika ada alokasi gagal, mengirimkan L
*/

List Concat (List L1, List L2) {
	List LTemp;

	if (IsListEmpty(L1)) {
		LTemp= Copy(L2);
	} else {
		LTemp= Konso(FirstElmt(L1), Concat(Tail(L1), L2));
	}
	return LTemp;
}
/*	Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
	Jika ada alokasi gagal, menghasilkan Nil
*/

void Printlist (List L) {
	if (IsListEmpty(L)) {
		printf("\n");
	} else if (IsListEmpty(Tail(L))) {
		printf("%d\n", FirstElmt(L));
	} else {
		printf("%d, ", FirstElmt(L));
		Printlist(Tail(L));
	}
}
/*	I.S. L terdefinisi. 
	F.S. Setiap elemen list dicetak.
	Format mencetak: "el1, el2, el3" (no trailing space - ingat berikan newline pada akhir)
	Jika list kosong, tidak perlu mencetak apapun
*/

int NBElmtList (List L) {
	if (IsListEmpty(L)) {
		return 0;
	} else {
		return 1 + NBElmtList(Tail(L));
	}
}
/*	Mengirimkan banyaknya elemen list L, Nol jika L kosong */

boolean Search (List L, Infotype X) {
	if (IsListEmpty(L)) {
		return false;
	} else if (Info(L) == X) {
		return true;
	} else {
		return Search(Tail(L), X);
	}
}
/*	Mengirim true jika X adalah anggota list, false jika tidak 
	L boleh kosong
*/


