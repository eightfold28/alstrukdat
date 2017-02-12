#include "listsirkuler.c"

int main()
{
    List L, L2, L3;
    Infotype X;
    Address a;
    int jar, jlh;

    CreateList(&L);
    CreateList(&L2);
    InsVLast(&L, 0);
    InsVLast(&L, 2);
    
   
    InsVLast(&L, 3);
    InsVFirst(&L, 10);
	 
    InsVFirst(&L, 1);
    InsVLast(&L, 8);
    InsVFirst(&L, 10);
    DelVFirst(&L, &X);
    InsVFirst(&L, 10);
    InsVLast(&L, 2);
    InsVFirst(&L, 10);
    PrintInfo(L);
    Rotate(&L, 3, false);
    PrintInfo(L);
    SubList(L, 2, 5, -1, &L2);
    PrintInfo(L2);
    jar= Jarak(L, 0, 2);
    jlh= NbX(5, L);
    printf("%d %d\n", jar, jlh);
    CreateList(&L3);
    RemAllX(&L3, 2);
    PrintInfo(L3);
    

	//printf("%d\n", SearchPrec(L, 8));
	//DeleteP(&L, 8);
    /*DeleteFirst(&L, &a);
    DeleteFirst(&L, &a);
    DeleteFirst(&L, &a);
    DeleteFirst(&L, &a);
    DeleteFirst(&L, &a);
    DeleteFirst(&L, &a);
    DeleteFirst(&L, &a); */
	
	/*
	PecahList(&L2, &L3, L);
    PrintInfo(L);
    PrintInfo(L2);
    PrintInfo(L3);
    
    Concat1(&L2, &L3, &L);
    PrintInfo(L);
    printf("%f\n", Average(L));
    

    printf("%d\n\n", NbElmt(L));

    printf("%d\n", Max(L));
    printf("%d\n", Min(L));

    DelVFirst(&L, &X);
    printf("%d\n\n", X);

    DelVLast(&L, &X);
    printf("%d\n\n", X);

    DeleteLast(&L, &a);
    printf("%d\n", Info(a));
*/
    

    return 0;
}
