/* 	Topik	  : ADT Garis
* 	Tanggal	  : 1 September 2015
*   Deskripsi : Header adt Garis
*/

#ifndef Garis_h
#define Garis_h
#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <math.h>

/* 	type garis */
typedef struct{
	POINT PAw; // point awal
	POINT PAkh; // point akhir
} GARIS;

/* 	Gunakan Epsilon = 0.00001 untuk mengecek presisi floating point 
	Refer pada soal praktikum untuk Initial State dan Final State
*/

/* 	selektor */
#define GetPAw(l) (l).PAw
#define GetPAkh(l) (l).PAkh

/* 	setter */
#define SetPAw(l, newPaw) (l).PAw = newPaw
#define SetPAkh(l, newPakh) (l).PAkh = newPakh

/* 	Konstruktor untuk membentuk GARIS */
void MakeGARIS(POINT p1, POINT p2, GARIS *l);
/* 	I.S. P1 dan P2 terdefinisi
	F.S. L terdefinisi dengan L.PAw= P1 dan L.Pakh=P2
	Cara membaca: satu point satu baris, dengan atribut point dipisahkan oleh spasi gunakan scanf("%f %f"...); 
*/

// 	Interaksi dengan I/O device, baca/ tulis 
void BacaGARIS(GARIS *l);
/* 	Membaca dua buah nilai p1 dan p2 sehingga dapat membentuk GARIS yang valid. 
	GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. 
	Bacalah 1 point per baris input, atribut point dipisahkan oleh spasi, gunakan scanf("%f %f"...);
*/

void TulisGARIS(GARIS l);
/* 	Menuliskan garis ke layar dengan format "((x1,y1), (x2,y2))" diakhiri newline 
	x1 dan y1 adalah atribut PAw, sementara x2 y2 adalah atribut PAkh
	keluarkan dengan presisi 2 angka dibelakang titik
*/

// 	Kelompok operasi garis
float PanjangGARIS(GARIS l);
/* 	Menghitung panjang garis l */

float Gradien(GARIS l);
/* 	Menghitung gradien dari garis l.
	Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1) / (x2-x1) */

void GeserGARIS(GARIS *l, float deltaX, float deltaY);
/*	I.S. L terdefinisi
	F.S. L digeser sebesar deltaX dan ordinatnya sebesar deltaY 
	Menggeser garis l pada absis sebesar deltaX dan ordinatnya sebesar deltaY 
*/

// 	Kelompok predikat
boolean IsTegakLurus(GARIS l1, GARIS l2);
/* 	Menghasilkan true jika l1 tegak lurus terhadap l2 */

boolean IsSejajar(GARIS l1, GARIS l2);
/* 	Menghasilkan true jika l1 sejajar terhadap l2 */

#endif
