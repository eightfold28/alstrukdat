/* Nama/ NIM		: 
 * Nama file		: 
 * Topik		    : 
 * Tanggal		    : 
 * Deskripsi		: 
*/

#ifndef	STACK_H
#define STACK_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/*	MODUL STACK 
	Deklarasi stack yang diimplementasi dengan list linier 
	dengan representasi fisik pointer 
	TOP adalah alamat elemen puncak 
	
	Definisi stack kosong, top adalah Nil
*/
#define Nil NULL

/* Definisi Type Stack */
typedef int Infotype;
typedef struct tElmtStack *Address;
typedef struct tElmtStack {
	Infotype 	info;
	Address 	next;
} ElmtStack;

typedef struct {
	Address top; 
} Stack;

/*	TOP(S) = Nil adalah stack dengan elemen kosong 
	Definisi stack dengan representasi berkait : 
	Jika S adalah Stack maka akses elemen : */
	
#define Top(S) (S).top
#define Info(S) (S)->info
#define Next(S) (S)->next
#define InfoTop(S) Info(Top(S))

/** Konstruktor/Kreator **/

void CreateEmpty (Stack *S);
/*	I.S. Sembarang 
	F.S. Membuat sebuah stack S yang kosong 
	Ciri stack kosong : TOP bernilai Nil 
*/

/* Prototype manajemen memori */
void Alokasi (Address *P, Infotype X);
/*	I.S. P Sembarang, X terdefinisi
	F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil
	P = Nil jika alokasi gagal 
*/

void Dealokasi (Address *P);
/*	I.S. P adalah hasil alokasi, P <> Nil
	F.S. Alamat P didealokasi, dikembalikan ke sistem
*/


/* Predikat Untuk test keadaan KOLEKSI */
boolean IsEmpty (Stack S);
/*	Mengirim true jika Stack kosong : lihat definisi di atas */

/* Operator Dasar Stack */
void Push (Stack *S, Infotype X);
/*	Menambahkan X sebagai elemen Stack S.
	I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil.
	Jika alokasi gagal, S tetap.
*/

void Pop (Stack *S, Infotype *X);
/*	Menghapus X dari Stack S.
	I.S. S tidak kosong
	F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi,
	TOP(S) = Next(TOP(S)).
*/

#endif
