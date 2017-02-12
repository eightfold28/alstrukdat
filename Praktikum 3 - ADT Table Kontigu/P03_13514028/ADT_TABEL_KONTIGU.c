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


#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "ADT_TABEL_KONTIGU.h"




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
void MakeEmpty(TabInt *T)
/* 	I.S. sembarang
	F.S. Terbentuk tabel T kosong dengan semua elemen bernilai ValUndef

	Ingat! T.TI[0] tidak dihitung sebagai elemen pertama, artinya untuk T dengan kapasitas maksimum sebesar N,
	memiliki ruang elemen sebanyak N+1 (karena T.TI[0] bukan elemen pertama, T.TI[0] hanya sentinel)
*/
{
    /*Kamus lokal*/
    IdxType i;

    /*Algoritma*/
    for (i= IdxMin; i <= IdxMax; i++)
    {
        (*T).TI[i] = ValUndef;
    }
}


//SELEKTOR
int	NbElmt(TabInt T)
/*	Mengirimkan banyaknya elemen efektif tabel
	Mengirimkan nol jika tabel kosong
*/
{
    /*Kamus lokal*/
    int x=0;
    IdxType i;

    /*Algoritma*/
    for (i= IdxMin; i<= IdxMax; i++)
        {
            if (T.TI[i] != ValUndef)
            {
                   x++;
            } else return x; //break maksudnya berhenti gausah ngapa2in kalo misal ketemu T.TI[i] = ValUndef
        }
            return IdxMax;

}


int MaxNbEl(TabInt T)
/*	Mengirimkan maksimum elemen yang dapat ditampung oleh tabel (IdxMax - IdxMin+1) */
{
    /*KAMUS*/
    int x;

    /*ALGORITMA*/
    x= IdxMax - IdxMin + 1;
    return x;
}
IdxType	GetFirstIdx(TabInt T)
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks elemen pertama
*/
{
    /*KAMUS LOKAL*/
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks elemen efektif terakhir
*/
{
    /*KAMUS LOKAL*/
    int n;
    n = NbElmt(T);
    return n;
}


ElType GetElmt(TabInt T, IdxType i)
/*	Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) }
	Mengirimkan elemen tabel yang ke-i
*/
{
    /*KAMUS*/
    ElType x;

    /*Algoritma*/
    x = T.TI[i];
    return x;
}


//SELEKTOR
void SetTab(TabInt Tin, TabInt *Tout)
/*	I.S. Tin terdefinisi, sembarang
	F.S. Tout berisi salinan Tin
*/
{
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    MakeEmpty(Tout);
    for (i= GetFirstIdx(Tin); i<= GetLastIdx(Tin); i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
}

void SetEl(TabInt *T, IdxType i, ElType v)
/*	I.S. T terdefinisi, sembarang
	F.S. Elemen T yang ke-i bernilai v
	Merubah nilai elemen tabel yang ke-i sehingga bernilai v
*/
{
    /*KAMUS*/

    /*ALGORITMA*/
        (*T).TI[i] = v;

}
//INDEKS YANG VALID
boolean	IsIdxValid(TabInt T, IdxType i)
/*	Prekondisi : i sembarang }
	Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel }
	yaitu antara indeks yang terdefinisi utk container (IdxMin, IdxMax)}
*/
{
    if (i>= IdxMin && i<= IdxMax)
        return true;
    else
        return false;
}
boolean IsIdxEff(TabInt T, IdxType i)
/*	Prekondisi : i sembarang
	Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel
	yaitu antara FirstIdx(T)..LastIdx(T)
*/
{
    if (i>= GetFirstIdx(T) && i<= GetLastIdx(T))
        return true;
    else
        return false;
}

//KOSONG/PENUH
boolean IsEmpty(TabInt T)
/*	Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    if (NbElmt(T) == 0)
        return true;
    else return false;

    /*
    for (i= IdxMinTab(T); i<= IdxMaxTab(T); i++)
    {
        if (T.TI[i] != ValUndef)
            return false;
    }
    return true;
    */
}

boolean IsFull(TabInt T)
/*	Mengirimkan true jika tabel T penuh (sesuai kapasitas maksimum malloc), mengirimkan false jika tidak */
{
    if (NbElmt(T) == MaxNbEl(T))
        return true;
    else
        return false;
}
    /*
    IdxType i;
    for (i= GetFirstIdx(T); i<= GetLastIdx(T); i++)
    {
        if (T.TI[i] != ValUndef)
            return true;
        else
            return false;
    }
    */


//BACA DAN TULIS DENGAN INPUT/OUTPUT
void BacaIsi(TabInt *T)
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
{
    /*Kamus Lokal*/
    IdxType i, x;

    /*Algoritma*/
    MakeEmpty(T);
    scanf("%d", &x);
    for (i= IdxMin; i<= (IdxMin + x - 1); i++)
    {
        scanf("%d", &(*T).TI[i]);
    }
}

void TulisIsi(TabInt T)
/*	Proses : Menuliskan isi tabel dengan traversal
	I.S. T boleh kosong
	F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah
	Jika T kosong : Hanya menulis "Tabel kosong". Indeks dimulai dari indeks ke-0
	Format penulisan "<indeks> - <isi>" ingat diberikan newline untuk setiap row

	contoh:
	[1] - 100
	[2] - 99
	dst
*/
{
    /*Kamus lokal*/
    IdxType i;

    /*Algoritma*/
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
        for (i = IdxMin; i <= NbElmt(T); i++)
        {
            printf("[%d] - %d\n", i, T.TI[i]);
        }
}

void TulisIsiTab(TabInt T)
/*	Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung
	siku; antara dua elemen dipisahkan dengan separator "koma"
	I.S. T boleh kosong
	F.S. Jika T tidak kosong: [e1, e2, ... ,en]
	Contoh : jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30]
	Jika tabel kosong : menulis []
	ingat berikan newline pada output
*/
{
    /*Kamus lokal*/
    IdxType i;

    /*Algoritma*/
    if (IsEmpty(T))
    {
        printf("[]\n");
    }
    else
    {
        printf("[");
        for (i= GetFirstIdx(T); i<= GetLastIdx(T); i++)
        {
            if (i == GetLastIdx(T))
            {
                printf("%d", T.TI[i]);
            }
            else
            {
                printf("%d, ", T.TI[i]);
            }
        }
        printf("]\n");
    }
}

//OPERATOR ARITMATIKA
TabInt PlusTab(TabInt T1, TabInt T2)
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong dengan definisi tiap elemen dengan indeks yang sama ditambahkan
	Mengirimkan T1 + T2
*/
{
    /*Kamus lokal*/
    TabInt TPlus;
    IdxType i;

    /*Algoritma*/
    for (i = GetFirstIdx(T1); i<= GetLastIdx(T1); i++)
    {
        TPlus.TI[i] = T1.TI[i] + T2.TI[i];
    }
    return TPlus;
}
TabInt MinusTab(TabInt T1,TabInt T2)
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong dengan definisi tiap elemen dengan indeks yang sama ditambahkan
	Mengirimkan T1 - T2
*/
{
    /*Kamus lokal*/
    TabInt TKurang;
    IdxType i;

    /*Algoritma*/
    for (i = GetFirstIdx(T1); i<= GetLastIdx(T1); i++)
    {
        TKurang.TI[i] = T1.TI[i] - T2.TI[i];
    }
    return TKurang;
}

TabInt KaliTab(TabInt T1,TabInt T2)
/*	Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
	Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan
*/
{
    /*Kamus lokal*/
    TabInt TKali;
    IdxType i;

    /*Algoritma*/
    for (i = GetFirstIdx(T1); i<= GetLastIdx(T1); i++)
    {
        TKali.TI[i] = T1.TI[i] * T2.TI[i];
    }
    return TKali;
}
TabInt KaliKons(TabInt Tin, ElType c)
/*	Prekondisi : Tin tidak kosong
	Mengirimkan tabel dengan setiap elemen Tin dikalikan c
*/
{
    /*Kamus lokal*/
    TabInt TKons;
    IdxType i;

    /*Algoritma*/
    for (i = GetFirstIdx(Tin); i<= GetLastIdx(Tin); i++)
    {
        TKons.TI[i] = Tin.TI[i] * c;
    }
    return TKons;
}

//OEPRATOR RELASIONAL
boolean IsEQ(TabInt T1, TabInt T2)
/*	Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua
	elemennya sama
*/
{
    /* Kamus Lokal */
    boolean cek;
    IdxType i;

    /* Algoritma */
    i = IdxMin;
    cek = true;
    while ( (i <= GetLastIdx(T1)) && (cek) ) {
        if (GetElmt(T1, i) != GetElmt(T2, i)) {
            cek = false;
        }
        i++;
    }
    return cek;
}

boolean IsLess(TabInt T1, TabInt T2)
/*	Mengirimkan true jika T1 < T2, precond : T1 dan T2 memiliki ukuran yang sama
	yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3]. T1 < T2 bila semua elemen T1 lebih kecil dari elemen T2
*/
{
    /* Kamus Lokal */
    boolean cek;
    IdxType i;

    /* Algoritma */
    i = IdxMin;
    cek = true;
    while ( (i <= GetLastIdx(T1)) && (cek) ) {
        if (GetElmt(T1, i) >= GetElmt(T2, i)) {
            cek = false;
        }
        i++;
    }
    return cek;
}

//SEARCHING
IdxType	Search1(TabInt T, ElType X)
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X
	Jika tidak ada, mengirimkan IdxUndef
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong
	Memakai skema search TANPA boolean
*/
{
    /*Kamus lokal*/
    IdxType i;

    /*Algoritma*/
    if (IsEmpty(T))
        return IdxUndef;
    else
    {
        i= GetFirstIdx(T);
        while (T.TI[i] != X && i<= GetLastIdx(T))
        {
            i++;
        }
        if (i>GetLastIdx(T))
            return IdxUndef;
        else
            return i;

    }
}

IdxType	Search2(TabInt T, ElType X)
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X
	Jika tidak ada, mengirimkan IdxUndef
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong
	Memakai skema search DENGAN boolean Found
*/
{
    /*Kamus lokal*/
    IdxType i;
    boolean found;

    /*Algoritma*/
    if (IsEmpty(T))
        return IdxUndef;
    else
    {
        i= GetFirstIdx(T);
        found= false;
        while (!found && i<= GetLastIdx(T))
        {
            if (T.TI[i] == X)
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
        if (found)
            return i;
        else
            return IdxUndef;
    }

}
boolean SearchB(TabInt T, ElType X)
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan true, jika tidak ada menghasilkan false
	Menghasilkan false jika tabel T kosong
	Memakai Skema search DENGAN boolean
*/
{
    int i;
    boolean found;
    if (IsEmpty(T))
        return false;
    else
    {
        i= GetFirstIdx(T);
        found= false;
        while (!found && i<= GetLastIdx(T))
        {
            if (T.TI[i] == X)
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
        return found;
    }
}
boolean	SearchSentinel(TabInt T, ElType X)
/*	Search apakah ada elemen tabel T yang bernilai X
	Jika ada, menghasilkan true jika X ada dan false bila X tidak ada
	dengan metoda sequential search dengan sentinel
	Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C yang
	tidak dipakai dalam definisi tabel
	Menghasilkan false jika tabel T kosong
*/
{
    /*Kamus lokal*/
    IdxType i;

    /*Algoritma*/
    T.TI[0] = X; //Pasang Sentinel
    i = GetLastIdx(T);
    while (T.TI[i] != X)
    {
        i--;
    }
    if (i > 0)
        return true;
    else
        return false;
}

//NILAI EKSTREM
ElType ValMax(TabInt T)
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan nilai maksimum tabel
*/
{
    /*Kamus lokal*/
    IdxType i;
    ElType max;

    /*Algoritma*/
    max= T.TI[GetFirstIdx(T)];
    for (i = GetFirstIdx(T) + 1; i<= GetLastIdx(T); i++)
    {
        if (T.TI[i] > max)
        {
            max= T.TI[i];
        }
    }
    return max;
}

ElType ValMin(TabInt T)
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan nilai minimum tabel
*/
{
    /*Kamus lokal*/
    IdxType i;
    ElType min;

    /*Algoritma*/
    min= T.TI[GetFirstIdx(T)];
    for (i = GetFirstIdx(T) + 1; i<= GetLastIdx(T); i++)
    {
        if (T.TI[i] < min)
        {
            min= T.TI[i];
        }
    }
    return min;
}

IdxType IdxMaxTab(TabInt T)
/*	Prekondisi : Tabel T tidak kosong
	Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel, keluarkanlah index pertama kali nilai maximum tsb muncul
*/
{
    /*Kamus lokal*/
    IdxType i;
    ElType imax, max;

    /*Algoritma*/
    max= T.TI[GetFirstIdx(T)];
    imax= GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1; i<= GetLastIdx(T); i++)
    {
        if (T.TI[i] > max)
        {
            imax = i;
            max = T.TI[i];
        }
    }
    return imax;
}

IdxType IdxMinTab(TabInt T)
/*	Prekondisi : Tabel tidak kosong
	Mengirimkan indeks i dengan elemen ke-i adalah nilai minimum pada tabel, keluarkanlah index pertama kali nilai maximum tsb muncul
*/
{
    /*Kamus lokal*/
    IdxType i;
    ElType imin, min;

    /*Algoritma*/
    min= T.TI[GetFirstIdx(T)];
    imin= GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1; i<= GetLastIdx(T); i++)
    {
        if (T.TI[i] < min)
        {
            imin = i;
            min = T.TI[i];
        }
    }
    return imin;
}

//OPERASI LAIN
void CopyTab(TabInt Tin, TabInt *Tout)
/*	I.S. sembarang
	F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik)
	Proses : Menyalin isi Tin ke Tout
*/
{
    SetTab(Tin, Tout);
}

TabInt InverseTab(TabInt T)
/*	Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu :
	elemen pertama menjadi terakhir,
	elemen kedua menjadi elemen sebelum terakhir, dst..
	Tabel kosong menghasilkan tabel kosong
*/
{
    /*Kamus lokal*/
    TabInt InTab;
    IdxType i;

    /*Algoritma*/
    MakeEmpty(&InTab);
    if (IsEmpty(T) == false)
    {
        for (i = GetFirstIdx(T); i<= GetLastIdx(T); i++)
        {
            InTab.TI[GetLastIdx(T) - i + 1] = T.TI[i];
        }
    }
    return InTab;
}
boolean IsSimetris(TabInt T)
/*	Menghasilkan true jika tabel simetrik
	Tabel disebut simetrik jika:
	elemen pertama = elemen terakhir,
	elemen kedua = elemen sebelum terakhir, dan seterusnya
	Tabel kosong adalah tabel simetris
*/
{
    /*Kamus lokal*/
    IdxType i, j;
    boolean simetris;

    /*Algoritma*/

    if (IsEmpty(T))
    {
        simetris = true;
    }
    else
    {
        i= GetFirstIdx(T);
        j= GetLastIdx(T);
        simetris= true;
        while ((i<= j) && simetris == true)
        {
            if (T.TI[i] == T.TI[j])
            {
                simetris= true;
                i++;
                j--;
            }
            else
            {
                simetris = false;
            }
        }
    }
    return simetris;
}

//SORTING
void MaxSortDesc(TabInt *T)
/*	I.S. T boleh kosong
	F.S. T elemennya terurut menurun dengan Maximum Sort
	Proses : mengurutkan T sehingga elemennya menurun/mengecil
	tanpa menggunakan tabel kerja
*/
{
    IdxType i, pass, imax;
    ElType temp;

    for (pass= GetFirstIdx(*T); pass <= (GetLastIdx(*T) - 1); pass++)
    {
        imax= pass;
        for (i = (pass+1); i<= GetLastIdx(*T); i++)
        {
            if ((*T).TI[imax] < (*T).TI[i])
            {
                imax= i;
            }
        }
        temp = (*T).TI[imax];
        (*T).TI[imax] = (*T).TI[pass];
        (*T).TI[pass] = temp;
    }
}

void InsSortAsc(TabInt *T)
/*	I.S. T boleh kosong
	F.S. T elemennya terurut menaik dengan Insertion Sort
	Proses : mengurutkan T sehingga elemennya menaik/membesar
	tanpa menggunakan tabel kerja
*/
{
    IdxType i, pass;
    ElType temp;

    if (NbElmt(*T) > 1)
    {
        for (pass = GetFirstIdx(*T) + 1; pass <= GetLastIdx(*T); pass++)
        {
            temp= (*T).TI[pass];
            i= pass-1;
            for (; (temp < (*T).TI[i]) &&  (i > GetFirstIdx(*T));)
            {
                (*T).TI[i+1] = (*T).TI[i];
                i= i-1;
            }
            if (temp >= (*T).TI[i])
            {
                (*T).TI[i+1] = temp;
            }
            else
            {
                (*T).TI[i+1] = (*T).TI[i];
                (*T).TI[i] = temp;
            }

        }
    }
}

//MENAMBAH ELEMEN
void AddAsLastEl(TabInt *T, ElType X)
/*	Menambahkan X sebagai elemen terakhir tabel
	I.S. Tabel boleh kosong, tetapi tidak penuh
	F.S. X adalah elemen terakhir T yang baru
	Proses : Menambahkan sebagai elemen ke-i yang baru
*/
{
    if (IsFull(*T) == false)
    {
        (*T).TI[GetLastIdx(*T) + 1] = X;
    }
}
//value ke pointer pake &, pointer ke value pake *
void AddEli(TabInt *T, ElType X, IdxType i)
/*	Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas terhadap
	elemen yang sudah ada
	I.S. Tabel tidak kosong dan tidak penuh
	i adalah indeks yang valid.
	F.S. X adalah elemen ke-i T yang baru
	Proses : Geser elemen ke-i+1 s.d. terakhir
	Isi elemen ke-i dengan X
*/
{
    /*Kamus lokal*/
    IdxType j;

    /*Algoritma*/
    for (j= GetLastIdx(*T)+1; j>= i; j--)
    {
        (*T).TI[j]= (*T).TI[j-1];
    }
    (*T).TI[i]= X;
}
//MENGHAPUS ELEMEN
void DelLastEl(TabInt *T, ElType *X)
/*	Proses : Menghapus elemen terakhir tabel
	I.S. Tabel tidak kosong
	F.S. X adalah nilai elemen terakhir T sebelum penghapusan,
	Banyaknya elemen tabel berkurang satu
	Tabel T mungkin menjadi kosong
*/
{
    *X = (*T).TI[GetLastIdx(*T)];
    (*T).TI[GetLastIdx(*T)]= ValUndef;
}
void DelEli(TabInt *T, IdxType i, ElType *X)
/*	Proses : Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas
	I.S. Tabel tidak kosong, i adalah indeks efektif yang valid
	F.S. Elemen T berkurang satu
	Banyaknya elemen tabel berkurang satu
	Tabel T mungkin menjadi kosong
	Proses : Geser elemen ke-i+1 s.d. elemen terakhir
	Kurangi elemen efektif tabel
*/
{
    /*Kamus lokal*/
    IdxType j;

    /*Algoritma*/
    *X = (*T).TI[i];
    for (j= i+1; j<= GetLastIdx(*T); j++)
    {
        (*T).TI[j-1]= (*T).TI[j];
    }
}


//TABEL DENGAN ELEMEN TERURUT MEMBESAR
IdxType SearchUrut(TabInt T, ElType X)
/*	Prekondisi: Tabel boleh kosong. Jika tidak kosong, elemen terurut membesar.
	mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan
	mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X
	Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong
*/
{
    IdxType i;

    if (IsEmpty(T))
    {
        return IdxUndef;
    }
    else
    {
        i = GetFirstIdx(T);
        while (i <= GetLastIdx(T) && (T.TI[i] < X)){
            i++;
        }
        if (T.TI[i] == X){
            return i;
        }
        else{
            return IdxUndef;
        }

    }
}
ElType Max(TabInt T)
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai maksimum pada tabel
*/
{
    return (T.TI[GetLastIdx(T)]);
}

ElType Min(TabInt T)
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai minimum pada tabel
*/
{
    return (T.TI[GetFirstIdx(T)]);
}

MaksimumMinimum MaxMin(TabInt T)
/*	Prekondisi : Tabel tidak kosong, elemen terurut membesar
	Mengirimkan nilai maksimum dan minimum pada tabel
*/
{
    MaksimumMinimum maksmin;
    maksmin.maks = T.TI[GetLastIdx(T)];
    maksmin.min = T.TI[GetFirstIdx(T)];
    return maksmin;
}

void Add1Urut(TabInt *T, ElType X)
/*	Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel
	Nilai dalam tabel tidak harus unik.
	I.S. Tabel boleh kosong, boleh penuh.
	Jika tabel isi, elemennya terurut membesar.
	F.S. Jika tabel belum penuh, menambahkan X.
	Jika tabel penuh, maka tabel tetap.
	Proses : Search tempat yang tepat sambil geser
	Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan
*/
{
    /* Kamus lokal */
    IdxType i;

    /*Algoritma*/
    if (IsEmpty(*T))
    {
        (*T).TI[IdxMin] = X;
    }
    else if (!IsFull(*T))
    {
        i= GetFirstIdx(*T);
        while (((*T).TI[i] < X) && (i<= GetLastIdx(*T)))
        {
            i++;
        }
        if (i > GetLastIdx(*T))
        {
            AddAsLastEl(T, X);
        }
        else
        {
            AddEli(T, X, i);
        }
    }
}

void Del1Urut(TabInt *T, ElType X)
/*	Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan
	I.S. Tabel tidak kosong
	F.S. Jika ada elemen tabel bernilai X ,
	maka banyaknya elemen tabel berkurang satu.
	Jika tidak ada yang bernilai X, tabel tetap.
	Setelah penghapusan, elemen tabel tetap kontigu!
	Proses : Search indeks ke-i dengan elemen ke-i=X.
	Delete jika ada.
*/
{
    IdxType i;
    if (SearchUrutB(*T, X))
    {
        for (i= SearchUrut(*T, X); i< GetLastIdx(*T); i++)
        {
            SetEl(T, i, GetElmt(*T, i+1));
        }
        SetEl(T, GetLastIdx(*T), ValUndef);
    }

    /*
    IdxType i;

    i= Search1(*T, X);
    if (i != IdxUndef)
    {
        DelEli(T, i, &X);
    }
    */
}

//yg proc
//T.TI[i] = X;
//InSort
//for i <= GetLastIdx; i++
//if (T.TI[i]= x)
//{T.TI[i] = valundef}
//for (state awal; kondisi; iterasi)



boolean SearchUrutB (TabInt T, ElType X)
/* { Prekondisi: Tabel boleh kosong. Jika tidak kosong, elemen terurut
    membesar. }
    { Mengirimkan true jika X ada di dalam T dan false jika X tidak ditemukan
    di T. }
*/
{
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    if (IsEmpty(T))
        return false;
    else
    {
        i= GetFirstIdx(T);
        while (i<= GetLastIdx(T) && X > T.TI[i])
        {
            i++;
        }
        if (T.TI[i] == X)
            return true;
        else
            return false;
    }
}

int SumTab (TabInt T)
/*  { Prekondisi : Tabel T tidak kosong }
    { Mengirim hasil penjumlahan semua elemen dalam T }
*/
{
    /*Kamus lokal*/
    int sum;
    IdxType i;

    /*Algoritma*/
    sum = 0;
    for (i= GetFirstIdx(T); i<= GetLastIdx(T); i++)
    {
        sum+= T.TI[i];
    }
    return sum;
}
void UpdateElmt (TabInt *T, IdxType i, ElType X)
/* { I.S. : T terdefinisi, tidak kosong.
    i merupakan indeks valid dalam T.
    X terdefinisi. }
    { F.S. : Nilai elemen T pada indeks ke-i berubah menjadi X.
    T tetap terurut membesar, sehingga ada kemungkinan dilakukan
    proses pengurutan kembali. }
    { Proses : meng-assign nilai X pada TabInt dengan indeks i. Melakukan insertion sort dengan
                memanggil InsSortAsc(T). }
*/
{
    if (IsIdxEff(*T, i))
    {
    (*T).TI[i] = X;
    InsSortAsc(T);
    }

}
void DelAllX (TabInt *T, ElType X)
/*  procedure DelAllX (input/output T : TabInt, input X : ElType)
    { I.S. : T terdefinisi, boleh kosong. X terdefinisi. }
    { F.S. : Semua elemen T yang bernilai X dihapus dari tabel penampung, jika
    X ada di T. Jika X tidak ada, T tetap. }
    { Proses : mengecek dengan while apakah X ada di T dengan function SearchUrutB, jika true, panggil fungsi Del1Urut. }
*/
{
    int n, head, tail;

    n = NbElmt(*T);
    head= SearchUrut(*T, X);
    tail = head;
    for (; tail <= IdxMax && (*T).TI[tail] == X; ++tail);
    while (tail <= n)
    {
        (*T).TI[head] = (*T).TI[tail];
        ++tail;
        ++head;
    }
    while (head<tail)
    {
        (*T).TI[head] = ValUndef;
        ++head;
    }

}

/*
    diajarin tadi bs juga yg delAll:
    while (SearchUrutB(*T, X) == true)
    {
        Del1Urut(T, X);
    }
*/
