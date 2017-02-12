#include "listlinier.h"
void PrintAddress(List l);

int main()
{
    int i,n,x;
    Infotype X;
    Address p,p1, septi;
    List L,L1,L2,Lout;

    CreateList(&L);
    /*printf("Masukkan n\n");
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
        scanf("%d",&x);
        InsertLast(&L,Alokasi(x));
    }
    PrintInfo(L);
    PrintAddress(L);
    printf("NbElmt = %d\n",NbElmt(L));
    printf("\n");

    printf("Min = %d | Max = %d\n",Min(L),Max(L));
    printf("\n");s

    printf("info(Addr Min) = %d | info(Addr Max) = %d\n",Info(AdrMin(L)), Info(AdrMax(L)));

    printf("IsEmpty = %d\n",IsListEmpty(L));
    printf("Search = "); */
    
    n =5;
    for (i=1; i <= 10; i++) {
    	//InsVFirst(&L, n);
    	InsVLast(&L, n);
    	n = n+ 5;
    }
    PrintInfo(L);
    
    scanf("%d",&x);
    septi = Search(L,x);
    DeleteAfter(&L, &p, septi);
    PrintInfo(L);
    return 0;
}
    /*printf("%x\n", septi);
    printf("\n");
    printf("Alokasi 10\n");
    p = Alokasi(10);
    printf("%d, Info = %d\n",p,Info(p));
    InsertLast(&L,p);
    PrintInfo(L);
    printf("FSearch(p) = %d\n",FSearch(L,p));

    printf("\n");
    printf("Alokasi 5\n");

    p = Alokasi(5);
    PrintInfo(L);
    printf("%d, Info = %d\n",p,Info(p));
    printf("FSearch(p) = %d\n",FSearch(L,p));

    printf("\n");
    PrintInfo(L);
    PrintAddress(L);
    printf("SearchPrec(10) = %d\n",SearchPrec(L,10));
    printf("\n");
    if (IsListEmpty(L) == false)
    {

        DeleteLast(&L,&p);
        printf("DeleteLast = %d, %d\n",Info(p),p);
        PrintInfo(L);
        printf("\n");
        if(IsListEmpty(L) == false)
        {
            DeleteFirst(&L,&p);
            printf("DeleteFirst = %d, %d\n",Info(p),p);
            PrintInfo(L);
            printf("\n");
        }
    };

    printf("InsertFirst 100\n");
    InsVFirst(&L,100);
    PrintInfo(L);
    printf("DeleteAfter 100\n");
    p = First(L);
    DeleteAfter(&L,&p1,p);
    PrintInfo(L);
    PrintAddress(L);
    printf("Yang didelete = %d\n",Info(p1));
    printf("\n");

    printf("DeleteP 3\n");
    DeleteP(&L,3);
    PrintInfo(L);
    PrintAddress(L);
    printf("\n");

    printf("InsVLast 25\n");
    InsVLast(&L,25);
    PrintInfo(L);
    PrintAddress(L);
    printf("\n");

    printf("DelVFirst");
    DelVFirst(&L,&x);
    printf("x = %d\n",x);
    PrintInfo(L);
    PrintAddress(L);
    printf("\n");

    printf("DelVLast");
    DelVLast(&L,&x);
    printf("x = %d\n",x);
    PrintInfo(L);
    PrintAddress(L);
    printf("\n");

    printf("Invers\n");
    InversList(&L);
    PrintInfo(L);

    printf("Invers F \n");
    PrintInfo(FInversList(L));
    printf("\n");

    printf("Copy\n");
    CopyList(L,&L1);
    PrintInfo(L1);
    printf("FCopy\n");
    PrintInfo(FCopyList(L));
    printf("CpAlok\n");
    CpAlokList(L,&L1);
    PrintInfo(L1);
    printf("\n");

    printf("Concat\n");
    Concat(L,L1,&Lout);
    PrintInfo(Lout);

    printf("Pecah\n");
    PecahList(&Lout,&L2,Lout);
    PrintInfo(Lout);
    PrintInfo(L2);
    return 0;
}

void PrintAddress(List L)
{
    Address p;
    printf("[");
    if (IsListEmpty(L) == false) {
        p = First(L);
        while(p != Nil)
        {
            printf("%d",p);
            if (Next(p) != Nil)
                printf(", ");
            p = Next(p);
        }
    }
    
    
    printf("]\n");
}
*/
