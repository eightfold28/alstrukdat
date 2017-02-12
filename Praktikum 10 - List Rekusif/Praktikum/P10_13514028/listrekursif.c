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

boolean IsOneElmt(List L) {
	if (IsListEmpty(L)) {
		return false;
	} else {
		if (IsListEmpty(Tail(L))) {
			return true;
		} else {
			return false;
		}
	}
}
			
/* Menghasilkan true jika L hanya terdiri dari satu elemen. */

void MinMax (List L, Infotype *Min, Infotype *Max) {
	Infotype Min1, Max1;
	
	if (IsOneElmt(L)) {
		*Min= FirstElmt(L);
		*Max= FirstElmt(L);
	} else {
		MinMax(Tail(L), &Min1, &Max1);
		if (Min1 < FirstElmt(L)) {
			*Min= Min1;
		} else {
			*Min= FirstElmt(L);
		}
		if (Max1 > FirstElmt(L)) {
			*Max= Max1;
		} else {
			*Max= FirstElmt(L);
		}
	}
}

/* I.S. L terdefinisi, Min dan Max sembarang.
F.S. Min berisi nilai elemen L terkecil, Max berisi nilai elemen L terbesar. */

int ListCompare (List L1, List L2) {
	if ((L1 == Nil) && (L2 == Nil)) {
		return 0;
	} else if ((L1 != Nil) && (L2 == Nil)) {
		return 1;
	} else if ((L1 == Nil) && (L2 != Nil)) {
		return -1;
	} else if (FirstElmt(L1) > FirstElmt(L2)) {
		return 1;
	} else if (FirstElmt(L1) < FirstElmt(L2)) {
		return -1;
	} else {
		return 0 + ListCompare(Tail(L1), Tail(L2));
	}
	/*
	if (IsOneElmt(L1) && IsOneElmt(L2)) {
		if (FirstElmt(L1) == FirstElmt(L2)) {
			return 0;
		} else if (FirstElmt(L1) > FirstElmt(L2)) {
			return 1;
		} else {
			return -1;
		}
	} else {
		if (IsOneElmt(L1)) { // L2 >1
			return -1;
		} else if (IsOneElmt(L2)) { // L1 > 1
			return 1;
		} else { // L1 dan L2 > 1
			if (FirstElmt(L1) == FirstElmt(L2)) {
				return ListCompare(Tail(L1), Tail(L2));
			} else if (FirstElmt(L1) > FirstElmt(L2)) {
				return 1;
			} else {
				return -1;
			}
		}
	}*/
}
	
	
/* Menghasilkan 1 jika L1 > L2, 0 jika L1 = L2, dan -1 jika L1 < L2.
L1 dan L2 tidak kosong.
L1 = L2 jika memiliki jumlah elemen yang sama dan semua elemen pada urutan yang
bersesuaian juga sama. Misalnya [3,5,7,2,8] = [3,5,7,2,8].
L1 > L2 jika ditemukan e1x > e2x dengan x adalah posisi terkecil kemunculan
elemen di L1 dan L2 yang tidak sama. ATAU jika semua character pada
urutan yang bersesuaian sudah sama, tetapi panjang L1 > panjang L2.
Misalnya [3,5,7,9] > [3,5,6,7,8]; [1,2,3,4,5] > [1,2,3].
L1 < L2 adalah kebalikan dari L1 > L2. */


void SplitOnX (List L, Infotype X, List *L1, List *L2) {
	List La, Lb;
	
	if (IsListEmpty(L)) {
		*L1= Nil;
		*L2= Nil;
	} else if (IsOneElmt(L)) {
		if (FirstElmt(L) < X) {
			*L1= Konso(FirstElmt(L), La);
			*L2= Nil;
		} else {
			*L2= Konso(FirstElmt(L), Lb);
			*L1= Nil;
		}
	} else {
		if (FirstElmt(L) < X) {
			*L1= Konso(FirstElmt(L), La);
		} else {
			*L2= Konso(FirstElmt(L), Lb);
		}
		SplitOnX(Tail(L), X, &La, &Lb);
	}
}
	
	/*
	List La, Lb;
	
	if (FirstElmt(L) < X) {
		Konso(FirstElmt(L), *L1);
	} else {
		SplitOnX(Tail(L), X, &La, &Lb);
		Konso(FirstElmt(L), *L2);
	}
	*/

/*I.S. L dan X terdefinisi, L1 dan L2 sembarang.
F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan kemunculan
yang sama, L2 berisi semua elemen L yang tidak masuk ke L1, dengan urutan
kemunculan yang sama.*/

boolean IsAllExist(List L1, List L2) {
	if (IsListEmpty(L1)) {
		return false;
	} else {
		if (IsListEmpty(L2)) {
			return false;
		} else {
			if (IsOneElmt(L1)) {
				if (Search(L2, FirstElmt(L1))) {
					return true;
				} else {
					return false;
				}
			} else {
				if (Search(L2, FirstElmt(L1))) {
					return IsAllExist(Tail(L1), L2);
				}
			
			/* (Search(L2, FirstElmt(L1))) {
				if (IsAllExist(Tail(L1), L2)) {
					return true;
				} else {
					return false;
				}
			} else {
				return false;
			} */
		}
	}
}
}
			
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpmemperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */

List CopyReverse (List L) {
	List L1;
	
	if (IsListEmpty(L)) {
		return Nil;
	} else {
		L1= Konsdot(CopyReverse(Tail(L)), FirstElmt(L));
		return L1;
	}
} 
/*
	
/* Menghasilkan list dengan elemen-elemen yang sama dengan L namun dengan urutan
kemunculan yang terbalik.
Misalnya: CopyReverse([2,3,4,5,6]) = [6,5,4,3,2] */




