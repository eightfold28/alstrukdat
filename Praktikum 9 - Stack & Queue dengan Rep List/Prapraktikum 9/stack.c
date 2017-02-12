/* Nama/ NIM		: Dharma Kurnia Septialoka/ 13514028
 * Nama file		: stack.h
 * Topik		    : ADT LIST STACK
 * Tanggal		    : 3 November 2015
 * Deskripsi		: STACK dalam representasi list linier biasa
*/

#include "stack.h"

/** Konstruktor/Kreator **/
void CreateEmpty (Stack *S) {
	Top(*S)= Nil;
}
/*	I.S. Sembarang 
	F.S. Membuat sebuah stack S yang kosong 
	Ciri stack kosong : TOP bernilai Nil 
*/

/* Prototype manajemen memori */
void Alokasi (Address *P, Infotype X) {
	*P= (ElmtStack *) malloc (sizeof(ElmtStack));
	if (*P!= Nil) {
		Info(*P)= X;
		Next(*P)= Nil;
	}
}
/*	I.S. P Sembarang, X terdefinisi
	F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil
	P = Nil jika alokasi gagal 
*/

void Dealokasi (Address *P) {
	free(*P);
	*P= Nil;
}
/*	I.S. P adalah hasil alokasi, P <> Nil
	F.S. Alamat P didealokasi, dikembalikan ke sistem
*/


/* Predikat Untuk test keadaan KOLEKSI */
boolean IsEmpty (Stack S) {
	if (Top(S) == Nil) {
		return true;
	} else {
		return false;
	}
}
/*	Mengirim true jika Stack kosong : lihat definisi di atas */

/* Operator Dasar Stack */
void Push (Stack *S, Infotype X) {
		Address P;

		Alokasi(&P, X);
		if (P!= Nil) {
			Next(P)= Top(*S);
			Top(*S)= P;
		}
}
/*	Menambahkan X sebagai elemen Stack S.
	I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil.
	Jika alokasi gagal, S tetap.
*/

void Pop (Stack *S, Infotype *X) {
	Address P;

	*X= InfoTop(*S);
	P= Top(*S);
	Top(*S)= Next(P);
	Dealokasi(&P);
}
/*	Menghapus X dari Stack S.
	I.S. S tidak kosong
	F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi,
	TOP(S) = Next(TOP(S)).
*/

