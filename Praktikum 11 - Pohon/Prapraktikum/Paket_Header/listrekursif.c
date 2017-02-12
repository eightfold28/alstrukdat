/* Nama/ NIM		: 
 * Nama file		: 
 * Topik			: 
 * Tanggal			: 
 * Deskripsi		: 
*/

#include "listrekursif.h"
#include <stdio.h>
#include <stdlib.h>

/** Manajemen Memori **/
Address Alokasi (Infotype X) {
/*	Mengirimkan Address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka Address tidak Nil, dan misalnya menghasilkan P,
	maka Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/
	//Kamus Lokal
	Address	P;
	//Algoritma
	P = (Address) malloc (sizeof(ElmtList));
	if (P!=Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi (Address *P) {
/* 	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian Address P
*/
	free(*P);
}

/** Primitif-primitif yang harus direalisasikan **/
/** Selektor **/
Infotype FirstElmt (List L) {
/*	Mengirimkan elemen pertama sebuah list L yang tidak kosong */
	return Info(L);
}

List Tail (List L) {
/* Mengirimkan list L yang tidak kosong tanpa elemen pertamanya */
	return Next(L);
}

/** Konstruktor **/
List Konso (Infotype e, List L) {
/* 	Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
	//Kamus Lokal
	Address	P;
	//Algoritma
	P = Alokasi(e);
	if (P!=Nil) {
		Next(P) = L;
		L = P;
	}
	return L;
}

List Konsdot (List L, Infotype e) {
/* 	Mengirimkan list L dengan tambahan e sebagai elemen terakhir
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
	//Kamus Lokal
	Address	P;
	//Algoritma
	if (IsListEmpty(L)) {
		P = Alokasi(e);
		if (P!=Nil) {
			return P;
		}
		else return L;
	}
	else {
		Next(L) = Konsdot(Tail(L),e);
		return L;
	}
}

/** Predikat **/
boolean IsListEmpty (List L) {
/* 	Mengirimkan true jika list kosong, false jika tidak kosong
	Mungkin yang dikirimkan adalah sebuah list kosong
*/
	return (L == Nil);
}

/** Operasi Lain **/
List Copy (List L) {
/* 	Mengirimkan salinan list L (menjadi list baru)
	Jika ada alokasi gagal, mengirimkan L
*/
	//Kamus Lokal
	Address	P;
	List	L_cpy=Nil;
	//Algoritma
	if (IsListEmpty(L)) {
		return L;
	}
	else {
		P = Alokasi (FirstElmt(L));
		if (P!=Nil) {
			L_cpy = P;
			Next(L_cpy) = Copy(Tail(L));
		}
		return L_cpy;
	}
}

List Concat (List L1, List L2) {
/*	Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
	Jika ada alokasi gagal, menghasilkan Nil
*/
	//Kamus Lokal
	List	L_cpy=Nil;
	Address	P;
	//Algoritma
	if (IsListEmpty(L1)) {
		return Copy(L2);
	} 
	else {
		P = Alokasi (FirstElmt(L1));
		if (P!=Nil) {
			L_cpy = P;
			Next(L_cpy) = Concat(Tail(L1),L2);
		}
		return L_cpy;
	}
}

void Printlist (List L) {
/*	I.S. L terdefinisi. 
	F.S. Setiap elemen list dicetak.
	Format mencetak: "el1, el2, el3" (no trailing space - ingat berikan newline pada akhir)
	Jika list kosong, tidak perlu mencetak apapun
*/
	//Algoritma
	if (!IsListEmpty(L)) {
		printf("%d",FirstElmt(L));
		if (Tail(L)!=Nil) printf(", ");
		fflush(stdout);
		Printlist(Tail(L));
	}	
	else printf("\n");
}

int NBElmtList (List L) {
/*	Mengirimkan banyaknya elemen list L, Nol jika L kosong */
	//Algoritma
	if (IsListEmpty(L)) {
		return 0;
	}
	else {
		return 1 + NBElmtList(Tail(L));
	}
}

boolean Search (List L, Infotype X) {
/*	Mengirim true jika X adalah anggota list, false jika tidak */
	//Algoritma
	if (IsListEmpty(L)) {
		return false;
	}
	else {
		if (FirstElmt(L)==X) {
			return true;
		}
		else return Search(Tail(L),X);
	}
}

