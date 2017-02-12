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
	boolean fail;
	
	CreateEmpty(&S);
	fail= true;
	while (scanf("%c", &ch) == 1 && fail) {
			if (ch == '{') {
				Push(&S, X);
			} else if (ch == '}') {
				if (!IsEmpty(S)) {
					Pop(&S, &X);
				} else {
					fail= false;
				}
			}
	}
			
	if (IsEmpty(S) && fail) {
		printf("ok\n");
	} else {
		printf("salah\n");
	}
	return 0;
}
