/*  [ATTENTION]
	Harap cantumkan identitas setiap pada file yang Anda submit!

	NIM/Nama  : 13514028/ Dharma Kurnia Septialoka
   	Nama file : matriks.c
   	Topik     : ADT Matriks
   	Tanggal   : 17 September 2015
   	Deskripsi : Realisasi dari header matriks.h
*/



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
#include "matriks.h"

/* KONSTRUKTOR */
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
/*	Membentuk sebuah MATRIKS kosong berukuran NB x NK di "ujung kiri atas" container
	I.S. NB dan NK adalah valid untuk container matriks yang dibuat
	F.S. Matriks M sesuai dengan definisi di atas terbentuk
	Matriks kosong berisi nilai ValUndef untuk setiap elemennya

	Untuk standardisasi, pada kasus ini set NBrsEff dan NKolEff sesuai NB dan NK
*/
{
    indeks i, j;

    if((NB<= (BrsMax - BrsMin + 1)) && (NK <= KolMax - KolMin + 1))
    {
        (*M).NBrsEff = NB;
        (*M).NKolEff = NK;
        for (i= 0; i<= NB; i++) //0 = BrsMin - 1
        {
            for (j= 0; j<= NK; j++ )
            {
                (*M).Mem[i][j] = ValUndef;
            }
        }
    }
}


/* SELEKTOR "DUNIA MATRIKS" */
indeks GetIdxBrsMin()
/* 	Mengirimkan indeks baris minimum matriks yang dapat dibuat oleh ADT */
{
    return BrsMin;
}

indeks GetIdxKolMin()
/*	Mengirimkan indeks kolom minumum matriks yang dapat dibuat oleh ADT */
{
    return KolMin;
}

indeks GetIdxBrsMax()
/*	Mengirimkan indeks baris maksimum matriks yang dapat dibuat oleh ADT */
{
    return BrsMax;
}

indeks GetIdxKolMax()
/*	Mengirimkan indeks kolom maksimum matriks yang dapat dibuat oleh ADT */
{
    return KolMax;
}

boolean IsIdxValid(int i, int j)
/*	Mengirimkan true jika i, j adalah indeks yang valid, indeks yang valid berada pada range indeks container
	yang dapat dibuat oleh ADT
*/
{
    if (i>= BrsMin && i<= BrsMax && j>= KolMin && j<= KolMax)
        return true;
    else return false;
}

/* UNTUK SEBUAH MATRIKS M YANG TERDEFINISI */
indeks FirstIdxBrs(MATRIKS M)
/*	Mengembalikan indeks baris terkecil yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */
{
    return BrsMin;
}

indeks FirstIdxKol(MATRIKS M)
/*	Mengembalikan indeks kolom terkecil yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */
{
    return KolMin;
}

indeks LastIdxBrs(MATRIKS M)
/*	Mengembalikan indeks baris terbesar yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */
{
    return GetNBrsEff(M);
}
/*
 {
	indeks i, j;
	i = M.NBrsEff;
	j = KolMin;
	while ((i >= BrsMin) && (M.Mem[i][j] == ValUndef)) {
		i = i - 1;
	}

	return i;
 }
 */

indeks LastIdxKol(MATRIKS M)
/*	Mengembalikan indeks kolom terbesar yang memiliki nilai yang sudah terdefinisi (bukan ValUndef) */
{
    return GetNKolEff(M);
}
/* {

	indeks i, j;


	i = BrsMin;
	j = M.NKolEff;
	while ((j >= KolMin) && (M.Mem[i][j] == ValUndef)) {
		j = j - 1;
	}

	return j;
}*/



int GetNBrsEff(MATRIKS M)
/*	Mengirimkan banyaknya baris efektif M */
{
    int x;
    x= M.NBrsEff;
    return x;
}

int GetNKolEff(MATRIKS M)
/*	mengirimkan banyaknya kolom efektif M */
{
    int x;
    x= M.NKolEff;
    return x;
}

boolean IsIdxEff(MATRIKS M, indeks i, indeks j)
/*	Mengirimkan true jika i, j adalah indeks efektif bagi M, yaitu berada dalam range FirstIdx...() sampai LastIdx...() */
{
    if (i>= GetIdxBrsMin(M) && i<= GetNBrsEff(M) && j>= GetIdxKolMin(M) && j<= GetNKolEff(M))
        return true;
    else return false;
}
el_type GetElmt(MATRIKS M, indeks i, indeks j)
/*	Mengirimkan elemen M dengan nomor baris i dan nomor kolom j */
{
    return M.Mem[i][j];
}

el_type GetElmtDiagonal(MATRIKS M, indeks i)
/*	Mengimkan elemen M(i,i) */
{
    return GetElmt(M, i, i);
}

/* OPERASI MENGUBAH NILAI ELEMEN MATRKS : SET/ASSIGN */
void SetBrsEff(MATRIKS *M, int NB)
/*	I.S. M sudah terdefinisi
	F.S. Nilai M.BrsEff diisi dengan NB
*/
{
    M-> NBrsEff = NB; //M-> artinya (*M)
}

void SetKolEff(MATRIKS *M, int NK)
/*	I.S. M sudah terdefinisi
	F.S. Nilai M.NKolEff diisi dengan NK
*/
{
    (*M).NKolEff = NK;
}

void SetEl(MATRIKS *M, int i, int j, el_type X)
/*	I.S. M sudah terdefinisi
	F.S. M(i,j) bernilai X
	Proses: Mengisi M(i,j) dengan X
*/
{
    (*M).Mem[i][j] = X;
}

/* ASSIGNMET MATRIKS */
void CopyMATRIKS(MATRIKS Min, MATRIKS *MHsl)
/*	Melakukan assignment Mhsl <- Min */
{
    indeks i, j, NB, NK;

    NB= GetNBrsEff(Min);
    NK= GetNKolEff(Min);
    MakeMATRIKS(GetNBrsEff(Min), GetNKolEff(Min), MHsl);
    for (i= BrsMin; i<= NB; i++)
    {
        for (j= KolMin; j<= NK; j++)
        {
            SetEl(MHsl, i, j, GetElmt(Min, i, j));
        }
    }
}


/* KELOMPOK BACA TULIS */
void BacaMATRIKS(MATRIKS *M, int NB, int NK)
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
{
    indeks i, j;
    el_type in;

    MakeMATRIKS(NB, NK, M);

    for (i= BrsMin; i<= NB; i++)
    {
        for (j= KolMin; j<= NK; j++)
        {
            scanf("%d", &in);
            SetEl(M, i, j, in);
        }
    }
}

void TulisMATRIKS(MATRIKS M)
/*	I.S. M terdefinisi
	F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layaR
	Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris

	contoh (sesuai dengan contoh pada baca matriks):
	[1, 2, 3] {tidak terdapat spasi pada akhir}
	[4, 5, 6] {"[" dan "]" juga dioutputkan}
	[7, 8, 9] {jangan lupa mengakhiri dengan sebuah newline}
*/
{
    indeks i, j;

    for (i= BrsMin; i<= GetNBrsEff(M); i++)
    {
        printf("[");
        for (j= KolMin; j<= GetNKolEff(M); j++)
        {
            if (j != GetNKolEff(M))
            {
                printf("%d, ", M.Mem[i][j]);
            }
            else
            {
                printf("%d", M.Mem[i][j]);
            }
        }
        printf("]\n");
    }
}


/* 	KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE
	Operasi aritmatika yang dilakukan sesuai operasi aritmatika matriks pada matematika
*/

MATRIKS Tambah(MATRIKS M1, MATRIKS M2)
/*	Prekondisi : M1 berukuran sama dengan M2
	Mengirim hasil penjumlahan matriks: M1 + M2
*/
{
    MATRIKS Tambah;

    indeks i, j;
    MakeMATRIKS(GetNBrsEff(M1), GetNKolEff(M1), &Tambah);
    for (i= BrsMin; i<= GetNBrsEff(M1); i++)
    {
        for (j= KolMin; j<= GetNKolEff(M1); j++)
        {
            Tambah.Mem[i][j] = M1.Mem[i][j] + M2.Mem[i][j];
        }
    }
    return Tambah;
}

MATRIKS Kurang(MATRIKS M1, MATRIKS M2)
/*	Prekondisi : M1 berukuran sama dengan M2
	Mengirim hasil pengurangan matriks: M1 - M2
*/
{
    MATRIKS Kurang;
    indeks i, j;
    for (i= BrsMin; i<= GetNBrsEff(M1); i++)
    {
        for (j= KolMin; j<= GetNKolEff(M1); j++)
        {
            Kurang.Mem[i][j] = M1.Mem[i][j] - M2.Mem[i][j];
        }
    }
    return Kurang;
}

MATRIKS Kali2Matriks(MATRIKS M1, MATRIKS M2)
/*	Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2
	Mengirim hasil perkalian matriks: M1 * M2
*/
{
    MATRIKS Kali;
	indeks i,j,k;
	// ALGORITMA
	MakeMATRIKS(GetNBrsEff(M1),GetNKolEff(M2),&Kali);
	for (i = BrsMin; i <= GetNBrsEff(M1); i++)
	{
		for (j = KolMin; j <= GetNKolEff(M1); j++)
		{
			SetEl(&Kali,i,j,0);
			for (k = KolMin; k <= GetNKolEff(M1); k++)
			{
				SetEl(&Kali,i,j,(GetElmt(Kali,i,j) + GetElmt(M1,i,k)*GetElmt(M2,k,j)));
			}
		}
	}
	return Kali;
}

MATRIKS KaliKons(MATRIKS M1, int X)
/*	Mengirim hasil perkalian setiap elemem M dengan X
*/
{
    MATRIKS Kons;
    indeks i, j;
    for (i= BrsMin; i<= GetNBrsEff(M1); i++)
    {
        for (j= KolMin; j<= GetNKolEff(M1); j++)
        {
            Kons.Mem[i][j] = M1.Mem[i][j] * X;
        }
    }
    return Kons;
}
void KaliKonsA(MATRIKS *M, int K)
/*	Mengalikan setiap elemen M dengan K
*/
{
    indeks i, j;
    for (i= BrsMin; i<= GetNBrsEff(*M); i++)
    {
        for (j= KolMin; j<= GetNKolEff(*M); j++)
        {
            (*M).Mem[i][j] = (*M).Mem[i][j] * K;
        }
    }
}

/* KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS */
boolean EQ(MATRIKS M1, MATRIKS M2)
/* 	Mengirimkan true jika M1 = M2,
	yaitu NBElmt(M1) = NBElmt(M2), dimensi matriks sama
	dan
	untuk setiap i,j yang merupakan indeks baris dan kolom
	M1(i,j) = M2(i,j)
*/
{
    boolean eq;
    int i, j;
    eq= true;
    if (NBElmt(M1) == NBElmt(M2))
    {
        for (i= BrsMin; i<= GetIdxBrsMin(M1); i++)
        {
            for (j= KolMin; j<= GetIdxKolMax(M1); j++)
            {
                if (M1.Mem[i][j] != M2.Mem[i][j])
                {
                    eq= false;
                }
            }
        }
    }
    else eq= false;
    return eq;
}
boolean NEQ(MATRIKS M1, MATRIKS M2)
/*	Mengirimkan true jika not EQ(M1,M2) */
{
    return !EQ(M1,M2);
}

boolean EQSize(MATRIKS M1, MATRIKS M2)
/*	Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2
	yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2)
*/
{
    if (GetNBrsEff(M1) == GetNBrsEff (M2) && GetNKolEff (M1) == GetNKolEff (M2))
        return true;
    else return false;
}

boolean KurangDari(MATRIKS M1, MATRIKS M2)
/*	Mengirimkan true jika ukuran efektif M1 < ukuran efektif M2, dalam artian luas efektifnya */
{
    if ((GetNBrsEff(M1) * GetNKolEff(M1)) < (GetNBrsEff(M2) * GetNKolEff(M2)))
		return true;
	else
		return false;
}

/* OPERASI LAIN */
int NBElmt(MATRIKS M)
/*	Mengirimkan banyaknya elemen efektif M, matriks kosong memiliki elemen efektif sebanyak 0 (lihat definisi matriks kosong) */
{
    int n;
    n= 0;
    indeks i, j;
    for (i= BrsMin; i<= GetNBrsEff(M); i++)
    {
        for (j= KolMin; j<= GetNKolEff(M); j++)
        {
            if (M.Mem[i][j] != ValUndef)
            {
                n++;
            }
        }
    }
    return n;
}

//KELOMPOK TEST TERHADAP MATRIKS
boolean IsBujurSangkar(MATRIKS M)
/*	Mengirimkan true jika M adalah matriks dengan ukuran baris dan kolom sama, matriks kosong adalah bujur sangkar */
{
    if ((GetNBrsEff(M) == GetNKolEff(M)) || (NBElmt(M) == 0))
        return true;
    else return false;
}

boolean IsSimetri(MATRIKS M)
/* 	Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) dan untuk
	setiap elemen M, M(i,j)=M(j,i)
*/
{
    boolean simetri;
    simetri= true;
    indeks i, j;
    if (IsBujurSangkar(M) == true)
    {
        for (i= BrsMin; i<= GetNBrsEff(M); i++)
        {
            for (j= KolMin; j<= GetNKolEff(M); j++)
            {
                if (M.Mem[i][j] != M.Mem[j][i])
                {
                    simetri= false;
                }
            }
        }
    }
    else
    {
        simetri= false;
    }
    return simetri;
}

boolean IsSatuan(MATRIKS M)
/*	Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan setiap
	elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0

	Ingat! Bernilai 0
*/
{
    indeks i, j;
	boolean found;

	i = FirstIdxBrs(M);
	j = FirstIdxKol(M);
	found = false;
	if (IsBujurSangkar(M)) {
		while (i <= M.NBrsEff && !(found)) {
			while (j <= M.NKolEff && !(found)) {
				if (i == j) {
					if (M.Mem[i][j] == 1) {
						j += 1;
					} else {
						found = true;
					}
				} else {
					if (M.Mem[i][j] == 0) {
						j += 1;
					} else {
						found = true;
					}
				}
			}
			i += 1;
		}
	} else {
		return false;
	}

	if (found) {
		return false;
	} else {
		return true;
	}
}



//PRAKTIKUM
float RataNIlai (MATRIKS M, indeks N)
/* Prekon: Matriks tidak kosong
 * Mengirimkan rata-rata nilai ujian ke-N
*/
{
	float Rata;
	int sum;
	indeks i, j;
	j= N;
	sum= 0;
	for (i= BrsMin; i<= GetNBrsEff(M); i++)
	{
		sum+= M.Mem[i][j];
	}
	Rata= sum/(GetNBrsEff(M));
	return Rata; 

}




indeks RataTestTertinggi (MATRIKS M)
/* Prekon: Matriks tidak kosong
 * Mengirim no test yg memiliki rata-rata kelas tertinggi
*/
{
	indeks j, RataTestTertinggi;
	RataTestTertinggi= 1;
	for (j= KolMin+1; j<= GetNKolEff(M); j++)
	{
		if (RataNIlai(M,j) > RataNIlai(M, j-1))
		{
			RataTestTertinggi= j;
		}
	}
	return RataTestTertinggi;
}

void TulisStatistikTest (MATRIKS M)
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
{
	indeks i, j;
	float avg;
	int min, max;\
	
	for (j= KolMin; j<= GetNKolEff(M); j++)
	{
	for (i= BrsMin; i<= GetNBrsEff(M); i++)
	{
		
			min= M.Mem[BrsMin][j];
			if (M.Mem[i][j] < min)
			{
				min= M.Mem[i][j];
			}
			max= M.Mem[BrsMin][j];
			if (M.Mem[i][j] > max)
			{
				max= M.Mem[i][j];
			}
			avg= RataNIlai(M, j);
		}
		printf("T%d Min=%d Max=%d Avg=%.2f\n", j, min, max, avg);
		
	}
}
			
void TulisMatriks1 (MATRIKS M)
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
{
	indeks i, j;
	
	for (i= BrsMin; i<= GetNBrsEff(M); i++)
	{
		printf("Mhs%d ", i);
		for (j= KolMin; j<= GetNKolEff(M); j++)
		{
			printf("T%d=%d ", j, M.Mem[i][j]);
		}
		printf("Avg=%.2f\n", RataNIlai(M,i));
	}
	
}


