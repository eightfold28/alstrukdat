#include "garis.h"

/* konstruktor */
void MakeGARIS(POINT P1, POINT P2, GARIS *L){
	/* I.S. P1 dan P2 terdefinisi.
	   F.S. L terdefinisi dengan L.PAw= P1 dan L.Pakh=P2 */
	/* Algoritma */
	L->PAw = P1;
	L->PAkh = P2;	
}


/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS */

void BacaGARIS(GARIS *L){
	/* I.S. sembarang.
	 * F.S. L terdefinisi sebagai GARIS yang valid */
	 /* Kamus */
	 POINT P1, P2;
	 
	 /* Algoritma  */
	 BacaPoint(&P1);
	 BacaPoint(&P2);
	 MakeGARIS(P1, P2, L);
}

void TulisGARIS(GARIS L){
	/* I.S. L terdefinisi
	 * F.S. L tertulis di layar dengan format ((x,y), (x,y)) beserta newline */
	/* Algoritma */
	printf("((%.2f,%.2f), (%.2f,%.2f))\n", fabs(GetAbsis(L.PAw)), fabs(GetOrdinat(L.PAw)), fabs(GetAbsis(L.PAkh)), fabs(GetOrdinat(L.PAkh)));
}

float PanjangGARIS(GARIS L){
	/* Menghitung panjang garis L : sqrt(((L.PAw.x - L.PAkh.x) * (L.PAw.x - L.PAkh.x)) + ((L.PAw.y - GetOrdinat(L.PAkh)) * (L.PAw.y - GetOrdinat(L.PAkh))) */
	/* Kamus */
	float Panjang;
	
	/* Algoritma */
	Panjang = sqrt(((GetAbsis(L.PAw) - GetAbsis(L.PAkh)) * (GetAbsis(L.PAw) - GetAbsis(L.PAkh))) + ((GetOrdinat(L.PAw) - GetOrdinat(L.PAkh)) * (GetOrdinat(L.PAw) - GetOrdinat(L.PAkh))));
	return Panjang;
}

float Gradien(GARIS L){
	/* Mengembalikan Gradien (m) dari L.
	   Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
	/* Kamus */
	float Gradien;
	
	/* Algoritma */
	Gradien = ((GetOrdinat(L.PAkh) - GetOrdinat(L.PAw))/(GetAbsis(L.PAkh) - (GetAbsis(L.PAw))));
	return Gradien;
}

void GeserGARIS(GARIS *L, float deltaX, float deltaY){
	/* I.S. L terdefinisi
	 * F.S. L digeser sebesar deltaX dan ordinatnya sebesar deltaY */
	 SetAbsis(L->PAw, (GetAbsis(L->PAw) + deltaX));
	 SetAbsis(L->PAkh, (GetAbsis(L->PAkh) + deltaX));
	 SetOrdinat(L->PAw, (GetOrdinat(L->PAw) + deltaY));
	 SetOrdinat(L->PAkh, (GetOrdinat(L->PAkh) + deltaY));	 
}

boolean IsTegakLurus(GARIS L1, GARIS L2){
	/* Menghasilkan true jika L1 tegak lurus terhadap L2.
	 * Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
	/* Kamus */
	 const float epsilon = 0.00001;
	 boolean bool;
	
	/* Algoritma */
	if (fabs(((Gradien(L1) * Gradien(L2)) + 1) < epsilon)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
}

boolean IsSejajar(GARIS L1, GARIS L2){
	/* Menghasilkan true jika L "sejajar" terhadap L1.
	 * Dua garis saling sejajar jika memiliki gradien yang sama */
	 /* Kamus */
	 const float epsilon = 0.00001;
	 boolean bool;
	 
	/* Algoritma */
	if (fabs((Gradien(L1) - Gradien(L2)) < epsilon)){
		bool = true;
	} else {
		bool = false;
	}
	return bool;
} 
