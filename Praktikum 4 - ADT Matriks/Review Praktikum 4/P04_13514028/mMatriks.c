
#include "boolean.h"
#include <math.h>
#include <stdio.h>
#include "matriks.h"

int main() {
	indeks i,j;
	MATRIKS M;
	scanf("%d",&i);
	scanf("%d",&j);
	if ((i >= 1) && (j>=1)) { 
		BacaMATRIKS(&M,i,j);
		TulisMATRIKS(M);
		j = RataTestTertinggi(M);
		printf("Test-Max T%d Avg=%.2f\n",RataTestTertinggi(M),RataNilai(M,RataTestTertinggi(M)));
		TulisStatistikTest(M);
		TulisMatriks1(M);
	}
	
	
	return 0;
}
