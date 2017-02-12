#include "stack.h"
#include "mesintoken.h"

int main () {
	boolean AkhirInput;
	infotype X;
	Stack S;
	int i;
	
	CreateEmpty(&S);
	STARTKATA();
	AkhirInput= false;
	
	if (CC == blank) {
		Ignore_Blank();
	} 
	if ((CKata.Length == 0) && (CC == mark)) {
		AkhirInput= true;
		printf("EKSPRESI KOSONG\n");
	}
	/*
	while (!AkhirInput) {
		SalinKata();
		
		
		for (i=0; i<= CKata.Length; i++) {
			printf("%c", CKata.TabKata[i]);
		}
		
		
		CKata.Length= 0;
		ADVKATA();
		Ignore_Blank();
		if (CC == mark) {
			AKhirInput= true;
		}
	}
		
		
	}*/
	
}
