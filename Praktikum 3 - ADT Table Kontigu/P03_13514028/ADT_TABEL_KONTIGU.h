/*  FILE MILIK ASISTEN
	VERSI REPRESENTASI IMPLISIT - STATIK
	Bila terdapat perbedaan versi ini dengan definisi Modul Pra-Praktikum, gunakan definisi pada header ini,
	karena header sudah disesuaikan untuk autograding

	Berisi definisi dan semua primitif pemrosesan tabel integer
	Penempatan elemen selalu rapat kiri
	Elemen ke-0 merupakan sentinel
	Versi Implisit Statik
*/

/*Nim/ Nama = 13514028/ Dharma Kurnia Septialoka*/

#ifndef ADT_TABEL_KONTIGU_H
#define ADT_TABEL_KONTIGU_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define IdxMax 100
#define IdxMin 1
#define RangeMin -100 //nilai terkecil yang mungkin pada tabel
#define RangeMax 100 //nilai terbesar yang mungkin pada tabel
#define IdxUndef -999
#define ValUndef -9999

typedef int IdxType;
typedef int ElType;

typedef struct {
	ElType TI[IdxMax+1];
} TabInt;

typedef struct {
	int maks;
	int min;
} MaksimumMinimum;

/*
{ Jika T adalah TabInt, cara deklarasi dan akses: }
{ Deklarasi T : TabInt }
{ Maka cara akses :
  T.TI untuk mengakses seluruh nilai elemen tabel
  T.TI[i] untuk mengakses elemen ke-i }
{ Definisi :
  Tabel kosong: semua elemen tabel berisi ValUndef
  Definisi elemen pertama : T.TI[i] dengan i=1 }
*/

//KONSTRUKTOR
void MakeEmpty(TabInt *T);
/* 	I.S. sembarang
	F.S. Terbentuk tabel T kosong dengan semua elemen bernilai ValUndef

	Ingat! T.TI[0] tidak dihitung sebagai elemen pertama, artinya untuk T dengan kapasitas maksimum sebesar N,
	memiliki ruang elemen sebanyak N+1 (karena T.TI[0] bukan elemen pertama, T.TI[0] hanya sentinel)
*/

//SELEKTOR
int	NbElmt(TabInt T);
/*	Mengirimkan banyaknya elemen efektif tabel
	Mengirimkan nol jika tabel kosong
*/

int MaxNbEl(TabInt T);
/*	Mengirimkan maksimum elemen yang dapat ditampung oleh tabel (IdxMax - IdxMin+1) */

IdxType	GetFirstIdx(TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks elemen pertama
*/

IdxType GetLastIdx(TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks elemen terakhir
*/

ElType GetElmt(TabInt T, IdxType i);
/*	Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) }
	Mengirimkan elemen tabel yang ke-i
*/

//SELEKTOR
void SetTab(TabInt Tin, TabInt *Tout);
/*	I.S. Tin terdefinisi, sembarang
	F.S. Tout berisi salinan Tin
*/

void SetEl(TabInt *T, IdxType i, ElType v);
/*	I.S. T terdefinisi, sembarang
	F.S. Elemen T yang ke-i bernilai v
	Merubah nilai elemen tabel yang ke-i sehingga bernilai v
*/

//INDEKS YANG VALID
boolean	IsIdxValid(TabInt T, IdxType i);
/*	Prekondisi : i sembarang }
	Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel }
	yaitu antara indeks yang terdefinisi utk container (IdxMin, IdxMax)}
*/

boolean IsIdxEff(TabInt T, IdxType i);
/*	Prekondisi : i sembarang
	Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel
	yaitu antara FirstIdx(T)..LastIdx(T)
*/

//KOSONG/PENUH
boolean IsEmpty(TabInt T);
/*	Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

boolean IsFull(TabInt T);
/*	Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

//BACA DAN TULIS DENGAN INPUT/OUTPUT
void BacaIsi(TabInt *T);
/*	I.S. sembarang
	F.S. tabel T terdefinisi
	Proses : membaca banyaknya elemen T dan mengisi nilainya, tabel dialokasikan ulang sebelum disiikan nilai (baca dr elemen ke-1)

	contoh proses membaca
	5 //jumlah elemen
	0 //elemen ke-1
	1 //elemen ke-2, dst
	2
	3
	4
*/

void TulisIsi(TabInt T);
/*	Proses : Menuliskan isi tabel dengan traversal
	I.S. T boleh kosong
	F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah
	Jika T kosong : Hanya menulis "Tabel kosong" diakhiri newline. Indeks dimulai dari indeks ke-1
	Format penulisan "<indeks> - <isi>" ingat diberikan newline untuk setiap row. Hanya outputkan elemen efektif

	contoh:
	[1] - 100
	[2] - 99
	dst
*/

void TulisIsiTab(TabInt T);
/*	Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung
	siku; antara dua elemen dipisahkan dengan separator "koma"
	I.S. T boleh kosong
	F.S. Jika T tidak kosong: [e1, e2, ... ,en]
	Contoh : jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30]
	Jika tabel kosong : menulis []
	ingat berikan newline pada output
	Hanya outputkan elemen efektif.
*/


//OPERATOR ARITMATIKA
TabInt PlusTab(TabInt T1, TabInt T2);
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong dengan definisi tiap elemen dengan indeks yang sama ditambahkan
	Mengirimkan T1 + T2
*/

TabInt MinusTab(TabInt T1,TabInt T2);
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong dengan definisi tiap elemen dengan indeks yang sama ditambahkan
	Mengirimkan T1 - T2
*/

TabInt KaliTab(TabInt T1,TabInt T2);
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
	Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan
*/

TabInt KaliKons(TabInt Tin, ElType c);
/*	Prekondisi : Tin tidak kosong
	Mengirimkan tabel dengan setiap elemen Tin dikalikan c
*/

//OEPRATOR RELASIONAL
boolean IsEQ(TabInt T1, TabInt T2);
/*	Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua
	elemennya sama
*/

boolean IsLess(TabInt T1, TabInt T2);
/*	Mengirimkan true jika T1 < T2, precond : T1 dan T2 memiliki ukuran yang sama
	yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3]. T1 < T2 bila semua elemen T1 lebih kecil dari elemen T2
*/

//SEARCHING
IdxType	Search1(TabInt T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X
	Jika tidak ada, mengirimkan IdxUndef
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong
	Memakai skema search TANPA boolean
*/

IdxType	Search2(TabInt T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X
	Jika tidak ada, mengirimkan IdxUndef
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong
	Memakai skema search DENGAN boolean Found
*/
boolean SearchB(TabInt T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan true, jika tidak ada menghasilkan false
	Menghasilkan false jika tabel T kosong
	Memakai Skema search DENGAN boolean
*/

boolean	SearchSentinel(TabInt T, ElType X);
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan true jika X ada dan false bila X tidak ada
	dengan metoda sequential search dengan sentinel
	Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C yang
	tidak dipakai dalam definisi tabel
	Menghasilkan false jika tabel T kosong
*/

//NILAI EKSTREM
ElType ValMax(TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan nilai maksimum tabel
*/

ElType ValMin(TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan nilai minimum tabel
*/

IdxType IdxMaxTab(TabInt T);
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel, keluarkanlah index pertama kali nilai maximum tsb muncul
*/

IdxType IdxMinTab(TabInt T);
/*	Prekondisi : Tabel tidak kosong
	Mengirimkan indeks i dengan elemen ke-i adalah nilai minimum pada tabel, keluarkanlah index pertama kali nilai maximum tsb muncul
*/

//OPERASI LAIN
void CopyTab(TabInt Tin, TabInt *Tout);
/*	I.S. sembarang
	F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik)
	Proses : Menyalin isi Tin ke Tout
*/

TabInt InverseTab(TabInt T);
/*	Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu :
	elemen pertama menjadi terakhir,
	elemen kedua menjadi elemen sebelum terakhir, dst..
	Tabel kosong menghasilkan tabel kosong
*/

boolean IsSimetris(TabInt T);
/*	Menghasilkan true jika tabel simetrik
	Tabel disebut simetrik jika:
	elemen pertama = elemen terakhir,
	elemen kedua = elemen sebelum terakhir, dan seterusnya
	Tabel kosong adalah tabel simetris
*/

//SORTING
void MaxSortDesc(TabInt *T);
/*	I.S. T boleh kosong
	F.S. T elemennya terurut menurun dengan Maximum Sort
	Proses : mengurutkan T sehingga elemennya menurun/mengecil
	tanpa menggunakan tabel kerja
*/

void InsSortAsc(TabInt *T);
/*	I.S. T boleh kosong
	F.S. T elemennya terurut menaik dengan Insertion Sort
	Proses : mengurutkan T sehingga elemennya menaik/membesar
	tanpa menggunakan tabel kerja
*/

//MENAMBAH ELEMEN
void AddAsLastEl(TabInt *T, ElType X);
/*	Menambahkan X sebagai elemen terakhir tabel
	I.S. Tabel boleh kosong, tetapi tidak penuh
	F.S. X adalah elemen terakhir T yang baru
	Proses : Menambahkan sebagai elemen ke-i yang baru
*/

void AddEli(TabInt *T, ElType X, IdxType i);
/*	Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas terhadap
	elemen yang sudah ada
	I.S. Tabel tidak kosong dan tidak penuh
	i adalah indeks yang valid.
	F.S. X adalah elemen ke-i T yang baru
	Proses : Geser elemen ke-i+1 s.d. terakhir
	Isi elemen ke-i dengan X
*/

//MENGHAPUS ELEMEN
void DelLastEl(TabInt *T, ElType *X);
/*	Proses : Menghapus elemen terakhir tabel
	I.S. Tabel tidak kosong
	F.S. X adalah nilai elemen terakhir T sebelum penghapusan,
	Banyaknya elemen tabel berkurang satu
	Tabel T mungkin menjadi kosong
*/

void DelEli(TabInt *T, IdxType i, ElType *X);
/*	Proses : Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas
	I.S. Tabel tidak kosong, i adalah indeks efektif yang valid
	F.S. Elemen T berkurang satu
	Banyaknya elemen tabel berkurang satu
	Tabel T mungkin menjadi kosong
	Proses : Geser elemen ke-i+1 s.d. elemen terakhir
	Kurangi elemen efektif tabel
*/

//TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI
void AddElUnik(TabInt *T, ElType X);
/*	Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik
	I.S. Tabel boleh kosong, tetapi tidak penuh
	dan semua elemennya bernilai unik, tidak terurut
	F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, jika belum ada
	elemen yang bernilai X. Jika sudah ada elemen tabel yang bernilai X maka I.S. =
	F.S. dan dituliskan pesan "nilai sudah ada" dengan newline
	Proses : Cek keunikan dengan sequential search dengan sentinel
	Kemudian tambahkan elemen jika belum ada
*/

//TABEL DENGAN ELEMEN TERURUT MEMBESAR
IdxType SearchUrut(TabInt T, ElType X);
/*	Prekondisi: Tabel boleh kosong. Jika tidak kosong, elemen terurut membesar.
	mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan
	mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong
*/

ElType Max(TabInt T);
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai maksimum pada tabel
*/

ElType Min(TabInt T);
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai minimum pada tabel
*/

MaksimumMinimum MaxMin(TabInt T);
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai maksimum dan minimum pada tabel
*/

void Add1Urut(TabInt *T, ElType X);
/*	Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel
	Nilai dalam tabel tidak harus unik.
	I.S. Tabel boleh kosong, boleh penuh.
	Jika tabel isi, elemennya terurut membesar.
	F.S. Jika tabel belum penuh, menambahkan X.
	Jika tabel penuh, maka tabel tetap.
	Proses : Search tempat yang tepat sambil geser
	Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan
*/

void Del1Urut(TabInt *T, ElType X);
/*	Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan
	I.S. Tabel tidak kosong
	F.S. Jika ada elemen tabel bernilai X ,
	maka banyaknya elemen tabel berkurang satu.
	Jika tidak ada yang bernilai X, tabel tetap.
	Setelah penghapusan, elemen tabel tetap kontigu!
	Proses : Search indeks ke-i dengan elemen ke-i=X.
	Delete jika ada.
*/

//Tambahan
boolean SearchUrutB (TabInt T, ElType X);
/* { Prekondisi: Tabel boleh kosong. Jika tidak kosong, elemen terurut
    membesar. }
    { Mengirimkan true jika X ada di dalam T dan false jika X tidak ditemukan
    di T. }
*/

int SumTab (TabInt T);
/*  { Prekondisi : Tabel T tidak kosong }
    { Mengirim hasil penjumlahan semua elemen dalam T }
*/

void UpdateElmt (TabInt *T, IdxType i, ElType X);
/* { I.S. : T terdefinisi, tidak kosong.
    i merupakan indeks valid dalam T.
    X terdefinisi. }
    { F.S. : Nilai elemen T pada indeks ke-i berubah menjadi X.
    T tetap terurut membesar, sehingga ada kemungkinan dilakukan
    proses pengurutan kembali. }
    { Proses : meng-assign nilai X pada TabInt dengan indeks i. Melakukan insertion sort dengan
                memanggil InsSortAsc(T). }
*/

void DelAllX (TabInt *T, ElType X);
/*  procedure DelAllX (input/output T : TabInt, input X : ElType)
    { I.S. : T terdefinisi, boleh kosong. X terdefinisi. }
    { F.S. : Semua elemen T yang bernilai X dihapus dari tabel penampung, jika
    X ada di T. Jika X tidak ada, T tetap. }
    { Proses : mengecek dengan while apakah X ada di T dengan function SearchUrutB, jika true, panggil fungsi Del1Urut. }
*/


#endif
