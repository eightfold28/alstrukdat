

#include "boolean.h"
#include <math.h>
#include <stdio.h>
#include "matriks.h"


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
void MakeMATRIKS(int NB, int NK, MATRIKS *M) {
/*	Membentuk sebuah MATRIKS kosong berukuran NB x NK di "ujung kiri atas" container
	I.S. NB dan NK adalah valid untuk container matriks yang dibuat
	F.S. Matriks M sesuai dengan definisi di atas terbentuk
	Matriks kosong berisi nilai ValUndef untuk setiap elemennya

	Untuk standardisasi, pada kasus ini set NBrsEff dan NKolEff sesuai NB dan NK
*/	/*Kamus Lokal*/
	indeks i,j;
	/*Algoritma*/
	(*M).NBrsEff = NB;
	(*M).NKolEff = NK;
	for(i = 0; i<= NB; i++) {
		for (j = 0; j<= NK; j++) {
			(*M).Mem[i][j] = ValUndef;
		}
	}
	
}
/* SELEKTOR "DUNIA MATRIKS" */
indeks GetIdxBrsMin() {
/* 	Mengirimkan indeks baris minimum matriks yang dapat dibuat oleh ADT */
	return 1;
}
indeks GetIdxKolMin() {
/*	Mengirimkan indeks kolom minumum matriks yang dapat dibuat oleh ADT */
	return 1;
}
indeks GetIdxBrsMax() {
/*	Mengirimkan indeks baris maksimum matriks yang dapat dibuat oleh ADT */
	return 100;
}
indeks GetIdxKolMax() {
/*	Mengirimkan indeks kolom maksimum matriks yang dapat dibuat oleh ADT */
	return 100;
}
boolean IsIdxValid(int i, int j) {
/*	Mengirimkan true jika i, j adalah indeks yang valid, indeks yang valid berada pada range indeks container 
	yang dapat dibuat oleh ADT
*/
	if ((i >= GetIdxBrsMin()) && (i <= GetIdxBrsMax()) && (j >= GetIdxKolMin()) && (j <= GetIdxKolMax())) {
		return true;
	}
	else {
		return false;
	}
}
/* UNTUK SEBUAH MATRIKS M YANG TERDEFINISI */
indeks FirstIdxBrs(MATRIKS M) {
/*	Mengembalikan indeks baris terkecil yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */
	if ((M).Mem[1][1] != ValUndef) {
		return 1;
	}
}
indeks FirstIdxKol(MATRIKS M) {
/*	Mengembalikan indeks kolom terkecil yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */
	if ((M).Mem[1][1] != ValUndef) {
		return 1;
	}
}
indeks LastIdxBrs(MATRIKS M) {
/*	Mengembalikan indeks baris terbesar yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */
	/*Kamus Lokal*/

	return FirstIdxBrs(M) + GetNBrsEff(M) -1;
}
indeks LastIdxKol(MATRIKS M) {
/*	Mengembalikan indeks kolom terbesar yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */

	return FirstIdxKol(M) + GetNKolEff(M) -1;
}
int GetNBrsEff(MATRIKS M) {
/*	Mengirimkan banyaknya baris efektif M */
	return M.NBrsEff;
}
int GetNKolEff(MATRIKS M) {
/*	mengirimkan banyaknya kolom efektif M */
	return M.NKolEff;
}
boolean IsIdxEff(MATRIKS M, indeks i, indeks j) {
/*	Mengirimkan true jika i, j adalah indeks efektif bagi M, yaitu berada dalam range FirstIdx...() sampai LastIdx...() */
	if ((i <= GetNBrsEff(M)) && (j <= GetNKolEff(M)) && (i >= 1) && (j >= 1)) {
		return true;
	}
	else {
		return false;
	}
}
el_type GetElmt(MATRIKS M, indeks i, indeks j) {
/*	Mengirimkan elemen M dengan nomor baris i dan nomor kolom j */
	return M.Mem[i][j];
}
el_type GetElmtDiagonal(MATRIKS M, indeks i) {
/*	Mengimkan elemen M(i,i) */
	return M.Mem[i][i];
}
/* OPERASI MENGUBAH NILAI ELEMEN MATRKS : SET/ASSIGN */
void SetBrsEff(MATRIKS *M, int NB) {
/*	I.S. M sudah terdefinisi
	F.S. Nilai M.BrsEff diisi dengan NB
*/	(*M).NBrsEff = NB;
}
void SetKolEff(MATRIKS *M, int NK) {
/*	I.S. M sudah terdefinisi
	F.S. Nilai M.NKolEff diisi dengan NK
*/	(*M).NKolEff = NK;
}
void SetEl(MATRIKS *M, int i, int j, el_type X) {
/*	I.S. M sudah terdefinisi
	F.S. M(i,j) bernilai X
	Proses: Mengisi M(i,j) dengan X
*/
	(*M).Mem[i][j] = X;
}
/* ASSIGNMET MATRIKS */
void CopyMATRIKS(MATRIKS Min, MATRIKS *MHsl) {
/*	Melakukan assignment Mhsl <- Min */
	/*Kamus Lokal*/
	indeks i,j;
	/*Algoritma*/
	MakeMATRIKS(GetNBrsEff(Min),GetNKolEff(Min),MHsl);
	for (i = GetIdxBrsMin(); i <= (GetNBrsEff(Min)); i++) {
		for (j = GetIdxKolMin(); j <= (GetNKolEff(Min)); j++) {
			SetEl(MHsl,i,j,GetElmt(Min,i,j));
		}
	}
}
/* KELOMPOK BACA TULIS */
void BacaMATRIKS(MATRIKS *M, int NB, int NK) {
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
*/ /*Kamus Lokal*/
	indeks i,j,X;
	/*Algoritma*/
	MakeMATRIKS(NB,NK,M);
	for (i = GetIdxBrsMin(); i <= (GetNBrsEff(*M)); i++) {
		for (j = GetIdxKolMin(); j <= (GetNKolEff(*M)); j++) {
			scanf("%d",&X);
			SetEl(M,i,j,X);
		}
	}
}
void TulisMATRIKS(MATRIKS M) {
/*	I.S. M terdefinisi
	F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layaR
	Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris

	contoh (sesuai dengan contoh pada baca matriks):
	[1, 2, 3] {tidak terdapat spasi pada akhir}
	[4, 5, 6] {"[" dan "]" juga dioutputkan}
	[7, 8, 9] {jangan lupa mengakhiri dengan sebuah newline}
*/	/*Kamus Lokal*/
	indeks i,j;
	/*Algoritma*/
	for (i = GetIdxBrsMin(); i <= GetNBrsEff(M); i++) {
		printf("[");
		for (j = GetIdxKolMin(); j <= (GetNKolEff(M) - 1); j++) {
			printf("%d, ",GetElmt(M,i,j));
		}
		printf("%d]\n",GetElmt(M,i,j));
	}
}

/* 	KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE
	Operasi aritmatika yang dilakukan sesuai operasi aritmatika matriks pada matematika
*/


/*TAMBAHAN*/
float RataNilai(MATRIKS M, indeks n) {
/*{ Prekondisi: Matriks tidak kosong. }
{ Mengirimkan rata-rata nilai ujian ke-N } */

	
	/*Kamus Lokal*/
	int sum;
	indeks i;
	/*Algoritma*/
	sum = 0;
	for (i = 1; i <= GetNBrsEff(M); i++) {
		sum += GetElmt(M,i,n);
	}
	
	return ((float)sum)/(i-1);
}


indeks RataTestTertinggi(MATRIKS M) {
/* { Prekondisi : Matriks tidak kosong }

{ Mengirim nomor test yang memiliki rata-rata kelas tertinggi }*/
	

	/*Kamus*/
	indeks Nmax,j;
	/*Algoritma*/
	Nmax = FirstIdxKol(M);
	for (j = FirstIdxKol(M) + 1; j<= GetNKolEff(M); j++) {
		if (RataNilai(M,j) > RataNilai(M,Nmax)) {
			Nmax = j;
		}
	}
	return Nmax;
}

void TulisStatistikTest( MATRIKS M) {
/*{ I.S. : M terdefinisi, tidak kosong. }

{ F.S. : Untuk setip test yang pernah dilakukan ditayangkan nilai

         terkecil dan terbesar yang diperoleh mahasiswa, berikut

         nilai rata-rata dari seluruh mahasiswa.

         Setiap baris menampilkan data statistik sebuah test.

 

           Format Output:

           Text-<Nomor Test> Min=Nilai Max=Nilai Avg=Nilai

           *) outputkan nilai rata-rata dengan 2 angka dibelakang koma

           *) Nomor Test dimulai dari indeks ke-1

 

           Contoh Format Output:

           T1 Min=1 Max=100 Avg=60.78

           T2 Min=20 Max=90 Avg=30.46}

{ Proses : ... -> tuliskan bagaimana Anda menyelesaikannya. */	

	/*Kamus Lokal*/
	indeks j;
	/*Algoritma*/
	for (j = 1; j <= GetNKolEff(M); j++) {
		printf("T%d Min=%d Max=%d Avg=%.2f\n",j,GetElmt(M,NilaiMin(M,j),j),GetElmt(M,NilaiMax(M,j),j),RataNilai(M,j));
	}
	
}

void TulisMatriks1(MATRIKS M) {
/*{ I.S. : M terdefinisi, tidak kosong }

{ F.S. : Semua elemen matriks tertulis di layar.

         Setiap baris akan menampilkan data satu mahasiswa, berupa:

         Nomor urut, nilai untuk setiap test, dan rata-rata nilai dari

         seluruh test.

             

              Format output

              Mhs-<nomor mahasiswa> Ti=Nilai Avg=Nilai

              Dengan Nomor Mahasiswa dimulai dari 1 untuk record terawal

              Ti merupakan test ke-i (gantilah i dengan 1, 2, 3 dst). Untuk

              setiap nilai Ti dipisahkan oleh spasi (lihatlah contoh)

 

              Contoh Format Output:

              Mhs1 T1=20 T2=30 T3=40 Avg=30.00}

{ Proses : ... -> tuliskan bagaimana Anda menyelesaikannya. }*/
	
	/*Kamus Lokal*/
	indeks i,j;
	/*Algoritma*/
	for ( i = FirstIdxBrs(M); i<=GetNBrsEff(M); i++) {
		printf("Mhs%d ",i);
		for( j = FirstIdxKol(M); j <= GetNKolEff(M); j++) {
			printf("T%d=%d ",j,GetElmt(M,i,j));
		}
		printf("Avg=%.2f\n",RataMahasiswa(M,i));
	}
	
}

indeks NilaiMax (MATRIKS M, indeks j) {
	/*Kamus Lokal*/
	indeks i, Imax;
	/*Algoritma*/
	Imax = FirstIdxBrs(M);
	for (i = FirstIdxBrs(M) + 1; i <= GetNKolEff(M); i++)  {
		if (GetElmt(M,i,j) > GetElmt(M,Imax,j)) {
			Imax = i;
		}
	}
	return Imax;
}

indeks NilaiMin (MATRIKS M, indeks j) {
	/*Kamus Lokal*/
	indeks i, Imin;
	/*Algoritma*/
	Imin = FirstIdxBrs(M);
	for (i = FirstIdxBrs(M) + 1; i <= GetNBrsEff(M); i++)  {
		if (GetElmt(M,i,j) < GetElmt(M,Imin,j)) {
			Imin = i;
		}
	}
	return Imin;
}


float RataMahasiswa(MATRIKS M,indeks i) {
	/*Kamus Lokal*/
	indeks j;
	int sum;
	/*Algoritma*/
	sum = 0;
	for(j=FirstIdxKol(M); j <= GetNKolEff(M); j++) {
		sum+= GetElmt(M,i,j);
	}
	return ((float)sum/(j-1));
	
}
