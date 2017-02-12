/* NIM/Nama		:  */
/* Nama file	:  */
/* Topik		:  */
/* Tanggal		:  */
/* Deskripsi	:  */

#ifndef pohon_h
#define pohon_h

/* ADT Pohon Biner */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/* Modul lain yang digunakan */
#include "listrekursif.h"
#include "mesinkar.h"

#define Nil NULL
//typedef char Infotype

/*** Definisi Type Pohon Biner ***/
typedef struct tNode *AddressTree;
typedef struct tNode {
	Infotype Info;
	AddressTree Left;
	AddressTree Right;
} Node;
typedef AddressTree BinTree;

/*** Definisi Type List of Node ***/
typedef List ListOfNode;

/*
	BEBERAPA CATATAN
	1. Pohon merupakan pohon biner dengan representasi karakter
	2. pita karakter merupakan stdin (di-supply dari stdin)
*/

/*** PROTOTYPE ***/
/*** Selektor ***/
#define Akar(P) (P)->Info
/* Mengirimkan nilai Akar pohon biner P */

#define Left(P) (P)->Left
/* Mengirimkan Anak Kiri pohon biner P */

#define Right(P) (P)->Right
/* Mengirimkan Anak Kanan pohon biner P */

/*** Konstruktor ***/
BinTree Tree (Infotype Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (Infotype Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */

void BuildTree (BinTree *P);
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
Memori pasti cukup, alokasi pasti berhasil. */
/* F.S. P dibentuk dari ekspresi dalam pita */

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */

boolean IsOneElmt (BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */

boolean IsUnerLeft (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */

boolean IsUnerRight (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan */

boolean IsBiner (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan */

/*** Traversal ***/
void PrintPreorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (a (b (d () ()) ()) (c () ())) */

void PrintInorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder:pohon kiri, akar, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (((() d ()) b ()) a (() c ())) */

void PrintPostorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (((() () d) () b) (() () c) a) */

void PrintTree (BinTree P, int h);
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
boolean SearchTree (BinTree P, Infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/*** Fungsi-Fungsi Lain ***/
int NbElmt (BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */

int NbDaun (BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */

boolean IsSkewLeft (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */

boolean IsSkewRight (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */

int Level (BinTree P, Infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner
P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. */

/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, Infotype X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak k@anan X (jika Kiri = false) */

void DelDaunTerkiri (BinTree *P, Infotype *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */

void DelDaun (BinTree *P, Infotype X);
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */

ListOfNode MakeListDaun (BinTree P);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong : menghasilkan list yang elemennya adalah semua daun
pohon P, jika semua alokasi list berhasil. Menghasilkan list kosong jika ada
alokasi yang gagal. */

ListOfNode MakeListPreorder (BinTree P);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen
pohon P dengan urutan Preorder, jika semua alokasi berhasil. Menghasilkan list
kosong jika ada alokasi yang gagal. */

ListOfNode MakeListLevel (BinTree P, int N);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen
pohon P yang levelnya=N, jika semua alokasi berhasil. Menghasilkan list kosong jika
ada alokasi yang gagal. */

/*** Balanced tree ***/
BinTree BuildBalanceTree (int n);
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca dari input */
/* Contoh (Preorder): (1 (2 (3 () ()) ()) (4 (5 () ()) ())) */

/*** Binary Search Tree ***/
boolean BSearch (BinTree P, Infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

BinTree InsSearch (BinTree P, Infotype X);
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum
ada simpul P yang bernilai X. */

void DelBtree (BinTree *P, Infotype X);
/* I.S. Pohon P tidak kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus, node di bawahnya menjadi node yang dihapus,
gunakan node yang kiri jika kedua node di bawahnya terdefinisi */

#endif
