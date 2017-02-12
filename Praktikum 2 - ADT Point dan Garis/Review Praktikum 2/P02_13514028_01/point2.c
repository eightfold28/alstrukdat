#include "point2.h"
#include "boolean.h"
#include <math.h>

/* 	Tambahkan pada file *.c anda baris berikut ini*/
	const float pi = 3.14;
	const float eps = 0.000000001;

POINT MakePoint(float x, float y)
/*	membentuk sebuah point dari komponen-komponennya */
{

    POINT p;

    SetAbsis(p, x);
    SetOrdinat(p, y);
    return p;
}


//interaksi dengan I/O device baca/tulis
void BacaPoint(POINT *p)
/*	Makepoint(x,y,P) membentuk P dari x dan y yang dibaca */
{

    float x, y;

    scanf("%f %f",&x,&y);
    *p = MakePoint(x, y);
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
    POINT p = MakePoint( (GetAbsis(p1) + GetAbsis(p2)) , ( GetOrdinat(p1) + GetOrdinat(p2))  );
    return p;

}

POINT Kurang(POINT p1, POINT p2)
/*	menghasilkan point bernilai p1-p2
	buatlah spesifikasi pengurangan dua buah point
*/
{
    POINT p = MakePoint( (GetAbsis(p1) - GetAbsis(p2)) , ( GetOrdinat(p1) - GetOrdinat(p2))  );
    return p;
}

float DotProduct(POINT p1, POINT p2)
/*	operasi perkalian p1.p2 melakukan operasi dot */
{

    float dot = (GetAbsis(p1)*GetAbsis(p2)) + (GetOrdinat(p1)*GetOrdinat(p2));
    return dot;
}

//kelompok operasi relasional terhadap point
boolean	EQ(POINT p1, POINT p2)
/*	mengirimkan true jika p1=p2 absis dan ordinatnya sama */
{
    if ((GetAbsis(p1) == GetAbsis(p2)) && (GetOrdinat(p1) == GetOrdinat(p2)))
        return true;
    else
        return false;
}


boolean NEQ(POINT p1, POINT p2)
/*	mengirimkan true jika p1 tidak sama dengan p2 */
{

     if ((GetAbsis(p1) != GetAbsis(p2)) || (GetOrdinat(p1) != GetOrdinat(p2)))
        return true;
    else
        return false;
}

boolean KurangDari(POINT p1, POINT p2)
/*	mengirimkan true jika p1<p2. definisi lebih kecil : lebih kiri bawah
	dalam bidang kartesian
*/
{
    if ((GetAbsis(p1) < GetAbsis(p2)) && (GetOrdinat(p1) < GetOrdinat(p2)))
        return true;
    else
        return false;

}

boolean LebihDari(POINT p1, POINT p2)
/*	mengirimkan true jika p1>p2. definisi lebih besar : lebih kanan atas
	di bidang kartesian
*/
{
    if ((GetAbsis(p1) > GetAbsis(p2)) && (GetOrdinat(p1) > GetOrdinat(p2)))
        return true;
    else
        return false;
}

//kelompok menentukan dimana p berada
boolean IsOrigin(POINT p)
/*	menghasilkan true jika p adalah titik origin */
{
    if ((GetAbsis(p) == 0.0) && (GetOrdinat(p) == 0.0))
        return true;
    else
        return false;
}

boolean IsOnSbX(POINT p)
/*	menghasilkan true jika p terletak pada sumbu x */
{
    if ( GetOrdinat(p) == 0.0)
        return true;
    else
        return false;
}


boolean IsOnSbY(POINT p)
/*	menghasilkan true jika p terletak pada sumbu y */
{
    if ( GetAbsis(p) == 0.0 )
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

    if (GetAbsis(p) > 0 && GetOrdinat(p) > 0)
        return 1;
    else if (GetAbsis(p) < 0 && GetOrdinat(p) > 0)
        return 2;
    else if (GetAbsis(p) < 0 && GetOrdinat(p) < 0)
        return 3;
    else
        return 4;


}


//kelompok operasi lain terharap tipe
POINT NextX(POINT p)
/*	mengirim salinan P dengan absis ditambah satu */
{
    SetAbsis(p, (GetAbsis(p) + 1));
    return p;
}


POINT NextY(POINT p)
/*	mengirim salinan P dengan ordinat ditambah satu */
{
    SetOrdinat(p, (GetOrdinat(p) + 1));
    return p;
}

POINT PlusDelta(POINT p, float deltaX, float deltaY)
/*	mengim salinan p yang absisnya = absis(p) + deltaX
	dan ordinatnya adalah ordinat(p) +deltaY
*/
{
    p = MakePoint( GetAbsis(p) + deltaX , GetOrdinat(p) + deltaY);
    return p;
}

POINT MirrorOf(POINT p, boolean SbX, boolean SbY)
/*	menghasilkan salinan P yang dicerminkan
	tergantung nilai SbX dan SbY
	jika SbX bernilai true maka dicermintan thd sumbu x
	jika SbY bernilai true maka dicerminkan terhadap sumbu Y
*/
{
    if (SbY == true)
        SetAbsis(p, GetAbsis(p) * (-1));

    if (SbX == true)
        SetOrdinat(p, GetOrdinat(p) * (-1));
    return p;
}

float Jarak0(POINT p)
/*	menghitung jarak p ke (0,0) */
{
    float hasil = sqrt(GetAbsis(p)*GetAbsis(p) + GetOrdinat(p)*GetOrdinat(p));
    return hasil;

}


float Panjang(POINT p1, POINT p2)
/*	menghitung panjang garis yang dibentuk p1 dan p2 */
{

    float hasil = sqrt((GetAbsis(p1) - GetAbsis(p2)) * (GetAbsis(p1) - GetAbsis(p2)) + (GetOrdinat(p1) - GetOrdinat(p2)) * (GetOrdinat(p1) - GetOrdinat(p2)));
    return hasil;

}


void Geser(POINT *p, float deltaX, float deltaY)
/*	IS : p terdefinisi
	FS : p digeser absisnya sebesar deltaX dan ordinatnya sebesar deltaY
*/
{
   *p = MakePoint( GetAbsis(*p) + deltaX, GetOrdinat(*p) + deltaY );
   return;
}

void GeserKeSbX(POINT *p)
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu x
	contoh : jika koordinat semula (9,9) menjadi (9,0)
*/
{
    SetOrdinat(*p,0);
	return;

}

void GeserKeSbY(POINT *p)
/*	IS : p terdefinisi
	FS : p di sumbu x dengan absis sama dengan absis sama
	dengan sbsis absis semula
	proses : tergeser ke sumbu Y
	contoh : jika koordinat semula (9,9) menjadi (0,9)
*/
{
    SetAbsis(*p,0);
	return;

}

void Mirror(POINT *p, boolean SbX, boolean SbY)
/*	IS : p terdefinisi
	FS : p dicerminkan tergantung nilai SbX atauSbY
	jika SbX true maka dicerminkan terhadap sumbu X
	jika SbY true maka dicerminkan terhadap sumbu Y
*/
{

	if (SbX == true)
			SetOrdinat(*p, GetOrdinat(*p) * (-1));

	if (SbY == true)
			SetAbsis(*p, GetAbsis(*p) * (-1));
	return;
}

void Putar(POINT *p, float sudut)
/*	IS : p terdefinisi
	FS : p diputar sebesar (sudut) derajat berlawanan jarum jam
*/
{
    POINT hasil;
    SetAbsis(hasil, (cos(pi*sudut/180) * GetAbsis(*p)) - sin(pi*sudut/180) * GetOrdinat(*p));
    SetOrdinat(hasil, (sin(pi*sudut/180) * GetAbsis(*p)) + cos(pi*sudut/180) * GetOrdinat(*p));
    *p = hasil;

	return;

}

boolean DalamRange (POINT P1,POINT P2, float r)
/*{ Mengembalikan true apabila P1 berada dalam jarak r dari P }

{ (jarak dari P1 ke P ≤ r) }
*/
{
	if (Panjang(P1,P2)<=r)
		return true;
	else
		return false;
}


void GlideReflection (POINT *p,boolean SbX, float delta)

/*{ I.S. P terdefinisi }

{ F.S. P dicerminkan terhadap sumbu x jika sbX bernilai true atau sumbu y jika sbX bernilai false, kemudian digeser sebesar delta searah sumbu yang digunakan sebagai sumbu pencerminan }

{ Contoh: jika P=<3,4>, maka GlideReflection(P,true,-2) menghasilkan P=<1,-4>.

          Cerminkan terhadap sumbu-X menjadi <3,-4> kemudian digeser -2 satuan

          arah sumbu-X menjadi <1,-4> }
*/
{
	if (SbX == true) //Mirror dan geser ke SbX
	{
		Mirror(p,true,false);
		Geser(p,delta,0);
	}
	else // mirror dan geser ke sumbu Y
	{
		Mirror(p,false,true);
		Geser(p,0,delta);
	}
}
