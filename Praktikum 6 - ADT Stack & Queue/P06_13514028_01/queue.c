//
//  queue.c
//  
//
//  Created by Dharma Kurnia Septialoka on 10/5/15.
//
//

#include "queue.h"

//pemeriksaan kondisi queue
boolean IsEmpty(Queue Q) {
/*	Mengirim true jika Q kosong yaitu HEAD dan TAIL sama dengan nil */
    return ((GetHead(Q) == Nil) && (GetTail(Q) == Nil));
}

boolean IsFull(Queue Q) {
/*	Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung MaxEl elemen */
    return (NbElmt(Q) == GetMax(Q));
}

int NbElmt(Queue Q) {
/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)) {
        return 0;
    } else if ((GetTail(Q) >= GetHead(Q))) {
        return (GetTail(Q) - GetHead(Q) + 1);
    } else {
        return (GetMax(Q) - GetHead(Q) + 1 + GetTail(Q));
    }
}
//konstruktor
void CreateEmpty(Queue *Q, int max) {
/*	I.S. Max terdefinisi
	F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
	Jika alokasi berhasil, tabel memori dialokasi berukuran Max
	atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0
	Proses : Melakukan alokasi memori dan membuat sebuah Q kosong
 */
    (*Q).T = (Infotype *) malloc ((max + 1) * sizeof(Infotype));
    if ((*Q).T != NULL) {
        GetMax(*Q) = max;
        GetHead(*Q) = Nil;
        GetTail(*Q) = Nil;
    } else {
        GetMax(*Q) = Nil;
    }
}

//destruktor
void Dealokasi(Queue *Q) {
/*	Proses : Mengembalikan memori Q
	I.S. Q pernah dialokasi
	F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) juga diset 0
 Head dan Tail diset menjadi Nil
 Jangan lupa untuk membebaskan (free) memori yang telah dialokasikan untuk tabel
 */
    GetMax(*Q) = 0;
    GetHead(*Q) = Nil;
    GetTail(*Q) = Nil;
    free ((*Q).T);
}

//operator-operator dasar queue
void Add(Queue *Q, Infotype x) {
/*	Proses : Menambahkan X pada Q dengan aturan FIFO
	I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh
	F.S. X menjadi TAIL yang baru, TAIL "maju".
	Jika TAIL baru = MaxEl + 1, maka TAIL diset = 1.
 */
	int i ,j, k;

    if(IsEmpty(*Q)) {
        GetHead(*Q) = 1;
        GetTail(*Q) = 1;
        InfoTail(*Q) = x;
    }
    else {
        // teknik insertion sort
       i = GetTail(*Q);
       if (GetTail(*Q) < GetHead(*Q))
           i += GetMax(*Q);
       while( i >= GetHead(*Q) ) {
           j = i;
           k = i + 1;
           if(j > GetMax(*Q))
              j -= GetMax(*Q);
           if(k > GetMax(*Q))
              k -= GetMax(*Q);
           (*Q).T[k] = (*Q).T[j];
           if((i == GetHead(*Q)) && ((*Q).T[j].prio < x.prio)) {
			  (*Q).T[j] = x;
                break;
           }
           else if((*Q).T[j].prio < x.prio) 
                i --;
           else {
                (*Q).T[k] = x;
                break;
           }
        }
        GetTail(*Q)++;
        if(GetTail(*Q) == GetMax(*Q) + 1)
            GetTail(*Q) = 1;
    }
}


void Del(Queue *Q, Infotype *X) {
/*	Proses : Menghapus elemen pertama pada Q dengan aturan FIFO
	I.S. Q tidak kosong
	F.S. X = nilai elemen HEAD pada I.S.,
	Jika Queue masih isi : HEAD "maju".
	Jika HEAD baru menjadi MaxEl + 1, maka HEAD diset = 1;
	Jika Queue menjadi kosong, HEAD = TAIL = Nil.
 */
    *X= InfoHead(*Q);
    if (NbElmt(*Q) == 1) {
        GetHead(*Q) = Nil;
        GetTail(*Q) = Nil;
    } else if (GetHead(*Q) == GetMax(*Q)) {
        GetHead(*Q) = 1;
    } else {
        GetHead(*Q) ++;
    }
}
