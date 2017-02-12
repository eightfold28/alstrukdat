/* Nama/ NIM		: Dharma Kurnia Septialoka/ 13514028
 * Nama file		: listsirkuler.h
 * Topik		    : list sirkuler
 * Tanggal		    : 26 Oktober 2015
 * Deskripsi		: list sirkuler
*/

#include "listsirkuler.h"

Address Last(List L) {
	Address P;
	
	if (IsListEmpty(L)) {
		return Nil;
	} else {
		P= First(L);
		while (Next(P) != First(L)) {
			P= Next(P);
		}
		return P;
	}
}
/*	I.S. sembarang
	F.S. Mengirim address terakhir dari List. Jika List kosong, kembalikan Nil.
*/
 
boolean IsListEmpty (List L) {
	if (First(L) == Nil) {
		return true;
	} else {
		return false;
	}
}
/* Mengirim true jika list kosong */

void CreateList (List *L) {
	First(*L) = Nil;
}
/*	I.S. sembarang
	F.S. Terbentuk list kosong 
*/

Address Alokasi (Infotype X) {
	Address P;
	
	P= (ElmtList*) malloc(sizeof(Infotype));
	if (P == Nil) {
		return Nil;
	} 
	Next(P)= Nil;
	Info(P)= X;
	return P;
}
/*	Mengirimkan Address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka Address tidak Nil, dan misalnya menghasilkan P, maka
	Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/

void Dealokasi (Address *P) {
	free(*P);
	*P= Nil;
}
/*	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian Address P
*/

// PENCARIAN SEBUAH ELEMEN LIST
Address Search (List L, Infotype X) {
	Address P;
	boolean found;
	
	if (IsListEmpty(L)) {
		return Nil;
	} else {
		P= First(L);
		found= false;
		do {
			if (Info(P)== X) {
				found= true;
			} else {
				P= Next(P);
			}
		} while ((P!= First(L)) && (!found));
		if (!found) {
			return Nil;
		} else {
			return P;
		}
	}
}
/*	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan Address elemen tersebut
	Jika tidak ada, mengirimkan Nil
*/

boolean FSearch (List L, Address P) {
	boolean found;
	Address P1;
	
	if (IsListEmpty(L)) {
		return false;
	} else {
		found= false;
		P1= First(L);
		do {
			if (P == P1) {
				found= true;
			} else {
				P1= Next(P1);
			}
		} while ((P1!= First(L)) && (!found));
		return found;
	}
}
/*	Mencari apakah ada elemen list yang beralamat P
	Mengirimkan true jika ada, false jika tidak ada
*/

Address SearchPrec (List L, Infotype X) {
	Address P, Prec;
	boolean found;
	
	if (IsListEmpty(L)) {
		return Nil;
	} else {
		found= false;
		Prec= Nil;
		P= First(L);
		do {
			if (Info(P) == X) {
				found= true;
			} else {
				Prec= P;
				P= Next(P);
			}
		} while (P!= First(L) && !found);
	}
	if (found) {
		return Prec;
	} else {
		return Nil;
	}
}
/*	Mengirimkan Address elemen sebelum elemen yang nilainya = X
	Mencari apakah ada elemen list dengan Info(P) = X
	Jika ada, mengirimkan Address Prec, dengan Next(Prec) = P dan Info(P) = X
	Jika tidak ada, mengirimkan Nil
	Jika P adalah elemen pertama, maka mengirimkan Nil
	Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah search akan dilakukan operasi lain
*/

//PENAMBAHAN ELEMEN
void InsVFirst (List *L, Infotype X) {
	Address P;
	
	P= Alokasi(X);
	if (P!= Nil) {
		InsertFirst(L, P);
	}
}
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen pertama L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
	nilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/

void InsVLast (List *L, Infotype X) {
	Address P;
	P= Alokasi(X);
	if (P!= Nil) {
		InsertLast(L, P);
	}
}
/*	I.S. L mungkin kosong
	F.S. X ditambahkan sebagai elemen terakhir L
	Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
	elemen terakhir yang baru bernilai X jika alokasi berhasil.
	Jika alokasi gagal: I.S.= F.S.
*/

//PENGHAPUSAN ELEMEN
void DelVFirst (List *L, Infotype *X) {
	Address P;
	
	if (!IsListEmpty(*L)) {
		DeleteFirst(L, &P);
		if (P!= Nil) {
			*X= Info(P);
			Dealokasi(&P);
		}
	}
	/*
	if (!IsListEmpty(*L)) {
		P= First(*L);
		*X= Info(P);	
	}
	*/
}
/*	I.S. List L tidak kosong
	F.S. Elemen pertama list dihapus : nilai info disimpan pada X
	dan alamat elemen pertama di-dealokasi
*/

void DelVLast (List *L, Infotype *X) {
	Address P;
	
	if (!IsListEmpty(*L)) {
		DeleteLast(L, &P);
		if (P!= Nil) {
			*X= Info(P);
			Dealokasi(&P);
		}
	}
}
/*	I.S. list tidak kosong
	F.S. Elemen terakhir list dihapus : nilai info disimpan pada X
	dan alamat elemen terakhir di-dealokasi
*/

//PRIMITIF BERDASARKAN ALAMAT
//PENAMBAHAN ELEMEN BERDASARKAN ALAMAT
void InsertFirst (List *L, Address P) {
	if (IsListEmpty(*L)) {
		First(*L)= P;
		Next(P)= P;
	} else {
		Next(P)= First(*L);
		Next(Last(*L))= P;
		First(*L)= P;
	}
}
/*	I.S. Sembarang, P sudah dialokasi
	F.S. Menambahkan elemen ber-Address P sebagai elemen pertama
*/

void InsertAfter (List *L, Address P, Address Prec) {
	Next(P)= Next(Prec); //analogiin Prec sama next Prec lagi gandengan, terus karna P mau nyempil ditengah, yaudah 
	Next(Prec)= P;
}
/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir, P sudah dialokasi
	F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
*/

void InsertLast (List *L, Address P) {
	if (IsListEmpty(*L)) {
		First(*L)= P;
		Next(P)= P;
	} else {
		Next(P)= First(*L);
		Next(Last(*L))= P;
	}
}
/*	I.S. Sembarang, P sudah dialokasi
	F.S. P ditambahkan sebagai elemen terakhir yang baru
*/

//PENGHAPUSAN SEBUAH ELEMEN
void DeleteFirst (List *L, Address *P) {
	if (!IsListEmpty(*L)) {
	*P= First(*L);
	if (Next(First(*L)) == First(*L)) {
		First(*L)= Nil;
	} else {	
		Next(Last(*L)) = Next(First(*L));
		First(*L) = Next(First(*L));
	}
	Next(*P)= Nil;
	}
}
/*	I.S. List tidak kosong
	F.S. P adalah alamat elemen pertama list sebelum penghapusan
	Elemen list berkurang satu (mungkin menjadi kosong)
	First element yang baru adalah suksesor elemen pertama yang lama
*/

void DeleteP (List *L, Infotype X) {
	Address P, Prec;
	
	if (!IsListEmpty(*L)) {
		if (Info(First(*L)) == X) {
			DeleteFirst(L, &P);
			Dealokasi(&P);
		} else {
			Prec= SearchPrec(*L, X);
			if (Prec!= Nil) {
				DeleteAfter(L, &P, Prec);
				Dealokasi(&P);
			}
		}
	}
}
/*	I.S. Sembarang
	F.S. Jika ada elemen list ber-Address P, dengan Info(P) = X
	Maka P dihapus dari list dan di-dealokasi
	Jika tidak ada elemen list dengan Info(P) = X, maka list tetap
	List mungkin menjadi kosong karena penghapusan
*/

void DeleteLast (List *L, Address *P) {
	Address P1, Prec;
	
	P1= First(*L);
	Prec= Nil;
	
	while (Next(P1)!= First(*L)) {
		Prec= P1;
		P1= Next(P1);
	}
	*P= P1;
	if (Prec!= Nil) {
		Next(Prec)= First(*L);
	} else {
		First(*L)= Nil;
	}
}
/*	I.S. List tidak kosong
	F.S. P adalah alamat elemen terakhir list sebelum penghapusan
	Elemen list berkurang satu (mungkin menjadi kosong)
	Last element baru adalah predesesor elemen terakhir yang lama, jika ada
*/

void DeleteAfter (List *L, Address *Pdel, Address Prec) {
	*Pdel= Next(Prec);
	Next(Prec)= Next(Next(Prec));
}
/*	I.S. List tidak kosong. Prec adalah anggota list L. Prec bukan elemen terakhir.
	F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus
*/

//PROSES SEMUA ELEMEN LIST
void PrintInfo (List L) {
	Address P;
	
	if (IsListEmpty(L)) {
		printf("[]\n");
	} else {
		printf("[");
		P= First(L);
		do {
			printf("%d", Info(P));
			if (Next(P)!= First(L)) {
				printf(", ");
			}
			P= Next(P);
		} while (P!= First(L));
		printf("]\n");
	}
}
/*	I.S. List mungkin kosong
	F.S. Jika list tidak kosong,
	Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
	Jika list kosong, hanya menuliskan "[]"
*/

int NbElmt (List L) {
	Address P;
	int count;
	
	count= 0;
	if (!IsListEmpty(L)) {
	P= First(L);
	do {
		count++;
		P= Next(P);
	} while (P!= First(L));}
	return count;
}
/*	Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

// Prekondisi untuk Max dan Min : List tidak kosong 
Infotype Max (List L) {
	return Info(AdrMax(L));
}
/*	Mengirimkan nilai Info(P) yang maksimum */

Address AdrMax (List L) {
	Address P, PMax;
	
	if (!IsListEmpty(L)) {
		P= First(L);
		PMax= First(L);
		do {
			if (Info(PMax) < Info(P)) {
				PMax= P;
			}
			P= Next(P);
		} while (P!= First(L));
	} else {
		PMax= Nil;
	}
	return PMax;
}
/*	Mengirimkan address P, dengan Info(P) yang bernilai maksimum */

Infotype Min (List L) {
	return Info(AdrMin(L));
}
/*	Mengirimkan nilai Info(P) yang minimum */

Address AdrMin (List L) {
	Address P, PMin;
	
	if (!IsListEmpty(L)) {
		P= First(L);
		PMin= First(L);
		do {
			if (Info(PMin) > Info(P)) {
				PMin= P;
			}
			P= Next(P);
		} while (P!= First(L));
	} else {
		PMin= Nil;
	}
	return PMin;
}
/*	Mengirimkan address P, dengan Info(P) yang bernilai minimum */

double Average (List L) {
	Address P;
	double avg;
	Infotype sum;
	
	if (IsListEmpty(L)) {
		avg= 0;
	} else {
		sum= 0;
		P= First(L);
		do {
			sum += Info(P);
			P= Next(P);
		} while (P!= First(L));
		avg= (double) sum / (double) NbElmt(L);
	}
	return avg;
}
/*	Mengirimkan nilai rata-rata list L, rata-rata list kosong adalah 0 */ 

//PROSES TERHADAP LIST
void DeleteAll (List *L) {
	Address P;
	
	while (!IsListEmpty(*L)) {
		DeleteFirst(L, &P);
		Dealokasi(&P);
	}
	First(*L)= Nil;
}
/*	Delete semua elemen list dan alamat elemen di-dealokasi
	I.S. : L terdefinisi, boleh kosong
	F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi
*/

void InversList (List *L) {
	Address Pt, Pprec;
 

 	if (NbElmt(*L) > 1) {
  		DeleteLast(L, &Pt);
  		InsertFirst(L, Pt);
  		do {
   			DeleteLast(L, &Pprec);
   			InsertAfter(L, Pprec, Pt);
   			Pt = Pprec;
  		} while (Pprec != Last(*L));
 	}

	/*List L2;
	Address P;
	
	CreateList(&L2);
	while (!IsListEmpty(*L)) {
		P= First(*L);
		InsertFirst(&L2, P);
		DeleteFirst(L, &P);
	}
	CpAlokList(L2, L);

	Address P, Prec, Succ, Last;
	
	if (NbElmt(*L) >= 2) {
		Last= Last(*L);
		Prec= Last(*L);
		P= Next(Prec); //First
		Succ= Next(P); //setelah First
		
		do {
			Next(P)= Prec;
			Prec= P;
			P= Succ;
			Succ= Next(Succ);
		} while (P!= First(*L));
		First(*L)= Next(First(*L));
	}
	
	//1 2 3 4 5
	last= 5
	prec= 5
	p= 1
	succ= 2
	
	next(p)= 5
	prec= 1
	p= 2
	suc= 3
	
	next(p)= 1
	prec= 2
	p= 3
	succ= 4
	
	next(p)= 2
	*/
	
}
/*	I.S. L terdefinisi, boleh kosong
	F.S. Elemen list L dibalik :
	Elemen terakhir menjadi elemen pertama, dan seterusnya.
	Membalik elemen list, tanpa melakukan alokasi/dealokasi.
*/

List FInversList (List L) {
	List LInv;
	Address P, PInv;
	boolean fail;
	
	CreateList(&LInv);
	P= First(L);
	fail= false;
	if (!IsListEmpty(L)) {
		do {
			PInv= Alokasi(Info(P));
			if (PInv!= Nil) {
				InsertFirst(&LInv, PInv);
				P= Next(P);
			} else {
				fail= true;
			}
		} while (P!= First(L) && !fail);
	}
	if (fail) {
		DeleteAll(&LInv);
	}
	return LInv;
}
/*	Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
	Alokasi mungkin gagal. Jika alokasi gagal, hasilnya list kosong dan semua elemen
	yang terlanjur di-alokasi, harus didealokasi.
*/

void CopyList (List L1, List *L2) {
	First(*L2)= First(L1);
}
/*	I.S. L1 terdefinisi, L2 sembarang. F.S. L2 = L1
	L1 dan L2 "menunjuk" kepada list yang sama.
	Tidak ada alokasi/dealokasi elemen baru.
*/

List FCopyList (List L) {
	List LCopy;
	Address P, PCopy;
	boolean fail;
	
	CreateList(&LCopy);
	fail= false;
	P= First(L);
	if (!IsListEmpty(L)) {
		do {
			PCopy= Alokasi(Info(P));
			if (PCopy!= Nil) {
				InsertLast(&LCopy, PCopy);
				P= Next(P);
			} else { //PCopy= Nil
				fail= true;
			}
		} while (P!= First(L) && !fail);
	}
	if (fail) {
		DeleteAll(&LCopy);
	}
	return LCopy;
}
/*	Mengirimkan list yang merupakan salinan L dengan melakukan alokasi elemen baru.
	Jika ada alokasi gagal, hasilnya list kosong dan semua elemen yang terlanjur dialokasi,
	harus didealokasi.
*/

void CpAlokList (List Lin, List *Lout) {
	*Lout= FCopyList(Lin);
}
/*	I.S. Lout sembarang, Lin terdefinisi.
	F.S. Jika semua alokasi berhasil, maka Lout berisi hasil copy Lin
	Jika ada alokasi yang gagal, maka Lout = Nil dan semua elemen yang terlanjur
	dialokasi, didealokasi
*/

void Concat (List L1, List L2, List *L3) {

 	Address P, Pt;
 	boolean gagal;
 
 	CreateList(L3);
 	*L3 = FCopyList(L1);
 	P = First(L2);
 	gagal = false;
 	if (!IsListEmpty(L2)){
  		do {
   			Pt = Alokasi(Info(P));
   			if (Pt == Nil){
    				gagal = true;
   				break;
   			} else {
    				InsertLast(L3, Pt);
    				P = Next(P);
   			}
 		 } while (P != First(L2));
 	}
 	if (gagal){
  		DeleteAll(L3);
 	}
}
	/*List LCopy1, LCopy2;
	
	CpAlokList(L1, &LCopy1);
	CpAlokList(L2, &LCopy2);
	Concat1(&LCopy1, &LCopy2, L3);*/
	
	/*
	Address P2, P3;
	boolean fail;
	
	CreateList(L3);
	CpAlokList(L1, L3);
	if (!IsListEmpty(L2)) {
		fail= false;
		P2= First(L2);
		do {
			P3= Alokasi(Info(P2));
			if (P3!= Nil) {
				InsertLast(L3, P3);
				P2= Next(P2);
			} else {
				fail= true;
			}
		} while (P2!= First(L2) && !fail);
		if (fail) {
			DeleteAll(L3);
		}
	}
}
	I.S. L1 dan L2 terdefinisi, boleh kosong.
	F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 dan L2
	Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi L1 dan L2.
	Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi harus didealokasi
	dan L3 = Nil.
	Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru".
	Elemen L3 adalah hasil alokasi elemen yang "baru".
	Jika ada alokasi yang gagal, maka L3 harus bernilai Nil dan semua elemen yang
	pernah dialokasi harus didealokasi.
*/

void Concat1 (List *L1,  List *L2, List *L3) {
 	Address P, Pt;
 
 	CreateList(L3);
 	CopyList(*L1, L3);
 	P = First(*L2);
 	if (!IsListEmpty(*L2)){
  		do {
			Pt = Next(P);
   			InsertLast(L3, P);
   			P = Pt;
  		} while (P != First(*L2));
 	}
 	CreateList(L1);
 	CreateList(L2);
}


/*
	Address Last1, Last2;
	
	if (IsListEmpty(*L1)) {// L1 kosong; L2 tidak peduli kosong ataupun tidak
		*L3= *L2;
	} else if (IsListEmpty(*L2)) {//jika L1 list kosong dan L2 tidak
		*L3= *L1;
	} else { //L1 dan L2 ada isinya
		Last1= Last(*L1);
		Last2= Last(*L2);
		
		Next(Last1)= First(*L2); //lanjutan L1 ya L2
		
		Next(Last2)= First(*L1);
		*L3= *L1;
	}
	CreateList(L1);
	CreateList(L2);

	I.S. L1 dan L2 sembarang
	F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 dan L2
	Konkatenasi dua buah list: L1 dan L2 menghasilkan L3 yang baru (dengan elemen list L1 dan L2).
	L1 dan L2 menjadi list kosong.
	Tidak ada alokasi/dealokasi pada prosedur ini.
*/

void PecahList (List *L1, List *L2, List L) {
/* 	int i, nb;
 	Address P, Pt;
 	boolean gagal;
 
 	nb = (int) NbElmt(L) / 2;
 	CreateList(L1);
 	CreateList(L2);
 	i = 1;
 	gagal = false;
 	P = First(L);
 	while (i <= nb){
  		Pt = Alokasi(Info(P));
  		if (Pt == Nil){
   			gagal = true;
   			break;
  		} else {
   			InsertLast(L1, Pt);
   			P = Next(P);
  		}
  		i++;
 	}
 	if (gagal){
  		DeleteAll(L1);
 	}
 	gagal = false;
	while (i <= NbElmt(L)){
 		Pt = Alokasi(Info(P));
  		if (Pt == Nil){
   			gagal = true;
  		 	break;
  		} else {
   			InsertLast(L2, Pt);
   			P = Next(P);
  		}
  		i++;
 	}
 	if (gagal){
  		DeleteAll(L2);
 	}
}
*/

	Address P, P1;
	int i, hslbagi;
	boolean fail;
	
	CreateList(L1);
	CreateList(L2);
	i= 1;
	hslbagi= (int) NbElmt(L) / 2;
	fail= false;
	if (!IsListEmpty(L)) {
		P= First(L);
		do {
			P1= Alokasi(Info(P));
			if (P1 == Nil) {
				fail= true;
				break;
			}
			if (i<= hslbagi) {
				InsertLast(L1, P1);
			} else {
				InsertLast(L2, P1);
			}
			i++;
			P= Next(P);
		} while (P!= First(L) && !fail);
			if (fail) {
			DeleteAll(L1);
			DeleteAll(L2);
		}
	}
}
/*
	I.S. L mungkin kosong
	F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2
	L tidak berubah : untuk membentuk L1 dan L2 harus alokasi.
	L1 berisi separuh elemen L dan L2 berisi sisa elemen L.
	Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2.
	Jila alokasi gagal, semua elemen yang sudah dialokasikan harus di-dealokasi (bisa L1, L2 atau keduanya)
*/

int NbX (Infotype X, List L) {
	int count;
	Address P;
	
	count= 0;
	if (!IsListEmpty(L)) {
		P= First(L);
		do {
			if (Info(P)== X) {
				count++;
			}
			P= Next(P);
		} while (P!= First(L));
	}
	return count;
}
/* Mengirimkan jumlah kemunculan elemen bernilai X dalam list L;
mengirimkan 0 jika list kosong */

int Jarak (List L, Infotype X, Infotype Y) {
	Address P;
	Infotype Z;
	int jarak;
	boolean ketemu;
	
	jarak= 0;
	if (!IsListEmpty(L)) {
		P= First(L);
		ketemu= false;
		do {
			if (Info(P) == X || Info(P) == Y) {
				ketemu= true;
			} else {
				P= Next(P);
			}
		} while (P!= First(L) && !ketemu);
	}
	if (Info(P) == X) {
		Z= Y;
	} else {//karena X dan Y pasti ada di L, maka jika ketemu Y duluan, cari jarak ke Xnya
		Z= X;
	}
	P= Next(P);
	ketemu= false;
	do {
		if (Info(P)== Z) {
			ketemu= true;
		} else {
			jarak++;
			P= Next(P);
		}
	} while (P!= First(L) && !ketemu);
	return jarak;
}


/*
	Address j1, j2, P;
	int count;
	
	j1= Search(L, X);
	j2= Search(L, Y);
	if (Next(j1)== j2) {
		return 0;
	} else {
		count= 0;
		P= Next(j1);
		do {
			if (P != j2) {
				count++;
			}
			P= Next(P);
		} while (P!= j2); 
		return count;
	}
}
*/

/* Mengirimkan jarak (banyaknya elemen) antara elemen dengan infotype
X dan elemen dengan infotype Y (tidak termasuk elemen X dan Y
sendiri).
Jika X dan Y tepat bersebelahan, jaraknya adalah 0.
Jika ada lebih dari satu elemen X dan/atau Y di L maka digunakan
elemen X dan Y yang pertama kali ditemukan.
Urutan kemunculan X dan Y bebas, artinya X dapat muncul sebelum atau
sesudah Y. */
/* Prekondisi : X dan Y pasti berbeda dan pasti ada di L, sehingga L
tidak mungkin kosong. */

void RemAllX (List *L, Infotype X) {
	while (Search(*L, X) != Nil) {
		DeleteP(L, X);
	}
}
/* I.S. L terdefinisi, mungkin kosong */
/* F.S. Tidak ada elemen L yang bernilai X */
/* Menghapus seluruh elemen L yang bernilai X */

void SubList (List L1, int start, int count, int arah, List *L2) {
	Address P, P1;
	int i;
	boolean fail, wat;
	
	CreateList(L2);
	fail= false;
	i= 1;
	
	if (start > NbElmt(L1)) return;
	P= First(L1);
	if (!IsListEmpty(L1)) {
		wat= false;
		do {
			if (i== start) {
				wat= true;
			} else {
				i++;
				P= Next(P);
			}
		} while (P!= First(L1) && !wat);
	}
		wat= false;
		do {
			if (i== start + count) {
				wat= true;
			} else {
				P1= Alokasi(Info(P));
				if (P1== Nil) {
					fail= true; break;
				}
				if (arah== -1) {
					InsertFirst(L2, P1);
				} else {
					InsertLast(L2, P1);
				}
				i++;
				P= Next(P);
			} 
		} while (P!= First(L1) && !wat);
	
	if (fail) {
		DeleteAll(L2);
	}
}
		
	
/* I.S. L1, start, count, dan arah terdefinisi.
	start ≥ 1
	count ≥ 1
	arah bernilai 1 atau -1.
	L2 sembarang. */

/* F.S. Jika arah = 1, maka L2 berisi elemen L1 dari elemen ke-start
hingga elemen ke-(start+count-1) (sesuai urutan di L1).
Jika arah = -1, maka L2 berisi elemen L1 dari elemen
ke-(start+count-1) hingga elemen ke-start (dengan urutan
terbalik dari urutan di L1).
Setiap elemen L2 harus dialokasi sebagai elemen baru. Jika
ada elemen yang gagal dialokasi, maka L2 menjadi kosong dan
semua elemen yang sudah telanjur dialokasi harus didealokasi.
Jika start > jumlah elemen L1, L2 kosong.
Jika start ≤ jumlah elemen L1 dan (start+count-1) > jumlah
elemen L1, L2 berisi (jumlah elemen L1 – start + 1) elemen
(kurang dari count).

Urutan pada List dimulai dari 1
*/

void Rotate (List *L, int N, boolean isLeft) {
	Address P;
	int i;
	boolean stop;
	
	if (!isLeft) {
		N= NbElmt(*L)- N;
	}
	P= First(*L);
	stop= false;
	i= 1;
	if (!IsListEmpty(*L)) {
		do {
			if (i== N + 1) {
				stop= true;
			} else {
				i++;
				P= Next(P);
			}
		} while (!stop && P!= First(*L));
	}
	First(*L)= P;
}

/*	
	Address P, Pt;
	List LTemp;
	int i;

	if (!IsListEmpty(*L) && N <= NbElmt(*L)) {
		CreateList(&LTemp);
		if (isLeft) {
			CpAlokList(*L, &LTemp);
			P= First(*L);
			for (i= 1; i<= N; i++) {
				DeleteFirst(L, &P);
				P= Next(P);
			}
			Pt= First(LTemp);
			for (i= 1; i<= N; i++) {
				InsertLast(L, Pt);
				Pt= Next(Pt);
			}
		} else { //if notisleft 
			P= First(*L);
			for (i= 1; i<= (NbElmt(*L) - N); i++) {
				InsertLast(&LTemp, P);
				DeleteFirst(L, &P);
				P= Next(P);
			}
			InversList(L);
			Pt= First(*L);
			for (i= 1; i<= N; i++) {
				InsertFirst(&LTemp, Pt);
				Pt= Next(Pt);
			}
			CpAlokList(LTemp, L);
		}
	}
}

				
				
	
	
	if (N <= NbElmt(*L) {
		CreateList(LTemp);
		if (isLeft) {
			P= First(*L);
			i= 1;
			for (i= 1; i<= N; i++) {
				InsertLast(&LTemp, P);
				DeleteFirst(L, &P);
				i++;
				P= Next(P);
			}
			P= First(LTemp);
			for (i= 1; i<= N; i++) {
				InsertLast(L, P);
				i++;
				P= Next(P);
			}
		} else { //if not isleft
			LCopy= FCopyList(*L);
			DeleteAll(L);
			P= First(LCopy);
			i= 1;
			for (i= 1; i<= N; i++) {
				InsertFirst(&LTemp, P);
				DeleteLast(LCopy, &P);
				i++;
				P= Next(P);
			}
			P= First(LTemp);
			for (i= 1; i<= N; i++) {
				InsertFirst(L, P);
				i++;
				P= Next(P);
			}
			
		}
		
3 5 7 9 11
buat list baru masukkin inslast 3 5 lalu sambil delete
7 9 11 pake ins last jd 7 9 11 3 5

9 11 3 5 7
buat list baru pake insfirst 9 11 lalu sambil delete last
kan ltemp jd 9 11
lalu inslast ke L

cpaloklist(L, Ltemp);
P= First(L)
for (i= 1 sd N)
	deletefirst(L, P)
	P= next(P);
	
	P= First Ltemp;
lalu for i=1 sd N
	
	terus insertlast (L, P)
	P= Next(P);
	
//kalo yg false
create ltemp;
P= First(L)
for i= 1 sd nbelmt-N
	insertlast(Ltemp, P)
	//deletefirst(L, P)
	P= nextP;
	i++
	
	
	invers si L
	P= first L
for i=1 sd N
	insertfirst ke Ltemp
	P= nextP;
	i++
	
	
*/

				
				
/* I.S. L terdefinisi, mungkin kosong */
/* F.S. Jika isLeft = true: */
/* N buah elemen terdepan L dipindah ke belakang. 
Elemen ke-N+1 pada L awal menjadi First(L) yang baru. 
Jika isLeft = false: 
N buah elemen terbelakang L dipindah ke depan. */
/*
 Elemen ke-N dari belakang pada L awal menjadi First(L) yang baru. */
/*
 Jika N lebih besar dari jumlah elemen L, L tetap */
/* Contoh: Rotate([3,5,7,9,11],2,true) -> L = [7,9,11,3,5]
 Rotate([3,5,7,9,11],2,false) -> L = [9,11,3,5,7] */



