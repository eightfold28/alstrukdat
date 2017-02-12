/*	Template Asisten
 * 	Topik	  : ADT Point
 * 	Tanggal	  : 1 September 2015
 *      Deskripsi : Header adt point
*       Untuk diketahui, kami menggunakan perbandingan bilangan floating point, dengan presisi epslon sebesar 0.00001
*	Perihangan: untuk fungsi yang memerlukan return bertipe boolean, gunakan return true/return false. Jangan menggunakan, misal "return GetAbsis(p)==0;"
*       Dilarang merubah header ini, karena akan menyebabkan compile error pada autograder
*       Semua fungsi yang terdapat pada header, harus terdapat pada file *.c (walaupun body kosong), bila tidak, akan menyebabkan compile error
*/

/*
 * NIM / Nama : 13514028 / Dharma Kurnia Septialoka
 * Nama File: P02_13514028_point.c
*/


#include "point2.h" // " artinya dr file external. <> artinya dr library compiler
#include "boolean.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>

const float pi= 3.14;

POINT MakePoint(float x, float y)
/*	membentuk sebuah point dari komponen-komponennya */
{
    POINT P;
    SetAbsis (P, x);
    SetOrdinat (P, y);
    return P; // yg return yg punya fungsi aja
}

//interaksi dengan I/O device baca/tulis
void BacaPoint(POINT *p)
/*	Makepoint(x,y,P) membentuk P dari x dan y yang dibaca */
 {
    float x;
    float y;
    scanf("%f %f", &x, &y);
    *p= MakePoint(x, y);
 }

void TulisPoint(POINT p)
/*	nilai p ditulis ke layar dengan format "(X,Y)"
	harap menggunakan presisi 2 angka dibelakang koma

	Silahkan gunakan line berikut ini
	printf("(%.2f, %.2f)\n",GetAbsis(p),GetOrdinat(p));
*/
{
    printf("%.2f, %.2f\n", GetAbsis(p), GetOrdinat(p));
}

//kelompok operasi aritmatika terhadap type
POINT Tambah(POINT p1, POINT p2)
/*	menghasilkan point yang bernilai p1 + p2
	melakukan operasi penjumlahan vektor
*/
{
    POINT P;
    float x, y;
    x= GetAbsis(p1) - GetAbsis(p2); //selektor= get
    y= GetOrdinat(p1) - GetOrdinat(p2);
    SetAbsis(P, x);
    SetOrdinat(P, y);
    return P;

}

POINT Kurang(POINT p1, POINT p2)
/*	menghasilkan point bernilai p1-p2
	buatlah spesifikasi pengurangan dua buah point
*/
{
    POINT P;
    float x, y;
    x= GetAbsis(p1) - GetAbsis(p2); //selektor= get
    y= GetOrdinat(p1) - GetOrdinat(p2);
    SetAbsis(P, x);
    SetOrdinat(P, y);
    return P;

}
float DotProduct(POINT p1, POINT p2)
/*	operasi perkalian p1.p2 melakukan operasi dot */
{
    float v;
    v = (GetAbsis(p1) * GetOrdinat(p1)) + (GetAbsis(p2) * GetOrdinat(p2));
    return v;
}

//kelompok operasi relasional terhadap point
boolean	EQ(POINT p1, POINT p2)
/*	mengirimkan true jika p1=p2 absis dan ordinatnya sama */
{
    if ((GetAbsis(p1) == (GetAbsis(p2))) && ((GetOrdinat(p1)) == (GetOrdinat(p2))))
    {
        return true;
    }
    else
    {
        return false;
    }

}

boolean NEQ(POINT p1, POINT p2)
/*	mengirimkan true jika p1 tidak sama dengan p2 */
{
    if ((GetAbsis(p1) != (GetAbsis(p2))) || ((GetOrdinat(p1)) != (GetOrdinat(p2))))
    {
        return true;
    }
    else
    {
        return false;
    }

}

boolean KurangDari(POINT p1, POINT p2)
/*	mengirimkan true jika p1<p2. definisi lebih kecil : lebih kiri bawah
	dalam bidang kartesian
*/
{
    if (GetAbsis(p1) < GetAbsis(p2) && GetAbsis(p1) < GetAbsis(p2))
    {
        return true;
    }
    else
    {
         return false;
    }

}



boolean LebihDari(POINT p1, POINT p2)
/*	mengirimkan true jika p1>p2. definisi lebih besar : lebih kanan atas
	di bidang kartesian
*/
{
    if (GetAbsis(p1) > GetAbsis(p2) && GetAbsis(p1) < GetAbsis(p2))
    {
        return true;
    }
    else
    {
        return false;
    }

}

//kelompok menentukan dimana p berada
boolean IsOrigin(POINT p)
/*	menghasilkan true jika p adalah titik origin */
 
{
   if ((GetAbsis(p) == 0.000000) && (GetOrdinat(p) == 0.000000))
   {
       return true;
   }
   else
   {
       return false;
   }

}

boolean IsOnSbX(POINT p)
/*	menghasilkan true jika p terletak pada sumbu x */
{
    if (GetOrdinat(p) == 0.000000)
        return true;
    else
        return false;
}


boolean IsOnSbY(POINT p)
/*	menghasilkan true jika p terletak pada sumbu y */
{
    if (GetAbsis(p) == 0.000000)
        return true;
    else
        return false;
}

int Kuadran(POINT p)
/*	menghasilkan kuadran dari p : 1, 2, 3 dan 4
	precond : p bukan titik origin
	dan  tidak terletak di salah satu sumbu
*/
{
    if ((GetAbsis(p)) > 0 && (GetOrdinat(p)) > 0)
     {
        return 1;
     }
    else if ((GetAbsis(p)) < 0 && (GetOrdinat(p)) > 0)
    {
        return 2;
    }
    else if ((GetAbsis(p)) < 0 && (GetOrdinat(p)) < 0)
    {
        return 3;
    }
    else if (GetAbsis(p) > 0 && GetOrdinat(p) > 0)
    {
        return 4;
    }

}



//kelompok operasi lain terharap tipe
POINT NextX(POINT p)
/*	mengirim salinan P dengan absis ditambah satu */
{
    POINT P;
        GetAbsis(P) += 1;
        GetOrdinat(P) = GetOrdinat(p);
    return P;
}

POINT NextY(POINT p)
/*	mengirim salinan P dengan ordinat ditambah satu */
{
    POINT P;
        GetAbsis(P) = GetAbsis(p);
        GetOrdinat(P) += 1;
    return P;
}

POINT PlusDelta(POINT p, float deltaX, float deltaY)
/*	mengim salinan p yang absisnya = absis(p) + deltaX
	dan ordinatnya adalah ordinat(p) +deltaY
*/
{
    POINT P;
    GetAbsis(P) += deltaX;
    GetOrdinat(P) += deltaY;
    return P;
}


POINT MirrorOf(POINT p, boolean SbX, boolean SbY)
/*	menghasilkan salinan P yang dicerminkan
	tergantung nilai SbX dan SbY
	jika SbX bernilai true maka dicermintan thd sumbu x
	jika SbY bernilai true maka dicerminkan terhadap sumbu Y
*/
{
    POINT P;
        if (SbX)
        {
            GetAbsis(P) = GetAbsis(p);
        }
        if (SbY)
        {
            GetOrdinat(P) = GetOrdinat(p);
        }
    return P;
}

float Jarak0(POINT p)
/*	menghitung jarak p ke (0,0) */
{
    float jarak;
    jarak = sqrt((pow(GetAbsis(p), 2)) + (pow(GetOrdinat(p), 2)));
    return jarak;
}

float Panjang(POINT p1, POINT p2)
/*	menghitung panjang garis yang dibentuk p1 dan p2 */
{
	float panjang;
    panjang = sqrt((pow(GetAbsis(p1) - GetAbsis(p2), 2)) + (pow(GetOrdinat(p1) - (GetOrdinat(p2)), 2)));
    return panjang;
}

void Geser(POINT *p, float deltaX, float deltaY)
/*	IS : p terdefinisi
	FS : p digeser absisnya sebesar deltaX dan ordinatnya sebesar deltaY
*/
{
    GetAbsis(*p) += deltaX;
    GetOrdinat(*p) += deltaY;
 }

void GeserKeSbX(POINT *p)
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu x
	contoh : jika koordinat semula (9,9) menjadi (9,0)
*/
{
    GetOrdinat(*p) = 0.0;
}

void GeserKeSbY(POINT *p)
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu Y
	contoh : jika koordinat semula (9,9) menjadi (0,9)
*/
{
    GetAbsis(*p) = 0.0;
}

void Mirror(POINT *p, boolean SbX, boolean SbY)
/*	IS : p terdefinisi
	FS : p dicerminkan tergantung nilai SbX atauSbY
	jika SbX true maka dicerminkan terhadap sumbu X
	jika SbY true maka dicerminkan terhadap sumbu Y
*/
{
    if (SbX)
        {
            GetOrdinat(*p) = -GetOrdinat(*p);
        }
    if (SbY)
        {
            GetAbsis(*p) = -GetAbsis(*p);
        }
}
void Putar(POINT *p, float sudut)
/*	IS : p terdefinisi
	FS : p diputar sebesar (sudut) derajat berlawanan jarum jam
*/
{
    float sudutrad = sudut * pi / 180;
    GetAbsis(*p) = GetAbsis(*p) * cos(sudutrad) - GetOrdinat(*p) * sin(sudutrad);
    GetOrdinat(*p) = GetAbsis(*p) * sin(sudutrad) + GetOrdinat(*p) * cos(sudutrad);
}

boolean DalamRange(POINT P, POINT P1, float r)
/*{ Mengembalikan true apabila P1 berada dalam jarak r dari P }
{ (jarak dari P1 ke P ≤ r) }
*/
{
	float x;
	x = Panjang(P, P1);
	if ( x <= r )
	{
		return true;
	}
	else
	{
		return false;
	}
}
void GlideReflection(POINT *P, boolean SbX, float delta)
/* { I.S. P terdefinisi }
{ F.S. P dicerminkan terhadap sumbu x jika sbX bernilai true atau sumbu y jika
sbX bernilai false, kemudian digeser sebesar delta searah sumbu yang digunakan
sebagai sumbu pencerminan }
{ Contoh: jika P=<3,4>, maka GlideReflection(P,true,-2) menghasilkan P=<1,-4>. 
* Cerminkan terhadap sumbu-X menjadi <3,-4> kemudian digeser-2 satuan arah sumbu-X menjadi <1,-4> }
*/
{
	if (SbX == true)
	{
		GetAbsis(*P) += delta;
		GetOrdinat(*P) = -GetOrdinat(*P);
	}
	else if (SbX == false)
	{
		GetOrdinat(*P) += delta;
		GetAbsis(*P) = -GetAbsis(*P);
	}
}
