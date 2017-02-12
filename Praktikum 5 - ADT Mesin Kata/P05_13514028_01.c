#include "mesinkarakter.h"
#include "mesinkata.h"

/*
 * NIM/Nama  : 13514028/ Dharma Kurnia Septialoka
   	Nama file : mmesin1.c
   	Topik     : ADT Mesin kata
   	Tanggal   : 1 Oktober 2015
   	Deskripsi : Praktikum mesin kata
*/

int main() {
	int i;
	int KataReg, KataPanjang, biaya, jumlah;
	Kata KOMA;
	Kata TITIK;
	
	KOMA.Length= 4;
	KOMA.TabKata[1]= 'K';
	KOMA.TabKata[2]= 'O';
	KOMA.TabKata[3]= 'M';
	KOMA.TabKata[4]= 'A';
	
	TITIK.Length= 5;
	TITIK.TabKata[1]= 'T';
	TITIK.TabKata[2]= 'I';
	TITIK.TabKata[3]= 'T';
	TITIK.TabKata[4]= 'I';
	TITIK.TabKata[5]= 'K';
	
	START();
	Ignore_Blank();
	while ((!EndKata)&&(!EOP())) {
		ADVKATA();
		if (IsKataSama(CKata,TITIK)) {
			printf(".");
		} else
		if (IsKataSama(CKata,KOMA)) {
			printf(",");
		} else {
			for (i= 0; i<= CKata.Length; i++) {
			printf("%c", CKata.TabKata[i]);
			}
		}
		Ignore_Blank();
		printf(" ");
	}
	printf("\n");
	
	KataReg= 0;
	KataPanjang= 0;
	jumlah= 0;
	
	START();
	while (!EndKata) {
		SalinKata();
		if ((CKata.Length < 10) && (!IsKataSama(CKata, TITIK)) && (!IsKataSama(CKata, KOMA))) {
			KataReg += 1;
		} else if (CKata.Length >= 10) {
			KataPanjang += 1;
		}
		ADVKATA();
		jumlah += 1;
	}
	printf("Jumlah kata regular: %d\n", KataReg);
	printf("Jumlah kata panjang: %d\n", KataPanjang);
	
	if (jumlah > 10) {
		biaya= ((KataReg * 1000 + KataPanjang * 1500) * 0.9);
	} else {
		biaya= (KataReg * 1000 + KataPanjang * 1500);
	}
	printf("Biaya: %d\n", biaya);
	
	return 0;
}
	
	/*
	STARTKATA();
	while (!EndKata) {
		//for (i= 0; i<= CKata.Length; i++) {
			ADVKATA();
			if (IsKataSama(CKata, TITIK)) {
				printf(".");
				//ADVKATA();
			} else if (IsKataSama(CKata, KOMA)) {
				printf(",");
				//ADVKATA();
			} else {
				SalinKata();
				printf("%s", CKata.TabKata);
				//printf(" ");
			//printf("%c", CKata.TabKata[i]);
			}
			printf(" ");
		//ADVKATA();
		}
		
	
	return 0;
}
* */
	/*	
	START();
	Ignore_Blank();
	while ((!EndKata)&&(!EOP())) {
		ADVKATA();
		if (IsKataSama(CKata,KataWHILE)) {
			NWhile++;
		}
		Ignore_Blank();
	}
	printf("%d",NWhile);
	
	STARTKATA();
	while (!EndKata) {
		for (i= 0; i<= CKata.Length; i++) {
			printf("%c", CKata.TabKata[i]);
		}
		printf(" ");
		ADVKATA();
	}
	return 0;

}
*/
