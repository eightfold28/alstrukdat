/* 
*	NIM/Nama	:
*	Nama file	:
*	Topik		:
*	Tanggal		:
*	Deskripsi 	:
*/

#include "mesinkarakter.h"

extern void START() {
/* 	I.S. sembarang
	F.S. CC adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
	scanf("%c",&CC);
}

extern void ADV() {
/*	I.S. CC!=mark
	F.S. CC adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila CC menunjuk 'I', maka CC berikutnya adalah 'F' 
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
	//ALGORITMA
	if (!EOP())
		scanf("%c",&CC);
}

extern boolean EOP() {
/*	true jika CC==mark */
	return (CC==mark);
}
