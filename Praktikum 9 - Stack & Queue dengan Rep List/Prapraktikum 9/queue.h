/* Nama/ NIM		: Dharma Kurnia Septialoka/ 13514028
 * Nama file		: queue.h
 * Topik		    : ADT QUEUE
 * Tanggal		    : 3 November 2015
 * Deskripsi		: List linier queue
*/

#ifndef	QUEUE_H
#define QUEUE_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/*	Modul Queue
	Direpresentasikan dengan list linier, secara fisik dengan pointer
	Queue direpresentasikan sebagai list dengan first dan last

	Definisi Queue kosong: head dan tail adalah Nil
*/
#define Nil NULL

/* Definisi Type Queue */
typedef int Infotype;
typedef struct tElmtQueue *Address;
typedef struct tElmtQueue {
	Infotype 	info;
	Address 	next;
} ElmtQueue;

typedef struct {
	Address head;
	Address tail;
} Queue;

//selektor	
#define Head(Q) (Q).head
#define Tail(Q) (Q).tail
#define Info(Q) (Q)->info
#define Next(Q) (Q)->next
#define InfoHead(Q) Info(Head(Q))

/** Konstruktor/Kreator **/
void CreateEmpty (Queue *Q);
/*	I.S. sembarang
	F.S. Sebuah Q kosong terbentuk
*/

/* Prototype manajemen memori */
void Alokasi (Address *P, Infotype X);
/*	I.S. P sembarang, X terdefinisi
	F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil
	P = Nil jika alokasi gagal
*/

void Dealokasi (Address *P);
/*	I.S. P adalah hasil alokasi, P <> Nil
	F.S. Alamat P didealokasi, dikembalikan ke sistem
*/


/* Predikat Pemeriksaan Kondisi Queue */
boolean IsEmpty (Queue Q);
/*	Mengirim true jika Q kosong: HEAD(Q) = Nil and TAIL(Q) = Nil */

int NbElmt (Queue Q);
/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/*** Primitif Add/Delete **/
void Add (Queue *Q, Infotype X);
/*	Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi
	berhasil; jika alokasi gagal Q tetap
	I.S. Q mungkin kosong
	F.S. X menjadi TAIL, TAIL "maju"
*/

void Del (Queue *Q, Infotype *X);
/*	Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD
	I.S. Q tidak mungkin kosong
	F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur"
*/

#endif
