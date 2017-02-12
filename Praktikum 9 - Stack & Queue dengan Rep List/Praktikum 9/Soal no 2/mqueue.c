#include "queue.c"

int main ()
{
	/*Kamus*/
	Queue Q;
	Infotype X;
	int N,i,waktu;
	Address P,Prec;

	/*Algoritma*/
	CreateEmpty(&Q);
	
	scanf("%d",&N);
	Infotype siswa[N-1];
	
	for (i=0;i<N;i++)
	{
		scanf("%d", M(siswa[i]));
		scanf("%d", T(siswa[i]));
		scanf("%d", A(siswa[i]));
		
		id(siswa[i]) = i+1;
		MP(siswa[i]) = A(siswa[i]);
	}
	
	waktu=1;
	Add(&Q,siswa[0]);
	i=1;
	while (N>0)
	{
		if (waktu == A(siswa[i]))
		{
			Add(&Q,siswa[i]);
			
			P = Head(Q);
			while (i>1)
			{
				if (M(siswa[i])>M(siswa[i-1]))
				{
					P = AddressDari(Q,siswa[i]);
					Prec = AddressDari(Q,siswa[i-1]);
					tukar(&Q,P,Prec);
				}
				i=i-1;
			}
			
			
		}
		
		
		if (T(InfoHead(Q))>waktu)
		{
			Del(&Q,&X);
			printf ("%d %d",id(X),(MP(X)-A(X)));
			N=N-1;
		}
		
		
		waktu = waktu+1;
		
			
		
	
	}

	
	
	
	
	
return 0;	
}
