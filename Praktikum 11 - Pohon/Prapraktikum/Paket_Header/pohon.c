/* NIM/Nama		: 13514028/ Dharma Kurnia Septialoka */
/* Nama file	: pohon.c */
/* Topik		: ADT Pohon */
/* Tanggal		: 24 November 2015  */
/* Deskripsi	: ADT pohon */

#include "pohon.h"

/*** Konstruktor ***/
BinTree Tree (Infotype Akar, BinTree L, BinTree R) {
	BinTree T;

	T= (AddressTree) malloc (sizeof(Node));
	if (T == Nil) {
		return Nil;
	} else {
		Akar(T)= Akar;
		Left(T)= L;
		Right(T)= R;
		return T;
	}
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (Infotype Akar, BinTree L, BinTree R, BinTree *P) {
	*P= Tree(Akar, L, R);
}
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */

void BuildTree (BinTree *P) {
	ADV(); //karakter pertama sudah dibaca di driver dg START();
	if (CC == ')') {
		*P= Nil;
	} else {
		*P= Tree(CC, Nil, Nil);
		ADV();
		while (CC == ' ') ADV();
		BuildTree(&Left(*P));
		while (CC == ' ') ADV();
		BuildTree(&Right(*P));
		ADV();
	}
}
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
Memori pasti cukup, alokasi pasti berhasil. */
/* F.S. P dibentuk dari ekspresi dalam pita */

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P) {
	if (P == Nil) {
		return true;
	} else {
		return false;
	}
}
/* Mengirimkan true jika P adalah pohon biner kosong */

boolean IsOneElmt (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (Left(P) == Nil && Right(P) == Nil) {
			return true;
		}
		else {
			return false;
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */

boolean IsUnerLeft (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (!IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P))) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */

boolean IsUnerRight (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P))) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan */

boolean IsBiner (BinTree P) {
	if (!IsTreeEmpty(P)) {
		if (!IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P))) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan */

/*** Traversal ***/
void PrintPreorder (BinTree P) {
	if (IsTreeEmpty(P)) {
		printf("()");
	} else {
		printf("(%c ", Akar(P));
			PrintPreorder(Left(P));
			printf(" ");
			PrintPreorder(Right(P));
			printf(")");
	}
}

/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (a (b (d () ()) ()) (c () ())) */

void PrintInorder (BinTree P) {
	if (IsTreeEmpty(P))
		printf ("()");
	else
	{
		printf("(");
		PrintInorder(Left(P));
		printf(" %c ", Akar(P));
		PrintInorder(Right(P));
		printf(")");
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder:pohon kiri, akar, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (((() d ()) b ()) a (() c ())) */

void PrintPostorder (BinTree P) {
	if (IsTreeEmpty(P))
		printf("()");
	else {
		printf("(");
		PrintPostorder(Left(P));
		printf(" ");
		PrintPostorder(Right(P));
		printf(" %c)",Akar(P));
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (((() () d) () b) (() () c) a) */

void PrintTree (BinTree P, int h) {
	int i;

	if (IsTreeEmpty(P)) {
		printf(".\n");
	} else {
		printf("%c\n", Akar(P));
		for (i= 1; i<= h; i++) {
			printf(" ");
		}
		PrintTree(Left(P), h+h);
		for (i= 1; i<= h; i++) {
			printf(" ");
		}
		PrintTree(Right(P), h+h);
	}
}
/* I.S. P terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul P sudah ditulis dengan indentasi, Nil diganti dengan '.' */
/* Contoh: h=2
a
  b
    d
        .
        .
    .
  c
    .
    .
*/

/*** Searching ***/
boolean SearchTree (BinTree P, Infotype X) {
	if (IsTreeEmpty(P)) return false;
	else {
		if (Akar(P) == X) {
			return true;
		} else {
			return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
		}
	}
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/*** Fungsi-Fungsi Lain ***/
int NbElmt (BinTree P) {
	if (IsTreeEmpty(P)) return 0;
	else {
		return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
	} 
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */

int NbDaun (BinTree P) {
	if (IsTreeEmpty(P)) return 0;
	if (IsOneElmt(P)) return 1;
	return (NbDaun(Left(P)) + NbDaun(Right(P)));
}
/* Mengirimkan banyaknya daun (node) pohon biner P */

boolean IsSkewLeft (BinTree P) {
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (IsOneElmt(P)) {
			return true;
		} else if (IsUnerLeft(P)) {
			return IsSkewLeft(Left(P));
		} else {
			return false;
		}
	}
}
/* Mengirimkan true jika P adalah pohon condong kiri */

boolean IsSkewRight (BinTree P) {
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (IsOneElmt(P)) {
			return true;
		} else if (IsUnerRight(P)) {
			return IsSkewRight(Right(P));
		} else {
			return false;
		}
	}
}
/* Mengirimkan true jika P adalah pohon condong kanan */

int Level (BinTree P, Infotype X) {
	if (IsTreeEmpty(P))	return 0;
	if (Akar(P)==X) return 1;
	else {
		if (SearchTree(Left(P),X))
			return (Level(Left(P),X)+1);
		else
			return (Level(Right(P),X)+1);
	}
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner
P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. */ 

/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, Infotype X) {
	if (IsTreeEmpty(*P)) {
		*P= Tree(X, Nil, Nil);
	} else if (IsUnerLeft(*P) || IsBiner(*P) || IsOneElmt(*P)) {
		AddDaunTerkiri(&Left(*P), X);
	} else {
		AddDaunTerkiri(&Right(*P), X);
	}
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri) {
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			if (Kiri) {
				Left(*P)= Tree(Y, Nil, Nil);
			} else {
				Right(*P)= Tree(Y, Nil, Nil);
			}
		} else {
			AddDaun(&Left(*P), X, Y, Kiri);
			AddDaun(&Right(*P), X, Y, Kiri);
		}
	}
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak k@anan X (jika Kiri = false) */

void DelDaunTerkiri (BinTree *P, Infotype *X) {
	if (IsOneElmt(*P)) {
		*X= Akar(*P);
		free(*P);
		*P= Nil;
	} else {
		if (IsUnerRight(*P)) {
			DelDaunTerkiri(&Right(*P), X);
		} else { //left/ biner/ oneelmt
			DelDaunTerkiri(&Left(*P), X);
		}
	}
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */

void DelDaun (BinTree *P, Infotype X) {
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			free(*P);
			*P= Nil;
		} else {
			DelDaun(&Left(*P), X);
			DelDaun(&Right(*P), X);
		}
	}
}
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */

ListOfNode MakeListDaun (BinTree P) {
	if (IsTreeEmpty(P)) {
		return Nil;
	} else if (IsOneElmt(P)) {
		return Alokasi(Akar(P));
	} else {
		return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
	}

}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong : menghasilkan list yang elemennya adalah semua daun
pohon P, jika semua alokasi list berhasil. Menghasilkan list kosong jika ada
alokasi yang gagal. */

ListOfNode MakeListPreorder (BinTree P) {
	Address Q;

	if (IsTreeEmpty(P)) return Nil;
	else {
		Q = Alokasi(Akar(P));
		if (Q!=Nil) {
			Next(Q) = MakeListPreorder(Left(P));
			return Concat(Q,MakeListPreorder(Right(P)));
		} else
			return Nil;
	}
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen
pohon P dengan urutan Preorder, jika semua alokasi berhasil. Menghasilkan list
kosong jika ada alokasi yang gagal. */

ListOfNode MakeListLevel (BinTree P, int N) {

	if (IsTreeEmpty(P)) return Nil;
	if (N == 1) return Alokasi(Akar(P));
	else return Concat(MakeListLevel(Left(P),N-1), MakeListLevel(Right(P),N-1));

}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen
pohon P yang levelnya=N, jika semua alokasi berhasil. Menghasilkan list kosong jika
ada alokasi yang gagal. */

/*** Balanced tree ***/
BinTree BuildBalanceTree (int n) {
	BinTree P, L, R;
	int nL, nR;
	Infotype X;

	if (n == 0) return Nil;
	else {
		getchar();
		scanf("%c", &X);
		MakeTree(X, Nil, Nil, &P);
		if (P!= Nil) {
			nL= n/2;
			nR= n-nL-1;
			L= BuildBalanceTree(nL);
			R= BuildBalanceTree(nR);
			Left(P)= L;
			Right(P)= R;
			return P;
		} else return Nil;
	}
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca dari input */
/* Contoh (Preorder): (1 (2 (3 () ()) ()) (4 (5 () ()) ())) */

/*** Binary Search Tree ***/
boolean BSearch (BinTree P, Infotype X) {
	return SearchTree(P, X);
	/*
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (Akar(P) == X) return true; 
		else {
			if (X < Akar(P)) return BSearch(Left(P), X);
			else return BSearch(Right(P), X);
		}
	}
	*/
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

BinTree InsSearch (BinTree P, Infotype X) {
	BinTree Q;

	if (IsTreeEmpty(P))
		MakeTree(X, Nil, Nil, &Q);
	else {
		if (X < Akar(P)) {
			Left(P)= InsSearch(Left(P),X);
			Q= P;
		} else { // X > Akar(P)
			Right(P)= InsSearch(Right(P),X);
			Q= P;
		}
	}
	return Q;
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum
ada simpul P yang bernilai X. */

void DelBtree (BinTree *P, Infotype X) {
	AddressTree Q;

	if (X < Akar(*P)) {
		DelBtree(&Left(*P), X);
	} else if (X > Akar(*P)) {
		DelBtree(&Right(*P), X);
	} else if (X == Akar(*P)) {
		if (IsOneElmt(*P)) {
			DelDaun(P, X);
		} else if (IsUnerLeft(*P)) {
			*P= Left(*P);
		} else if (IsUnerRight(*P)) {
			*P= Right(*P);
		} else if (IsBiner(*P)) {
			Q= *P;
			*P= Left(Q);
			Right(*P)= Right(Q);
		}
	}
}
/* I.S. Pohon P tidak kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus, node di bawahnya menjadi node yang dihapus,
gunakan node yang kiri jika kedua node di bawahnya terdefinisi */

