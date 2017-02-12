/*	Template Asisten
 * 	Topik	  : ADT Point
 * 	Tanggal	  : 1 September 2015
 *      Deskripsi : Header adt point
*       Untuk diketahui, kami menggunakan perbandingan bilangan floating point, dengan presisi epslon sebesar 0.00001
*	Perihangan: untuk fungsi yang memerlukan return bertipe boolean, gunakan return true/return false. Jangan menggunakan, misal "return GetAbsis(p)==0;"
*       Dilarang merubah header ini, karena akan menyebabkan compile error pada autograder
*       Semua fungsi yang terdapat pada header, harus terdapat pada file *.c (walaupun body kosong), bila tidak, akan menyebabkan compile error
*/

#ifndef Point_h
#define Point_h
#include "boolean.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>

/* type point */
typedef struct {
	float x; //absis
	float y; //ordinat
} POINT;

/* selektor */
#define GetAbsis(p) (p).x
#define	GetOrdinat(p) (p).y
#define SetAbsis(p, newx) (p).x=newx
#define SetOrdinat(p, newy) (p).y=newy

/* 	Tambahkan pada file *.c anda baris berikut ini
	const float pi = 3.14;
*/

POINT MakePoint(float x, float y);
/*	membentuk sebuah point dari komponen-komponennya */

//interaksi dengan I/O device baca/tulis
void BacaPoint(POINT *p);
/*	Makepoint(x,y,P) membentuk P dari x dan y yang dibaca */

void TulisPoint(POINT p);
/*	nilai p ditulis ke layar dengan format "(X,Y)" 
	harap menggunakan presisi 2 angka dibelakang koma

	Silahkan gunakan line berikut ini
	printf("(%.2f, %.2f)\n",GetAbsis(p),GetOrdinat(p));
*/

//kelompok operasi aritmatika terhadap type
POINT Tambah(POINT p1, POINT p2);
/*	menghasilkan point yang bernilai p1 + p2
	melakukan operasi penjumlahan vektor
*/

POINT Kurang(POINT p1, POINT p2);
/*	menghasilkan point bernilai p1-p2 
	buatlah spesifikasi pengurangan dua buah point 
*/

float DotProduct(POINT p1, POINT p2);
/*	operasi perkalian p1.p2 melakukan operasi dot */

//kelompok operasi relasional terhadap point
boolean	EQ(POINT p1, POINT p2);
/*	mengirimkan true jika p1=p2 absis dan ordinatnya sama */

boolean NEQ(POINT p1, POINT p2);
/*	mengirimkan true jika p1 tidak sama dengan p2 */

boolean KurangDari(POINT p1, POINT p2);
/*	mengirimkan true jika p1<p2. definisi lebih kecil : lebih kiri bawah
	dalam bidang kartesian 
*/

boolean LebihDari(POINT p1, POINT p2);
/*	mengirimkan true jika p1>p2. definisi lebih besar : lebih kanan atas
	di bidang kartesian
*/

//kelompok menentukan dimana p berada
boolean IsOrigin(POINT p);
/*	menghasilkan true jika p adalah titik origin */

boolean IsOnSbX(POINT p);
/*	menghasilkan true jika p terletak pada sumbu x */

boolean IsOnSbY(POINT p);
/*	menghasilkan true jika p terletak pada sumbu y */

int Kuadran(POINT p);
/*	menghasilkan kuadran dari p : 1, 2, 3 dan 4
	precond : p bukan titik origin
	dan  tidak terletak di salah satu sumbu
*/

//kelompok operasi lain terharap tipe
POINT NextX(POINT p);
/*	mengirim salinan P dengan absis ditambah satu */

POINT NextY(POINT p);
/*	mengirim salinan P dengan ordinat ditambah satu */

POINT PlusDelta(POINT p, float deltaX, float deltaY);
/*	mengim salinan p yang absisnya = absis(p) + deltaX
	dan ordinatnya adalah ordinat(p) +deltaY
*/

POINT MirrorOf(POINT p, boolean SbX, boolean SbY);
/*	menghasilkan salinan P yang dicerminkan
	tergantung nilai SbX dan SbY
	jika SbX bernilai true maka dicermintan thd sumbu x
	jika SbY bernilai true maka dicerminkan terhadap sumbu Y
*/

float Jarak0(POINT p);
/*	menghitung jarak p ke (0,0) */

float Panjang(POINT p1, POINT p2);
/*	menghitung panjang garis yang dibentuk p1 dan p2 */

void Geser(POINT *p, float deltaX, float deltaY);
/*	IS : p terdefinisi
	FS : p digeser absisnya sebesar deltaX dan ordinatnya sebesar deltaY
*/

void GeserKeSbX(POINT *p);
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu x
	contoh : jika koordinat semula (9,9) menjadi (9,0)
*/

void GeserKeSbY(POINT *p);
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu Y
	contoh : jika koordinat semula (9,9) menjadi (0,9)
*/

void Mirror(POINT *p, boolean SbX, boolean SbY);
/*	IS : p terdefinisi
	FS : p dicerminkan tergantung nilai SbX atauSbY
	jika SbX true maka dicerminkan terhadap sumbu X
	jika SbY true maka dicerminkan terhadap sumbu Y
*/

void Putar(POINT *p, float sudut);
/*	IS : p terdefinisi
	FS : p diputar sebesar (sudut) derajat berlawanan jarum jam
*/

boolean DalamRange (POINT P, POINT P1, float r);
/* Mengembalikan true apabila P1 berada dalam jarak r dari P
 * (jarak dari P1 ke P ≤ r). */
 
void GlideReflection (POINT *P, boolean sbX, float delta);
/* I.S. P terdefinisi
 * F.S. P dicerminkan terhadap sumbu x jika sbX bernilai true atau sumbu y jika sbX bernilai false, kemudian digeser sebesar delta searah sumbu yang digunakan sebagai sumbu pencerminan
 * Contoh: jika P=<3,4>, maka GlideReflection(P,true,-2) menghasilkan P=<1,-4>.
          Cerminkan terhadap sumbu-X menjadi <3,-4> kemudian digeser -2 satuan
          arah sumbu-X menjadi <1,-4>. */
          
#endif
