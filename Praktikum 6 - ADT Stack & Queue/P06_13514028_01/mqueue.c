/* 
*	NIM/Nama 	: 13514028/ Dharma Kurnia Septialoka
*	Nama file 	: mqueue.c
*	Topik 		: Queue
*	Tanggal 	: 8 Oktober 2015
*	Deskripsi 	: Queue
*/


#include "queue.h"
#include <stdio.h>

void PrintQueue (Queue Q) {
	int i, j;
	if (IsEmpty(Q)) {
		printf("#\n");
	}
	else if (GetTail(Q) < GetHead(Q)) {
		GetTail(Q) += (GetMax(Q));
	} else {
		for (i= GetHead(Q); i<= GetTail(Q); i++) {
			j= i;
			if (j > GetMax(Q)) {
				j = j - GetMax(Q);
			}
			printf("%d %d\n", Q.T[j].prio, Q.T[j].nilai);
		}
    }
}
		

int main() {
	int N, i;
	Infotype x;
	Queue Q;
	
	
	scanf("%d", &N);
	CreateEmpty (&Q, N);
	for (i= 1; i<= N; i++) {
		scanf("%d %d", &x.prio, &x.nilai);
		Add(&Q, x);
	}
	PrintQueue(Q);
	return 0;
}
