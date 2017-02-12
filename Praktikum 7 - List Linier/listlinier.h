/* Nama/ NIM		: 
 * Nama file		: 
 * Topik		    : 
 * Tanggal		    : 
 * Deskripsi		: 
*/

#ifndef LISTLINIER_H
#define LISTLINIER_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

//Konstanta
#define Nil NULL
 
typedef int Infotype;
typedef struct TElmtList *Address;

typedef struct TElmtList {
	Infotype 	info;
	Address 	next;
} ElmtList;

typedef struct {
	Address		first;
} List;
 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

/*
	LIST INI MERUPAKAN VARIASI 1 - FISIK POINTER DENGAN FIRST EKSPLISIT

	BEBERAPA DEFINISI
	1. List Kosong -> First(L) bernilai Nil
	2. Elemen terakhir, bila Next(P) adalah Nil, maka P merupakan alamat elemen terakhir pada list
	
	CATATAN TEKNIS TENTANG EXECUTION FAULIRE
	1. Autograder akan menangani stackoverflow. Stackoverflow maupun alokasi memori yang buruk akan menyebabkan execution failure. 
	   Memori Limit adalah 16Mb. Test Case dijamin tidak akan melebihi 100 elemen, sehingga memori limit yang diberikan sudah SANGAT BERLEBIH untuk kondisi 
	   tidak terjadi stackoverflow.
	2. Hati-hati terhadap segmentation fault, akseslah memori yang benar.
	3. Operasi terhadap pointer harus hati-hati, jangan mengakses pointer yang sudah di-free.
	4. Cek berbagai macam kondisi, misal saat prekon disebutkan kondisi sembarang, cek untuk kasus kosong dan kasus isi
	5. Untuk kesalahan umum pada C programming, bacalah http://www.cs.mun.ca/~michael/c/problems.html

	LAIN-LAIN
	1. Untuk penjelasan detail skema pemrosesan list serta fungsional list linear, silahkan melihat diktat/slide kuliah
	2. Bila terdapat perbedaan versi header asisten dengan modul, ikuti versi asisten. Informasi perbedaan ada pada tiap fungsi/prosedur
*/
 
boolean IsListEmpty (List L);
/* Mengirim true jika list kosong */

void CreateList (List *L);
/*	I.S. sembarang
	F.S. Terbentuk list kosong 
*/

Address Alokasi (Infotype X);
/*	Mengirimkan Address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka Address tidak Nil, dan misalnya menghasilkan P, maka
	Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/

void Dealokasi (Address *P);
/*	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian Address P
*/

// PENCARIAN SEBUAH ELEMEN LIST
Address Search (List L, Infotype X);
/*	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan Address elemen tersebut
	Jika tidak ada, mengirimkan Nil
*/

boolean FSearch (List L, Address P);
/*	Mencari apakah ada elemen list yang beralamat P
	Mengirimkan true jika ada, false jika tidak ada
*/

Address SearchPrec (List L, Infotype X);
/*	Mengirimkan Address elemen sebelum elemen yang nilainya = X
	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan Address Prec, dengan Next(Prec) = P dan Info(P) = X
	Jika tidak ada, mengirimkan Nil
	Jika P adalah elemen pertama, maka mengirimkan Nil
	Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah
	Search akan dilakukan operasi lain
*/

//PENAMBAHAN ELEMEN
void InsVFirst (List *L, Infotype X);
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen pertama L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
	nilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/

void InsVLast (List *L, Infotype X);
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen terakhir L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
	elemen terakhir yang baru bernilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/

//PENGHAPUSAN ELEMEN
void DelVFirst (List *L, Infotype *X);
/*	I.S. List L tidak kosong
	F.S. Elemen pertama list dihapus : nilai info disimpan pada X
	dan alamat elemen pertama di-dealokasi
*/

void DelVLast (List *L, Infotype *X);
/*	I.S. list tidak kosong
	F.S. Elemen terakhir list dihapus : nilai info disimpan pada X
	dan alamat elemen terakhir di-dealokasi
*/

//PRIMITIF BERDASARKAN ALAMAT
//PENAMBAHAN ELEMEN BERDASARKAN ALAMAT
void InsertFirst (List *L, Address P);
/*	I.S. Sembarang, P sudah dialokasi
	F.S. Menambahkan elemen ber-Address P sebagai elemen pertama
*/

void InsertAfter (List *L, Address P, Address Prec);
/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
	P sudah dialokasi
	F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
*/

void InsertLast (List *L, Address P);
/*	I.S. Sembarang, P sudah dialokasi
	F.S. P ditambahkan sebagai elemen terakhir yang baru
*/

//PENGHAPUSAN SEBUAH ELEMEN
void DeleteFirst (List *L, Address *P);
/*	I.S. List tidak kosong
	F.S. P adalah alamat elemen pertama list sebelum penghapusan
	Elemen list berkurang satu (mungkin menjadi kosong)
	First element yang baru adalah suksesor elemen pertama yang lama
*/

void DeleteP (List *L, Infotype X);
/*	I.S. Sembarang
	F.S. Jika ada elemen list ber-Address P, dengan Info(P) = X
	Maka P dihapus dari list dan di-dealokasi
	Jika tidak ada elemen list dengan Info(P) = X, maka list tetap
	List mungkin menjadi kosong karena penghapusan
*/

void DeleteLast (List *L, Address *P);
/*	I.S. List tidak kosong
	F.S. P adalah alamat elemen terakhir list sebelum penghapusan
	Elemen list berkurang satu (mungkin menjadi kosong)
	Last element baru adalah predesesor elemen pertama yang lama, jika ada

	CATATAN
	P adalah parameter Input/Output
*/

void DeleteAfter (List *L, Address *Pdel, Address Prec);
/*	I.S. List tidak kosong. Prec adalah anggota list L.
	F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus
*/

//PROSES SEMUA ELEMEN LIST
void PrintInfo (List L);
/*	I.S. List mungkin kosong
	F.S. Jika list tidak kosong,
	Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
	Jika list kosong, hanya menuliskan "[]"
*/

int NbElmt (List L);
/*	Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

// Prekondisi untuk Max/Min/rata-rata : List tidak kosong 
Infotype Max (List L);
/*	Mengirimkan nilai Info(P) yang maksimum */

Address AdrMax (List L);
/*	Mengirimkan address P, dengan Info(P) yang bernilai maksimum */

Infotype Min (List L);
/*	Mengirimkan nilai Info(P) yang minimum */

Address AdrMin (List L);
/*	Mengirimkan address P, dengan Info(P) yang bernilai minimum */

//PROSES TERHADAP LIST
void DeleteAll (List *L);
/*	Delete semua elemen list dan alamat elemen di-dealokasi
	I.S. : L terdefinisi, boleh kosong
	F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi
*/

void InversList (List *L);
/*	I.S. L terdefinisi, boleh kosong
	F.S. Elemen list L dibalik :
	Elemen terakhir menjadi elemen pertama, dan seterusnya.
	Membalik elemen list, tanpa melakukan alokasi/dealokasi.
*/

List FInversList (List L);
/*	Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
	Alokasi mungkin gagal. Jika alokasi gagal, hasilnya list kosong dan semua elemen
	yang terlanjur di-alokasi, harus didealokasi.
*/

void CopyList (List L1, List *L2);
/*	I.S. L1 terdefinisi, L2 sembarang. F.S. L2 = L1
	L1 dan L2 "menunjuk" kepada list yang sama.
	Tidak ada alokasi/dealokasi elemen baru.
*/

List FCopyList (List L);
/*	Mengirimkan list yang merupakan salinan L dengan melakukan alokasi elemen baru.
	Jika ada alokasi gagal, hasilnya list kosong dan semua elemen yang terlanjur dialokasi,
	harus didealokasi.
*/

void CpAlokList (List Lin, List *Lout);
/*	I.S. Lout sembarang, Lin terdefinisi.
	F.S. Jika semua alokasi berhasil, maka Lout berisi hasil copy Lin
	Jika ada alokasi yang gagal, maka Lout = Nil dan semua elemen yang terlanjur
	dialokasi, didealokasi
*/

void Concat (List L1, List L2, List *L3);
/*	I.S. L1 dan L2 terdefinisi, boleh kosong.
	F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 dan L2
	Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi L1 dan L2.
	Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi harus didealokasi
	dan L3 = Nil.
	Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru".
	Elemen L3 adalah hasil alokasi elemen yang "baru".
	Jika ada alokasi yang gagal, maka L3 harus bernilai Nil dan semua elemen yang
	pernah dialokasi harus didealokasi.
*/

void PecahList (List *L1, List *L2, List L);
/*	I.S. L mungkin kosong
	F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2
	L tidak berubah : untuk membentuk L1 dan L2 harus alokasi.
	L1 berisi separuh elemen L dan L2 berisi sisa elemen L.
	Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2.
	Jila alokasi gagal, semua elemen yang sudah dialokasikan harus di-dealokasi (bisa L1, L2 atau keduanya)
*/

#endif
