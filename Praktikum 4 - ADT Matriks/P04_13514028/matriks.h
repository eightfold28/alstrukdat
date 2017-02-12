/*  [ATTENTION]
	Harap cantumkan identitas setiap pada file yang Anda submit!

	NIM/Nama  : 13514028/ Dharma Kurnia Septialoka
   	Nama file : matriks.h
   	Topik     : ADT Matriks
   	Tanggal   : 17 September 2015
   	Deskripsi : header matriks.h
*/

#ifndef matriks_h
#define matriks_h
#include "boolean.h"
#include <math.h>
#include <stdio.h>

/* DEFINISI TYPE MATRIKS DENGAN INDEKS INTEGER */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100
#define RangeMin -100 //nilai minimum elemen matriks
#define RangeMax 100 //nilai maksimum elemen matriks
#define ValUndef -999
#define IdxUndef -999

typedef int indeks;
typedef int el_type;

typedef struct {
	el_type Mem[BrsMax+1][KolMax+1];
	int	NBrsEff; //banyaknya/ukuran baris yang terdefinisi
	int NKolEff; //banyaknya/ukuran kolom yang terdefinisi
} MATRIKS;

/* 	CATATAN ASISTEN - PERINGATAN PENTING *
	Elemen matriks pertama menempati Mem[BrsMin, KolMin], sehingga Mem[0,Y] dan Mem[X,0] untuk sembarang nilai X dan Y tidak digunakan
	Ingat, matriks yang diisi selalu di "ujung kiri atas" container, seperti (untuk NBrsEff dan NKolEff bernilai masing-masing 3 ):
	
	-999 -999 -999 -999
	-999  1    2     3 
	-999  4    5     6 
	-999  7    8     9 

	NBrsEff >= 1 dan NKolEff >= 1 memenuhi semua kondisi matriks
	Mulai dari Mem[BrsMin, KolMin] sampai dengan Mem[NBrsEff, NKolEff] selalu memiliki nilai yang valid (elemen efektif) KECUALI KASUS prosedur MakeMATRIKS, karena diminta membuat "matriks kosong"
	MATRIKS yang digunakan pada uji coba kasus selalu merupakan matriks terisi (lihat definisi "matriks terisi")

	Definisi Matriks Kosong:
	Matriks yang seluruh elemennya berisi ValUndef dimulai indeks [BrsMin, KolMin] sampai [NBrsEff, NKolEff]
	
	Definisi Matriks Terisi:
	Matriks yang memuat elemen terdefinisi (berada pada RangeMin..RangeMax) untuk semua indeks [1,1] sampai [NBrsEff, NKolEff]

	Header ini telah dimodifikasi untuk disesuaikan dengan autograding, bila terdapat perbedaan antara header dengan modul PraPraktikum, aculah header ini
	DILARANG KERAS MERUBAH HEADER INI! Kecuali mengisi NAMA dan NIM
*/

/* KONSTRUKTOR */
void MakeMATRIKS(int NB, int NK, MATRIKS *M);
/*	Membentuk sebuah MATRIKS kosong berukuran NB x NK di "ujung kiri atas" container
	I.S. NB dan NK adalah valid untuk container matriks yang dibuat
	F.S. Matriks M sesuai dengan definisi di atas terbentuk
	Matriks kosong berisi nilai ValUndef untuk setiap elemennya

	Untuk standardisasi, pada kasus ini set NBrsEff dan NKolEff sesuai NB dan NK
*/

/* SELEKTOR "DUNIA MATRIKS" */
indeks GetIdxBrsMin();
/* 	Mengirimkan indeks baris minimum matriks yang dapat dibuat oleh ADT */

indeks GetIdxKolMin();
/*	Mengirimkan indeks kolom minumum matriks yang dapat dibuat oleh ADT */

indeks GetIdxBrsMax();
/*	Mengirimkan indeks baris maksimum matriks yang dapat dibuat oleh ADT */

indeks GetIdxKolMax();
/*	Mengirimkan indeks kolom maksimum matriks yang dapat dibuat oleh ADT */

boolean IsIdxValid(indeks i, indeks j);
/*	Mengirimkan true jika i, j adalah indeks yang valid, indeks yang valid berada pada range indeks container 
	yang dapat dibuat oleh ADT
*/

/* UNTUK SEBUAH MATRIKS M YANG TERDEFINISI */
indeks FirstIdxBrs(MATRIKS M);
/*	Mengembalikan indeks baris terkecil yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */

indeks FirstIdxKol(MATRIKS M);
/*	Mengembalikan indeks kolom terkecil yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */

indeks LastIdxBrs(MATRIKS M);
/*	Mengembalikan indeks baris terbesar yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */

indeks LastIdxKol(MATRIKS M);
/*	Mengembalikan indeks kolom terbesar yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */

int GetNBrsEff(MATRIKS M);
/*	Mengirimkan banyaknya baris efektif M */

int GetNKolEff(MATRIKS M);
/*	mengirimkan banyaknya kolom efektif M */

boolean IsIdxEff(MATRIKS M, indeks i, indeks j);
/*	Mengirimkan true jika i, j adalah indeks efektif bagi M, yaitu berada dalam range FirstIdx...() sampai LastIdx...() */

el_type GetElmt(MATRIKS M, indeks i, indeks j);
/*	Mengirimkan elemen M dengan nomor baris i dan nomor kolom j */

el_type GetElmtDiagonal(MATRIKS M, indeks i);
/*	Mengimkan elemen M(i,i) */

/* OPERASI MENGUBAH NILAI ELEMEN MATRKS : SET/ASSIGN */
void SetBrsEff(MATRIKS *M, int NB);
/*	I.S. M sudah terdefinisi
	F.S. Nilai M.BrsEff diisi dengan NB
*/

void SetKolEff(MATRIKS *M, int NK);
/*	I.S. M sudah terdefinisi
	F.S. Nilai M.NKolEff diisi dengan NK
*/

void SetEl(MATRIKS *M, indeks i, indeks j, el_type X);
/*	I.S. M sudah terdefinisi
	F.S. M(i,j) bernilai X
	Proses: Mengisi M(i,j) dengan X
*/

/* ASSIGNMET MATRIKS */
void CopyMATRIKS(MATRIKS Min, MATRIKS *MHsl);
/*	Melakukan assignment Mhsl <- Min */


/* KELOMPOK BACA TULIS */
void BacaMATRIKS(MATRIKS *M, int NB, int NK);
/*	I.S. IsIdxValid(NB,NK)
	F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK
	Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya
	dari pembacaan dengan traversal per baris

	cara membaca:
	mulai baris 1 berikutnya sampai NB terdapat bilangan sebanyak NK yang menyatakan elemen-elemen matriks
	
	contoh:
	1 2 3
	4 5 6
	7 8 9
*/

void TulisMATRIKS(MATRIKS M);
/*	I.S. M terdefinisi
	F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layaR
	Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris

	contoh (sesuai dengan contoh pada baca matriks):
	[1, 2, 3] {tidak terdapat spasi pada akhir}
	[4, 5, 6] {"[" dan "]" juga dioutputkan}
	[7, 8, 9] {jangan lupa mengakhiri dengan sebuah newline}
*/

/* 	KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE
	Operasi aritmatika yang dilakukan sesuai operasi aritmatika matriks pada matematika
*/

MATRIKS Tambah(MATRIKS M1, MATRIKS M2);
/*	Prekondisi : M1 berukuran sama dengan M2
	Mengirim hasil penjumlahan matriks: M1 + M2
*/

MATRIKS Kurang(MATRIKS M1, MATRIKS M2);
/*	Prekondisi : M1 berukuran sama dengan M2
	Mengirim hasil pengurangan matriks: M1 - M2
*/

MATRIKS Kali2Matriks(MATRIKS M1, MATRIKS M2);
/*	Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2
	Mengirim hasil perkalian matriks: M1 * M2
*/

MATRIKS KaliKons(MATRIKS M1, int X);
/*	Mengirim hasil perkalian setiap elemem M dengan X
*/

void KaliKonsA(MATRIKS *M, int K);
/*	Mengalikan setiap elemen M dengan K 
*/

/* KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS */
boolean EQ(MATRIKS M1, MATRIKS M2);
/* 	Mengirimkan true jika M1 = M2,
	yaitu NBElmt(M1) = NBElmt(M2), dimensi matriks sama
	dan
	untuk setiap i,j yang merupakan indeks baris dan kolom
	M1(i,j) = M2(i,j)
*/

boolean NEQ(MATRIKS M1, MATRIKS M2);
/*	Mengirimkan true jika not EQ(M1,M2) */

boolean EQSize(MATRIKS M1, MATRIKS M2);
/*	Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2
	yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2)
*/

boolean KurangDari(MATRIKS M1, MATRIKS M2);
/*	Mengirimkan true jika ukuran efektif M1 < ukuran efektif M2, dalam artian luas efektifnya */

/* OPERASI LAIN */
int NBElmt(MATRIKS M);
/*	Mengirimkan banyaknya elemen efektif M, matriks kosong memiliki elemen efektif sebanyak 0 (lihat definisi matriks kosong) */

//KELOMPOK TEST TERHADAP MATRIKS
boolean IsBujurSangkar(MATRIKS M);
/*	Mengirimkan true jika M adalah matriks dengan ukuran baris dan kolom sama, matriks kosong adalah bujur sangkar */

boolean IsSimetri(MATRIKS M);
/* 	Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) dan untuk
	setiap elemen M, M(i,j)=M(j,i)
*/

boolean IsSatuan(MATRIKS M);
/*	Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan setiap
	elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0

	Ingat! Bernilai 0
*/



//PRAKTIKUM
float RataNIlai (MATRIKS M, indeks N);
/* Prekon: Matriks tidak kosong
 * Mengirimkan rata-rata nilai ujian ke-N
*/

indeks RataTestTertinggi (MATRIKS M);
/* Prekon: Matriks tidak kosong
 * Mengirim no test yg memiliki rata-rata kelas tertinggi
*/

void TulisStatistikTest (MATRIKS M);
/*
 * {I.S. : M terdefinisi, tidak kosong.}
* {F.S. : Untuk setip test yang pernah dilakukan ditayangkan nilai terkecil dan terbesar yang diperoleh mahasiswa, 
* berikut nilai rata-rata dari seluruh mahasiswa.
Setiap baris menampilkan data statistik sebuah test.

Format Output:
Text-<Nomor Test> Min=Nilai Max=Nilai Avg=Nilai
*) outputkan nilai rata-rata dengan 2 angka dibelakang koma
*) Nomor Test dimulai dari indeks ke-1
Contoh Format Output:
T1 Min=1 Max=100 Avg=60.78
T2 Min=20 Max=90 Avg=30.46}
{Proses : ...-> tuliskan bagaimana Anda menyelesaikannya. }
*/

void TulisMatriks1 (MATRIKS M);
/*
{ I.S. : M terdefinisi, tidak kosong}
{ F.S. : Semua elemen matriks tertulis di layar. Setiap baris akan menampilkan data satu mahasiswa, berupa:
Nomor urut, nilai untuk setiap test, dan rata-rata nilai dari seluruh test.

Format output
Mhs-<nomor mahasiswa> Ti=Nilai Avg=Nilai
Dengan Nomor Mahasiswa dimulai dari 1 untuk record terawal
Ti merupakan test ke-i (gantilah i dengan 1, 2, 3 dst). Untuk
setiap nilai Ti dipisahkan oleh spasi (lihatlah contoh)
Contoh Format Output:
Mhs1 T1=20 T2=30 T3=40 Avg=30.00
{Proses : ...-> tuliskan bagaimana Anda menyelesaikannya. }
*/


 

#endif
