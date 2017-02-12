/*	Template Asisten
 * 	Topik	  : ADT Point
 * 	Tanggal	  : 1 September 2015
 *      Deskripsi : Header adt point
*       Untuk diketahui, kami menggunakan perbandingan bilangan floating point, dengan presisi epslon sebesar 0.00001
*	Perihangan: untuk fungsi yang memerlukan return bertipe boolean, gunakan return true/return false. Jangan menggunakan, misal "return GetAbsis(p)==0;"
*       Dilarang merubah header ini, karena akan menyebabkan compile error pada autograder
*       Semua fungsi yang terdapat pada header, harus terdapat pada file *.c (walaupun body kosong), bila tidak, akan menyebabkan compile error
*/

#include "point.h"

/* 	Tambahkan pada file *.c anda baris berikut ini
	const float pi = 3.14;
*/

POINT MakePoint(float x, float y){
/*	membentuk sebuah point dari komponen-komponennya */
	/* Kamus */
	POINT p;
	
	/* Algoritma */
	p.x = x;
	p.y = y;
	return p;
}
//interaksi dengan I/O device baca/tulis

void BacaPoint(POINT *p){
/*	Makepoint(x,y,P) membentuk P dari x dan y yang dibaca */
	/* Kamus */
	float x, y;
	
	/* Algoritma */
	scanf("%f\n", &x);
	scanf("%f\n", &y);

	*p = MakePoint(x,y);
}

void TulisPoint(POINT p){
/*	nilai p ditulis ke layar dengan format "(X,Y)" 
	harap menggunakan presisi 2 angka dibelakang koma

	Silahkan gunakan line berikut ini
	printf("(%.2f, %.2f)\n",GetAbsis(p),GetOrdinat(p));
*/
	if (p.x == -0){
		p.x = 0;
	}
	if (p.y == -0){
		p.y = 0;
	}
	printf("(%.2f,%.2f)\n",GetAbsis(p),GetOrdinat(p));
}

//kelompok operasi aritmatika terhadap type
POINT Tambah(POINT p1, POINT p2){
/*	menghasilkan point yang bernilai p1 + p2
	melakukan operasi penjumlahan vektor
*/
	/* Kamus */
	POINT p;
	
	/* Algoritma */
	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	return p;
}

POINT Kurang(POINT p1, POINT p2){
/*	menghasilkan point bernilai p1-p2 
	buatlah spesifikasi pengurangan dua buah point 
*/
	/* Kamus */
	POINT p;
	
	/* Algoritma */
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}

float DotProduct(POINT p1, POINT p2){
/*	operasi perkalian p1.p2 melakukan operasi dot */
	/* Kamus */
	float dot;
	
	/* Algoritma */
	dot = (p1.x * p2.x) + (p1.y * p2.y);
	return dot;
}

//kelompok operasi relasional terhadap point
boolean	EQ(POINT p1, POINT p2){
/*	mengirimkan true jika p1=p2 absis dan ordinatnya sama */
	/* Algoritma */
	if ((p1.x == p2.x) && (p1.y == p2.y)){
		return true;
	} else {
		return false;
	}
}

boolean NEQ(POINT p1, POINT p2){
/*	mengirimkan true jika p1 tidak sama dengan p2 */
	/* Algoritma */
	if ((p1.x == p2.x) && (p1.y == p2.y)){
		return false;
	} else {
		return true;
	}
}

boolean KurangDari(POINT p1, POINT p2){
/*	mengirimkan true jika p1<p2. definisi lebih kecil : lebih kiri bawah
	dalam bidang kartesian 
*/
	/* Kamus */
	boolean bool;
	
	/* Algoritma */
	if ((p1.x < p2.x) && (p1.y < p2.y)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
}

boolean LebihDari(POINT p1, POINT p2){
/*	mengirimkan true jika p1>p2. definisi lebih besar : lebih kanan atas
	di bidang kartesian
*/
	/* Kamus */
	boolean bool;
	
	/* Algoritma */
	if ((p1.x > p2.x) && (p1.y > p2.y)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
}

//kelompok menentukan dimana p berada
boolean IsOrigin(POINT p){
/*	menghasilkan true jika p adalah titik origin */
	/* Kamus */
	boolean bool;
	
	/* Algoritma */
	if ((p.x == 0) && (p.y == 0)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
}

boolean IsOnSbX(POINT p){
/*	menghasilkan true jika p terletak pada sumbu x */
	/* Kamus */
	boolean bool;
	
	/* Algoritma */
	if ((p.x == 0)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
}

boolean IsOnSbY(POINT p){
/*	menghasilkan true jika p terletak pada sumbu y */
	/* Kamus */
	boolean bool;
	
	/* Algoritma */
	if ((p.y == 0)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
}

int Kuadran(POINT p){
/*	menghasilkan kuadran dari p : 1, 2, 3 dan 4
	precond : p bukan titik origin
	dan  tidak terletak di salah satu sumbu
*/
	/* Kamus */
	int Kuad;
	
	/* Algoritma */
	if ((p.x > 0) && (p.y > 0)){
		Kuad = 1;
	} else if ((p.x < 0) && (p.y > 0)){
		Kuad = 2;
	} else if ((p.x < 0) && (p.y < 0)){
		Kuad = 3;
	} else {
		Kuad = 4;
	}
	return Kuad;
}

//kelompok operasi lain terharap tipe
POINT NextX(POINT p){
/*	mengirim salinan P dengan absis ditambah satu */
	p.x = p.x + 1;
	return p;
}
	
	
POINT NextY(POINT p){
/*	mengirim salinan P dengan ordinat ditambah satu */
	p.y = p.y + 1;
	return p;
}

POINT PlusDelta(POINT p, float deltaX, float deltaY){
/*	mengim salinan p yang absisnya = absis(p) + deltaX
	dan ordinatnya adalah ordinat(p) +deltaY
*/
	/* Kamus */
	POINT pD;
	
	/* Algoritma */
	pD.x = p.x + deltaX;
	pD.y = p.y + deltaY;
	return pD;
}

POINT MirrorOf(POINT p, boolean SbX, boolean SbY){
/*	menghasilkan salinan P yang dicerminkan
	tergantung nilai SbX dan SbY
	jika SbX bernilai true maka dicermintan thd sumbu x
	jika SbY bernilai true maka dicerminkan terhadap sumbu Y
*/
	/* Kamus */
	POINT pM;
	
	/* Algoritma */
	if ((SbX == true) && (SbY == true)){
		pM.x = -p.x;
		pM.y = -p.y;
	} else if ((SbX == true)){
		pM.x = p.x;
		pM.y = -p.y;
	} else if ((SbY == true)){
		pM.x = -p.x;
		pM.y = p.y;
	} else {
		pM.x = p.x;
		pM.y = p.y;
	}
	return pM;
}

float Jarak0(POINT p){
/*	menghitung jarak p ke (0,0) */
	/* Kamus */
	float Jarak;
	
	/* Algoritma */
	Jarak = sqrt((p.x * p.x) + (p.y * p.y));
	return Jarak;
}

float Panjang(POINT p1, POINT p2){
/*	menghitung panjang garis yang dibentuk p1 dan p2 */
	/* Kamus */
	float Panjang;
	
	/* Algoritma */
	Panjang = sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
	return Panjang;
}

void Geser(POINT *p, float deltaX, float deltaY){
/*	IS : p terdefinisi
	FS : p digeser absisnya sebesar deltaX dan ordinatnya sebesar deltaY
*/
	p->x = p->x + deltaX;
	p->y = p->y + deltaY;
} 

void GeserKeSbX(POINT *p){
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu x
	contoh : jika koordinat semula (9,9) menjadi (9,0)
*/
	p->y = 0;
}

void GeserKeSbY(POINT *p){
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu Y
	contoh : jika koordinat semula (9,9) menjadi (0,9)
*/
	p->x = 0;
}

void Mirror(POINT *p, boolean SbX, boolean SbY){
/*	IS : p terdefinisi
	FS : p dicerminkan tergantung nilai SbX atauSbY
	jika SbX true maka dicerminkan terhadap sumbu X
	jika SbY true maka dicerminkan terhadap sumbu Y
*/
	/* Algoritma */
	if ((SbX == true) && (SbY == true)){
		p->x = -p->x;
		p->y = -p->y;
	} else if ((SbX == true)){
		p->x = p->x;
		p->y = -p->y;
	} else if ((SbY == true)){
		p->x = -p->x;
		p->y = p->y;
	} else {
		p->x = p->x;
		p->y = p->y;
	}
}


void Putar(POINT *p, float sudut){
/*	IS : p terdefinisi
	FS : p diputar sebesar (sudut) derajat berlawanan jarum jam
*/
	/* Kamus */
	const float pi = 3.14;
	
	/* Algoritma */
	p->x = p->x * cos(sudut/180 * pi) - p->y * sin(sudut/180 * pi);
	p->y = p->x * sin(sudut/180 * pi) + p->y * cos(sudut/180 * pi);
}

boolean DalamRange (POINT P, POINT P1, float r){
/* Mengembalikan true apabila P1 berada dalam jarak r dari P
 * (jarak dari P1 ke P ≤ r). */
	/* Kamus */
	boolean bool;
	const float epsilon = 0.00001;
	
	/* Algoritma */
	if (fabs((Panjang(P, P1) - r) < epsilon)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
}
 
void GlideReflection (POINT *P, boolean sbX, float delta){
/* I.S. P terdefinisi
 * F.S. P dicerminkan terhadap sumbu x jika sbX bernilai true atau sumbu y jika sbX bernilai false, kemudian digeser sebesar delta searah sumbu yang digunakan sebagai sumbu pencerminan
 * Contoh: jika P=<3,4>, maka GlideReflection(P,true,-2) menghasilkan P=<1,-4>.
          Cerminkan terhadap sumbu-X menjadi <3,-4> kemudian digeser -2 satuan
          arah sumbu-X menjadi <1,-4>. */
	/* Kamus */

	/* Algoritma */
	if ((sbX == true)){
		P->y = -P->y;
		P->x = P->x + delta;
	} else {
		P->x = -P->x;
		P->y = P->y + delta;
	}
}
