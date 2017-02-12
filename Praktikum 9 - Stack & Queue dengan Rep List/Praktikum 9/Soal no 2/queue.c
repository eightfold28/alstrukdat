/* Nama/ NIM		: Dharma Kurnia Septialoka/ 13514028
 * Nama file		: queue.c
 * Topik		    : ADT QUEUE
 * Tanggal		    : 3 November 2015
 * Deskripsi		: List linier queue
*/

#include "queue.h"

/** Konstruktor/Kreator **/
void CreateEmpty (Queue *Q) {
	Head(*Q)= Nil;
	Tail(*Q)= Nil;
}
/*	I.S. sembarang
	F.S. Sebuah Q kosong terbentuk
*/

/* Prototype manajemen memori */
void Alokasi (Address *P, Infotype X) {
	*P= (Address) malloc (sizeof(ElmtQueue));
	if (*P!= Nil) {
		Info(*P)= X;
		Next(*P)= Nil;
	}
}
/*	I.S. P sembarang, X terdefinisi
	F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil
	P = Nil jika alokasi gagal
*/

void Dealokasi (Address *P) {
	free(*P);
}
/*	I.S. P adalah hasil alokasi, P <> Nil
	F.S. Alamat P didealokasi, dikembalikan ke sistem
*/


/* Predikat Pemeriksaan Kondisi Queue */
boolean IsEmpty (Queue Q) {
	if (Head(Q) == Nil && Tail(Q) == Nil) {
		return true;
	} else {
		return false;
	}
}
/*	Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */

int NbElmt (Queue Q) {
	Address P;
	int nb;

	if (IsEmpty(Q)) {
		return 0;
	} else {
		P= Head(Q);
		nb= 1;
		while(P!= Tail(Q)) {
			nb++;
			P= Next(P);
		}
		return nb;
	}
}
/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/*** Primitif Add/Delete **/
void Add (Queue *Q, Infotype X) {
	Address P;

	Alokasi(&P, X);
	if (P!= Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q)= P;
			Tail(*Q)= P;
		} else {
			Next(Tail(*Q))= P;
			Tail(*Q)= P;
		}
	}
}
/*	Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
	berhasil; jika alokasi gagal Q tetap
	I.S. Q mungkin kosong
	F.S. X menjadi TAIL, TAIL "maju"
*/

void Del (Queue *Q, Infotype *X) {
	Address P;

	*X= InfoHead(*Q);
	P= Head(*Q);

	if (Next(P) == Nil) {
		Head(*Q)= Nil;
		Tail(*Q)= Nil;
	} else {
		Head(*Q)= Next(P);
	}
	Dealokasi(&P);
}
/*	Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD
	I.S. Q tidak mungkin kosong
	F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur"
*/

void tukar (Queue *Q, Address P, Address Prec) {
/*Q lebih depan dari P*/
	/*Kamus*/
	Address temp;
	
	/*Algoritma*/
	temp = Head(*Q);
	while (Next(temp)!= Prec)
		temp = Next(temp);
	
	
	Next(Prec) = Next(P);
	Next(temp) = P;
	Next(P) = Prec;
}

Address AddressDari (Queue Q, Infotype X) {
	/*Kamus*/
	Address O,P;
	
	/*Algoritma*/
	P = Nil;
	
	if (IsEmpty(Q) == false)
	{
		O = Head(Q);
		while (O != Nil)
		{
			if (A(Info(O))==A(X))
				P = O;
			
			O = Next(O);
		}
	}

return P;	
}

