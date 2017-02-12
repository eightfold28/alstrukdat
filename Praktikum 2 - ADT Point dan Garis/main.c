#include "ADT_TABEL_KONTIGU.h"

int main()
{

	TabInt T1;
	TabInt T2;
	int i;
	int X;
	
	MakeEmpty(&T1);
	MakeEmpty(&T2);
	
	/*
	for (i = IdxMin; i <= IdxMax; i++)
	{
		printf("%d\n",(T1).TI[i]);
	}
	*/
	
	(T1).TI[96] = 1;
	(T1).TI[97] = 2;
	(T1).TI[98] = 2;
	(T1).TI[99] = 2;
	(T1).TI[100] = 1;
	
	//printf("%d\n",NbElmt(T1));
	//printf("%d\n",MaxNbEl(T1));
	//printf("%d\n",GetFirstIdx(T1));
	//printf("%d\n",GetLastIdx(T1));
	//printf("%d\n",GetElmt(T1,99));
	
	/*
	SetTab(T1,&T2);
	for (i = IdxMin; i <= IdxMax; i++)
	{
		printf("%d\n",(T2).TI[i]);
	}
	*/
	
	/*
	SetEl(&T1,99,2);
	printf("%d\n",(T1).TI[99]);
	*/
	
	//printf("%d\n",IsIdxValid(T1,98));
	//printf("%d\n",IsIdxEff(T1,98));
	//printf("%d\n",IsEmpty(T1));
	//printf("%d\n",IsFull(T1));
	
	
	/*
	BacaIsi(&T2);
	for (i = GetFirstIdx(T2); i <= GetLastIdx(T2); i++)
	{
		printf("%d\n",(T2).TI[i]);
	}
	*/
	
	//TulisIsi(T1);
	//TulisIsiTab(T2);
	
	//(T2).TI[99] = 1;
	//(T2).TI[100] = 1;
	
	//TulisIsiTab(PlusTab(T1,T2));
	//TulisIsiTab(MinusTab(T1,T2));
	//TulisIsiTab(KaliTab(T1,T2));
	//TulisIsiTab(KaliKons(T1,3));
	
	//printf("%d\n",IsEQ(T1,T2));
	
	//(T2).TI[99] = 2;
	//(T2).TI[100] = 3;
	//printf("%d\n",IsLess(T1,T2));
	
	printf("%d\n",Search1(T1,2));
	//printf("%d\n",Search2(T1,1));
	//printf("%d\n",SearchB(T1,1));
	//printf("%d\n",SearchSentinel(T1,1));
	//printf("%d\n",ValMax(T1));
	//printf("%d\n",ValMin(T1));
	//printf("%d\n",IdxMaxTab(T1));
	//printf("%d\n",IdxMinTab(T1));
	
	/*
	TulisIsiTab(T2);
	CopyTab(T1,&T2);
	TulisIsiTab(T2);
	TulisIsi(T2);
	*/
	
	/*
	T2 = InverseTab(T1);
	TulisIsiTab(T2);
	TulisIsi(T2);
	*/
	
	//printf("%d\n",IsSimetris(T1));
	
	/*
	MaxSortDesc(&T1);
	TulisIsiTab(T1);
	TulisIsi(T1);
	*/
	
	/*
	InsSortAsc(&T1);
	TulisIsiTab(T1);
	TulisIsi(T1);
	*/
	
	/*
	AddAsLastEl(&T1,3);
	TulisIsi(T1);
	*/
	
	/*
	AddEli(&T1,0,98);
	TulisIsi(T1);
	*/
	
	/*
	DelLastEl(&T1,&X);
	printf("%d\n",X);
	
	*/
	
	/*
	DelEli(&T1,98,&X);
	TulisIsi(T1);
	*/
	
	/*
	AddElUnik(&T1,2);
	TulisIsi(T1);
	*/
	
	//printf("%d\n",SearchUrut(T1,3));
	
	//printf("%d\n",(MaxMin(T1)).maks);
	//printf("%d\n",(MaxMin(T1)).min);
	
	/*
	Add1Urut(&T1,0);
	TulisIsi(T1);
	*/
	
	/*
	Del1Urut(&T1,1);
	TulisIsi(T1);
	*/
	
	return 0;
}
