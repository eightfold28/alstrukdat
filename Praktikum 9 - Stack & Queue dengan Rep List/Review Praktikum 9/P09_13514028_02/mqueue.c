#include "queue.h"

int main() {
	Queue Q, Q1, Q2, Q3;
	Infotype X;
	int M, T, A, N, i;

	CreateEmpty(&Q);
	scanf("%d", &N);
	for (i= 1; i<= N; i++) {
		scanf("%d %d %d", &M, &T, &A);
		X.nilaiMath= M;
		X.lamaPelayanan= T;
		X.waktuKedatangan= A;
		X.mulaiPelayanan= 0;
		X.id= i; //urutan kedatangan dmn input slalu terurut
		Add(&Q, X);
	}

	for (i= 1; i<= N; i++) {
		Del(&Q, &X);
		printf("%d %d\n", X.id, X.mulaiPelayanan);
	}


	return 0;
}
