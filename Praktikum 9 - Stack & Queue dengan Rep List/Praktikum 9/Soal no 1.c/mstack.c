/* Nama/ NIM		: Dharma Kurnia Septialoka/ 13514028
 * Nama file		: stack.h
 * Topik		    : ADT LIST STACK
 * Tanggal		    : 3 November 2015
 * Deskripsi		: STACK dalam representasi list linier biasa
*/


#include "stack.h"

int main() {
	Stack S;
	char ch;
	Infotype X;
	boolean awal, ok;
	
	
	CreateEmpty(&S);
	awal= false;
	ok= true;
	while (scanf("%c", &ch) == 1) {
			if (ch == '{') {
				if (!awal && !IsEmpty(S)) {
					ok= false;
				}
				Push(&S, X);
				awal= true;
			} else if (ch == '}') {
				if (IsEmpty(S)) {
					ok= false;
				} else {
				Pop(&S, &X);
				ok= true;
				}
			} else if (ch == '.' || ch == ' ') {
				if (!awal && IsEmpty(S)) {
					ok= true;
				} else if (IsEmpty(S)) {
					ok= false;
				} else if (!IsEmpty(S)) {
					ok= true;
				}
			}
	}
			
	if (!IsEmpty(S)) {
		ok= false;
	}
	if (ok== true) {
		printf("ok\n");
	} else {
		printf("salah\n");
	}
	return 0;
}
