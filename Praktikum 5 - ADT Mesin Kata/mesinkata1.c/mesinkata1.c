
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "string.h"

//definisi state mesin kata
extern boolean EndKata;
extern Kata	CKata;
extern char CC;

/*
	DESKRIPSI

	Buatlah mesin kata yang mengakuisisi input sampai ditemukan mark (end).
	Input akan di-supply dari standard input-output dalam bahasa C (stdin), contoh input adalah
	"praktikum if2110."
	"   praktikum     if2110    ."
	Dijamin selalu terdapat tanda akhir input yaitu mark "." pada akhir input
	Input merupakan kombinasi karakter yang merupakan anggota dari {a-z, A-Z, 0-9, ' ', '.'}

	[ATTENTION]
	Ikutilah Header ini karena telah disesuaikan untuk autograding

*/

/* Primitif-primitif mesin kata */
void Ignore_Blank(){
/*	Mengabaikan satu atau beberapa BLANK
	I.S. : CC sembarang
	F.S. : CC != BLANK atau CC == MARK
*/
    while( !EOP() && CC == blank ) ADV();
    if( EOP() ) EndKata = true;
}

void STARTKATA(){
/*	I.S. : CC sembarang
	F.S  : Salah satu dari dua kondisi dibawah.
		1. EndKata = true dan CC == Mark
		2. EndKata = false, CKata adalah kata yang sudah diakuisisi, dan CC adalah satu karakter setelah karakter terakhir kata

		Keterangan: CC mengacu pada yang disebut pada mesinkarakter
*/
    START();
    if(EOP()){
        EndKata = true;
    }
    else {
        EndKata = false;
        ADVKATA();
    }
}

void ADVKATA(){
/*	I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
	dari kata yg sudah diakuisisi
	F.S. : Jika CC == MARK, maka EndKata == true
	atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
	CC karakter pertama sesudah karakter terakhir kata
*/
    Ignore_Blank();
    SalinKata();
    if( EOP() ) EndKata = true;
}

void SalinKata(){
/*	Mengakuisisi kata, menyimpan dalam CKata
	I.S. : CC adalah karakter pertama dari kata
	F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
	NMax, sisa "kata" dibuang; CC == BLANK atau CC == MARK; CC adalah
	karakter sesudah karakter terakhir yang diakuisisi
*/
    CKata.Length = 0;
    CKata.TabKata[0] = '\0';

    while( !EOP() && CC != blank ){
        if( CKata.Length < NMax ){
            CKata.TabKata[CKata.Length] = CC;
            CKata.TabKata[CKata.Length+1] = '\0';
            CKata.Length++;
        }

        ADV();
    }
}

/* Operasi Lain */
boolean IsKataSama(Kata K1, Kata K2){
/*	Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
	urutan karakter yang menyusun kata juga sama. Sensitif terhadap uppercase dan lowercase
*/
    int i;

    if( K1.Length != K2.Length )
        return false;

    for( i = 0; i < K1.Length; ++ i){
        if( K1.TabKata[i] != K2.TabKata[i]) return false;
    }

    return true;
}

