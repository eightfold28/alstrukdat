#include "listlinier.h"

int main () {
	List L1, L2, L3, L4;
	Infotype a, b, c;
	Address P, P1;
	int i;
	boolean found;
	
	CreateList(&L1);
	PrintInfo(L1);
	
	a= 10;
	for (i= 0; i<= 10; i++) {
		InsVLast(&L1, a);
		a += 10;
	}
	PrintInfo(L1);
	
	InsVFirst(&L1, 200);
	//DeleteLast(&L1, &P);
	//DeleteFirst(&L1, &P);
	P= Search(L1, 50);
	//DeleteAfter(&L1, &P1, P);
	//DelVLast(&L1, &c);
	//DelVFirst(&L1, &c);
	//P= SearchPrec(L1, 10);
	//DeleteP(&L1, 50);
	//c= NbElmt(L1);
	//c= Max(L1);
	//c= Min(L1);
	//P= AdrMax(L1);
	//P= AdrMin(L1);
	//DeleteAll(&L1);
	//CopyList(L1, &L2);
	//InversList(&L1);
	//printf("c: %d\n", c);
	//printf("P: %x\n", P);
	//L2= FCopyList(L1);
	PrintInfo(L1);
	//PrintInfo(L2);
	

	return 0;
}
