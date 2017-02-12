#include "mesinkata.h"

int main() {
	Kata KTitik, KKoma;
	int KReg, KPjg, biaya, i, countKata;
	boolean space, AkhirTelegram;
	
	KTitik.Length= 5;
	KTitik.TabKata[0]= 'T';
	KTitik.TabKata[1]= 'I';
	KTitik.TabKata[2]= 'T';
	KTitik.TabKata[3]= 'I';
	KTitik.TabKata[4]= 'K';
	
	KKoma.Length= 4;
	KKoma.TabKata[0]= 'K';
	KKoma.TabKata[1]= 'O';
	KKoma.TabKata[2]= 'M';
	KKoma.TabKata[3]= 'A';
	
	KReg= 0;
	KPjg= 0;
	countKata = 0;
	
	space= false;
	AkhirTelegram= false;
	
	STARTKATA();
	
	printf("Isi Telegram: ");
	if (CC == blank) {
		Ignore_Blank();
	}
	if ((CKata.Length == 0) && (CC == mark)) {
		AkhirTelegram= true;
	}
	while (!AkhirTelegram) {
		countKata+= 1;
		if (IsKataSama(CKata, KTitik)) {
			printf(".");
			space= false;
		} else if (IsKataSama(CKata, KKoma)) {
			printf(", ");
			space= false;
		} else {
			if (space== true) {
				printf(" ");
			} else {
				space= true;
			}
			for (i= 0; i < CKata.Length; i++) {
				printf("%c", CKata.TabKata[i]);
			}
			if (CKata.Length < 10) {
				KReg+= 1;
			} else if (CKata.Length >= 10) {
				KPjg+= 1;
			}
		}
		CKata.Length = 0;
		ADVKATA();
		Ignore_Blank();
		if (CC == mark) {
			EndKata= true;
		}
		if (EndKata) {
			AkhirTelegram= true;
		}	
	}
	if (CKata.Length > 0){
		countKata+= 1;
		if (IsKataSama(CKata, KTitik)) {
			printf(".");
			space= false;
		} else if (IsKataSama(CKata, KKoma)) {
			printf(", ");
			space= false;
		} else {
			if (space== true) {
				printf(" ");
			}
			for (i= 0; i < CKata.Length; i++) {
				printf("%c", CKata.TabKata[i]);
			}
			space= true;
			if (CKata.Length < 10) {
				KReg+= 1;
			} else if (CKata.Length >= 10) {
				KPjg+= 1;
			}
		}
	}		
	if (countKata <= 10) {
		biaya= (KReg * 1000) + (KPjg * 1500);
	} else if (countKata > 10){
		biaya= (((KReg * 1000) + (KPjg * 1500)) * 0.9);
	}
	printf("\nJumlah kata regular: %d\n", KReg);
	printf("Jumlah kata panjang: %d\n", KPjg);
	printf("Biaya: %d\n", biaya);
	return 0;
}
