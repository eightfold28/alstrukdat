#include "mesinkarakter.h"
#include "mesinkata.h"
#include <string.h>

/*
 * NIM/Nama  : 13514028/ Dharma Kurnia Septialoka
   	Nama file : mmesin1.c
   	Topik     : ADT Mesin kata
   	Tanggal   : 1 Oktober 2015
   	Deskripsi : Praktikum mesin kata
*/

	typedef struct {
		char tkn;
		int val;
	} TOKEN;
	
	TOKEN KataToTOKEN (Kata k) {
		int i;
		int a, nilai;
		TOKEN t;
		
		if( (k.Length > 1) || ('0'<= k.TabKata[0] && k.TabKata[0] <= '9') )
		{
			a = 1;
			nilai = 0;
			for( i = k.Length-1; i >= 0; i-- ) {
			if( '0'<= k.TabKata[i] && k.TabKata[i] <= '9' ){
				nilai += (k.TabKata[i]-'0') * a;
				a *= 10;
				}
			}
			t.tkn = 'b';
			t.val = nilai;
		}
		else {
			t.tkn = k.TabKata[0];
			t.val = -1;
		}
		return t;
	}

	void printToken(TOKEN t ){
	printf("<'%c', %d>\n", t.tkn, t.val );
	}

int main(){
	int c = 0;
	STARTKATA();
	while(!EndKata) {
		++ c;
		printToken( KataToTOKEN( CKata ));
		ADVKATA();
	}
	if( c != 0 ) {
		printToken( KataToTOKEN( CKata ));
	} 
	if( c == 0 ) printf("Ekspresi Kosong\n");
	return 0;
}

				

