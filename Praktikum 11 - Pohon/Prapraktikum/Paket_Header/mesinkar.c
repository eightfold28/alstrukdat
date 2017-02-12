/* NIM/Nama		:  */
/* Nama file	:  */
/* Topik		:  */
/* Tanggal		:  */
/* Deskripsi	:  */

#include "mesinkar.h"

char CC;
boolean EOP;

static int retval;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka 
		  EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true) */
	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
		  Jika  CC = MARK maka EOP akan menyala (true) */
	retval = scanf("%c",&CC);
	EOP = (CC == MARK);
}
