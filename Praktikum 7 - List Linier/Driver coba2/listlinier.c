/* Nama/ NIM		: Dharma Kurnia Septialoka/ 13514028
 * Nama file		: listlinier.h
 * Topik		    : List Linier
 * Tanggal		    : 13 Oktober 2015
 * Deskripsi		: realisasi ADT List Linier
*/

#include "listlinier.h"

boolean IsListEmpty (List L)
/* Mengirim true jika list kosong */
{
    if (First(L) == Nil) {
        return true;
    }
    else {
        return false;
    }
}

void CreateList (List *L)
/*	I.S. sembarang
	F.S. Terbentuk list kosong
*/
{
    First(*L) = Nil;
}

Address Alokasi (Infotype X)
/*	Mengirimkan Address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka Address tidak Nil, dan misalnya menghasilkan P, maka
	Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/
{
    Address P;
    P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P!= Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (Address *P)
/*	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian Address P
*/
{
    free(*P);
}

// PENCARIAN SEBUAH ELEMEN LIST
Address Search (List L, Infotype X)
/*	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan Address elemen tersebut
	Jika tidak ada, mengirimkan Nil
*/
{
    Address P;
    boolean found;

    P = First(L);
    found = false;
    while ((P != Nil) && (!found)) {
        if (Info(P) == X) {
            found = true;
        }
        else {
            P = Next(P);
        }
    }
    return P;
}

boolean FSearch (List L, Address P)
/*	Mencari apakah ada elemen list yang beralamat P
	Mengirimkan true jika ada, false jika tidak ada
*/
{
    boolean found;
    Address P1;

    P1 = First(L);
    found = false;
    while ((P1 != Nil) && (!found)) {
        if (P1 == P) {
            found = true;
        }
        else {
            P1 = Next(P1);
        }
    }
    return found;
}

Address SearchPrec (List L, Infotype X)
/*	Mengirimkan Address elemen sebelum elemen yang nilainya = X
	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan Address Prec, dengan Next(Prec) = P dan Info(P) = X
	Jika tidak ada, mengirimkan Nil
	Jika P adalah elemen pertama, maka mengirimkan Nil
	Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah
	Search akan dilakukan operasi lain
*/
{
    Address Prec, P;
    boolean found;

    Prec = Nil;
    P = First(L);
    while ((P != Nil) && (!found)) {
        if (Info(P) == X) {
            found = true;
        }
        else {
            Prec = P;
            P = Next(P);
        }
    }
    if (found) {
        return Prec;
    }
    else {
        Prec = Nil;
        return Prec;
    }
}

//PENAMBAHAN ELEMEN
void InsVFirst (List *L, Infotype X)
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen pertama L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
	nilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/
{
    Address P;

    P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, Infotype X)
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen terakhir L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
	elemen terakhir yang baru bernilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/
{
    Address P;

    P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L,P);
    }
}

//PENGHAPUSAN ELEMEN
void DelVFirst (List *L, Infotype *X)
/*	I.S. List L tidak kosong
	F.S. Elemen pertama list dihapus : nilai info disimpan pada X
	dan alamat elemen pertama di-dealokasi
*/
{
    Address P;

    DeleteFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, Infotype *X)
/*	I.S. list tidak kosong
	F.S. Elemen terakhir list dihapus : nilai info disimpan pada X
	dan alamat elemen terakhir di-dealokasi
*/
{
    Address P;

    DeleteLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

//PRIMITIF BERDASARKAN ALAMAT
//PENAMBAHAN ELEMEN BERDASARKAN ALAMAT
void InsertFirst (List *L, Address P)
/*	I.S. Sembarang, P sudah dialokasi
	F.S. Menambahkan elemen ber-Address P sebagai elemen pertama
*/
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, Address P, Address Prec)
/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
	P sudah dialokasi
	F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
*/
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, Address P)
/*	I.S. Sembarang, P sudah dialokasi
	F.S. P ditambahkan sebagai elemen terakhir yang baru
*/
{
    Address last;

    if (IsListEmpty(*L)) {
        InsertFirst(L, P);
    }
    else {
        last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}

//PENGHAPUSAN SEBUAH ELEMEN
void DeleteFirst (List *L, Address *P)
/*	I.S. List tidak kosong
	F.S. P adalah alamat elemen pertama list sebelum penghapusan
	Elemen list berkurang satu (mungkin menjadi kosong)
	First element yang baru adalah suksesor elemen pertama yang lama
*/
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DeleteP (List *L, Infotype X)
/*	I.S. Sembarang
	F.S. Jika ada elemen list ber-Address P, dengan Info(P) = X
	Maka P dihapus dari list dan di-dealokasi
	Jika tidak ada elemen list dengan Info(P) = X, maka list tetap
	List mungkin menjadi kosong karena penghapusan
*/
{
    Address P, Prec, Pdel;
    boolean found;

    P = First(*L);
    Prec = Nil;
    found = false;
    while ( (P != Nil) && (!found) ) {
        if (Info(P) == X) {
            found = true;
        }
        else {
            Prec = P;
            P = Next(P);
        }
    }
    if (found == true) {
        if (Prec == Nil) { // X merupakan elemen pertama
            DeleteFirst(L, &Pdel);
            Dealokasi(&Pdel);
        }
        else {  // X bukan merupkan elemen pertama
            DeleteAfter(L, &Pdel, Prec);
            Dealokasi(&Pdel);
        }
    }
}

void DeleteLast (List *L, Address *P)
/*	I.S. List tidak kosong
	F.S. P adalah alamat elemen terakhir list sebelum penghapusan
	Elemen list berkurang satu (mungkin menjadi kosong)
	Last element baru adalah predesesor elemen pertama yang lama, jika ada

	CATATAN
	P adalah parameter Input/Output
*/
{
    Address last, precLast;

    last = First(*L);
    precLast = Nil;
    while (Next(last) != Nil) {
        precLast = last;
        last = Next(last);
    }
    if (precLast == Nil) {
        DeleteFirst(L, P);
    }
    else {
        DeleteAfter(L, P, precLast);
    }
}

void DeleteAfter (List *L, Address *Pdel, Address Prec)
/*	I.S. List tidak kosong. Prec adalah anggota list L.
	F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus
*/
{
    Address P;
    boolean found;

    P = First(*L);
    found = false;
    while ((P != Nil) && (!found)) {
        if (P == Prec) {
            found = true;
        }
        else {
            P = Next(P);
        }
    }

    *Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(*Pdel) = Nil;
}

//PROSES SEMUA ELEMEN LIST
void PrintInfo (List L)
/*	I.S. List mungkin kosong
	F.S. Jika list tidak kosong,
	Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
	Jika list kosong, hanya menuliskan "[]"
*/
{
    Address P;

    if (IsListEmpty(L)) {
        printf("[]\n");
    }
    else { // list berisi
        P = First(L);
        printf("[%d", Info(P));
        P = Next(P);
        while (P != Nil) {
            printf(", %d", Info(P));
            P = Next(P);
        }
        printf("]\n");
    }
}

int NbElmt (List L)
/*	Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count;
    Address P;

    count = 0;
    P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }

    return count;
}

// Prekondisi untuk Max/Min/rata-rata : List tidak kosong
Infotype Max (List L)
/*	Mengirimkan nilai Info(P) yang maksimum */
{
    Infotype maks;
    Address P;

    maks = Info(First(L));
    P = Next(First(L));
    while (P != Nil) {
        if (maks < Info(P)) {
            maks = Info(P);
        }
        P = Next(P);
    }
    return maks;
}

Address AdrMax (List L)
/*	Mengirimkan address P, dengan Info(P) yang bernilai maksimum */
{
	Address lalala;
    lalala = Search(L, Max(L));
    return lalala;
}

Infotype Min (List L)
/*	Mengirimkan nilai Info(P) yang minimum */
{
    Infotype mins;
    Address P;

    mins = Info(First(L));
    P = Next(First(L));
    while (P != Nil) {
        if (mins > Info(P)) {
            mins = Info(P);
        }
        P = Next(P);
    }
    return mins;
}

Address AdrMin (List L)
/*	Mengirimkan address P, dengan Info(P) yang bernilai minimum */
{
    Address min;
    min = Search(L, Min(L));
    return min;
}

//PROSES TERHADAP LIST
void DeleteAll (List *L)
/*	Delete semua elemen list dan alamat elemen di-dealokasi
	I.S. : L terdefinisi, boleh kosong
	F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi
*/
{
    Address P;

    while (IsListEmpty(*L) == false) {
        DeleteFirst(L, &P);
        Dealokasi(&P);
    }
}

void InversList (List *L)
/*	I.S. L terdefinisi, boleh kosong
	F.S. Elemen list L dibalik :
	Elemen terakhir menjadi elemen pertama, dan seterusnya.
	Membalik elemen list, tanpa melakukan alokasi/dealokasi.
*/
{
    Address P, Prec, Last;

    P = First((*L));
    Prec = Nil;

    while (P != Nil) {
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    First(*L) = Last;
}

List FInversList (List L)
/*	Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
	Alokasi mungkin gagal. Jika alokasi gagal, hasilnya list kosong dan semua elemen
	yang terlanjur di-alokasi, harus didealokasi.
*/
{
    List L1;

    CpAlokList(L, &L1);
    InversList(&L1);

    return L1;
}

void CopyList (List L1, List *L2)
/*	I.S. L1 terdefinisi, L2 sembarang. F.S. L2 = L1
	L1 dan L2 "menunjuk" kepada list yang sama.
	Tidak ada alokasi/dealokasi elemen baru.
*/
{
    First(*L2) = First(L1);
}

List FCopyList (List L)
/*	Mengirimkan list yang merupakan salinan L dengan melakukan alokasi elemen baru.
	Jika ada alokasi gagal, hasilnya list kosong dan semua elemen yang terlanjur dialokasi,
	harus didealokasi.
*/
{
    List L1;
    Address P, P1;
    boolean gagal;

    P = First(L);
    gagal = false;
    CreateList(&L1);
    while ((P != Nil) && (!gagal)) {
        P1 = Alokasi(Info(P));
        if (P1 != Nil) {
            InsertLast(&L1, P1);
            P = Next(P);
        }
        else { // alokasi gagal
            gagal = true;
            DeleteAll(&L1);
        }
    }
    return L1;
}

void CpAlokList (List Lin, List *Lout)
/*	I.S. Lout sembarang, Lin terdefinisi.
	F.S. Jika semua alokasi berhasil, maka Lout berisi hasil copy Lin
	Jika ada alokasi yang gagal, maka Lout = Nil dan semua elemen yang terlanjur
	dialokasi, didealokasi
*/
{
    *Lout = FCopyList(Lin);
}

void Concat (List L1, List L2, List *L3)
/*	I.S. L1 dan L2 terdefinisi, boleh kosong.
	F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 dan L2
	Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi L1 dan L2.
	Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi harus didealokasi
	dan L3 = Nil.
	Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru".
	Elemen L3 adalah hasil alokasi elemen yang "baru".
	Jika ada alokasi yang gagal, maka L3 harus bernilai Nil dan semua elemen yang
	pernah dialokasi harus didealokasi.
*/
{
    Address last;

    if (IsListEmpty(L1) == true) {
        CpAlokList(L2, L3);
    }
    else {
        CpAlokList(L1, L3);
        last = First(*L3);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = First(L2);
    }
}

void PecahList (List *L1, List *L2, List L)
/*	I.S. L mungkin kosong
	F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2
	L tidak berubah : untuk membentuk L1 dan L2 harus alokasi.
	L1 berisi separuh elemen L dan L2 berisi sisa elemen L.
	Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2.
	Jila alokasi gagal, semua elemen yang sudah dialokasikan harus di-dealokasi (bisa L1, L2 atau keduanya)
*/
{
    int i;
    Address(P);

    CpAlokList(L, L1);
    CpAlokList(L, L2);
    if ((NbElmt(L) % 2) == 1) { // ganjil
        for (i=1; i<= ((NbElmt(L) + 1) /2); i++) {
            DeleteLast(L1, &P);
        }
        for (i=1; i<= ((NbElmt(L) - 1) /2); i++) {
            DeleteFirst(L2, &P);
        }
    }
    else {
        for (i=1; i<= ((NbElmt(L)) /2); i++) {
            DeleteLast(L1, &P);
            DeleteFirst(L2, &P);
        }
    }
}
