#include "pohon.h"
#include "listrekursif.h"
#include "mesinkar.h"
#include <math.h>

int main(){
	BinTree P;
	Infotype X, temp;
		
	int max (int X, int Y){
		if (X > Y) {
			return X;
		} else {
			return Y;
		}
	}
	
	int Tinggi (BinTree P) {
		if (IsTreeEmpty(P)) {
			return 0;
		} else {
			return 1 + max(Tinggi(Right(P)), Tinggi(Left(P)));
		}
	}
	
	BinTree SearchPrec (BinTree P, Infotype X) {
		if (!SearchTree(P, X)) {
			return Nil;
		} else if (IsTreeEmpty(P) || IsOneElmt(P)) {
			return Nil;
		} else {
			if (IsUnerRight(P)) {
				if (Akar(Right(P)) == X) {
					return P;
				} else {
					return SearchPrec(Right(P), X);
				}	
			} else if (IsUnerLeft(P))  {
				if (Akar(Left(P)) == X){
					return P;
				} else {
					return SearchPrec(Left(P), X);
				}
			} else if (IsBiner(P)){
				if ((Akar(Left(P)) == X) || (Akar(Right(P)) == X)) {
					return P;
				} else {
					if (SearchTree(Right(P), X)){
						return SearchPrec(Right(P), X);
					} else {
						return SearchPrec(Left(P), X);
					}
				}
			} else {
				return Nil;
			}
		}
	}
	
	BinTree SearchBinTree (BinTree P, Infotype X) {
		if (IsTreeEmpty(P)) {
			return Nil;
		} else if (Akar(P) == X) {
			return P;
		} else {
			if (SearchTree(Left(P), X)) {
				return SearchBinTree(Left(P), X);
			} else {	
				return SearchBinTree(Right(P), X);
			}
		}
	}
	
	START();
	BuildTree(&P);
	getchar();
	scanf("%c", &X);
	// Baris 1
	printf("%d\n", NbElmt(P));
	// Baris 2
	PrintPreorder(P);
	printf("\n");
	// Baris 3
	if (IsTreeEmpty(P)) {
		printf("\n");
	} else {
		Printlist(MakeListDaun(P));
	}
	// Baris 4
	if (IsTreeEmpty(P)) {
		printf("true\n");
	} else if ((abs(Tinggi(Left(P)) - Tinggi(Right(P))) <= 1)){
		printf("true\n");
	} else {
		printf("false\n");
	}
	// Baris 5
	if (SearchTree(P, X)) {
		BinTree Pt1 = SearchBinTree(P, X);
		if (IsOneElmt(Pt1)){
			printf("true\n");
		} else {
			printf("false\n");
		}
	} else {
		printf("false\n");
	}
	// Baris 6
	if (SearchTree(P, X)) {
		printf("%d\n", Level(P, X));
	} else {
		printf("%d\n", -1);
	}
	// Baris 7
	if (SearchTree(P, X)) {
		BinTree Pt = SearchPrec(P, X);
		if (Pt != Nil){
			if (IsBiner(Pt)) {
				if (Akar(Right(Pt)) == X){
					printf("%c\n", Akar(Left(Pt)));
				} else {
					printf("%c\n", Akar(Right(Pt))); 
				}
			} else {
				printf("\n");
			}
		} else {
			printf("\n");
		}
	} else {
		printf("\n");
	}
	// Baris 8
	if (SearchTree(P, X)) {
		Printlist(MakeListLevel(P, Level(P, X)));
	} else {
		printf("\n");
	}
	// Baris 9
	if (!SearchTree(P, X)) {
		AddDaunTerkiri(&P, X);
	}
	PrintPreorder(P);
	printf("\n");
	return 0;
}
