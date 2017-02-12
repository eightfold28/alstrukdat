/* 
*	NIM/Nama 	:
*	Nama file 	:
*	Topik 		:
*	Tanggal 	:
*	Deskripsi 	:
*/

#include "mesintoken.h"

//primitif-primitif mesin token
void Ignore_Blank() {
/*	Mengabaikan satu atau beberapa BLANK
	I.S. : CC sembarang
	F.S. : CC != BLANK atau CC == MARK
*/
	//ALGORITMA
	while (!EOP() && (CC==blank)) {
		ADV();
	}
	if (EOP())
		EndKata=true;
}

void STARTKATA() {
/*	I.S. : CC sembarang
	F.S  : Salah satu dari dua kondisi dibawah.
		1. EndKata = true dan CC == Mark
		2. EndKata = false, CKata adalah kata yang sudah diakuisisi, dan CC adalah satu karakter setelah karakter terakhir kata

		Keterangan: CC mengacu pada yang disebut pada mesinkarakter
*/
	//ALGORITMA
	START();
	if (!EOP()) {
		EndKata=false;
		Ignore_Blank();
		SalinKata();
	}
	else {
		EndKata=true;
	}
}

void ADVKATA() {
/*	I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
	dari kata yg sudah diakuisisi
	F.S. : Jika CC = MARK, maka EndKata = true
	atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
	CC karakter pertama sesudah karakter terakhir kata
*/
	//ALGORITMA
	if (CC==mark) {
		EndKata=true;
		int i;
		for (i=0; i<CKata.Length; i++)
			CKata.TabKata[i]='\0';
	}
	else {
		Ignore_Blank();
		SalinKata();
	}
}

void SalinKata() {
/*	Mengakuisisi kata, menyimpan dalam CKata
	I.S. : CC adalah karakter pertama dari kata
	F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
	NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
	karakter sesudah karakter terakhir yang diakuisisi
*/
	//KAMUS LOKAL
	int i;
	//ALGORITMA

	//reset CKata terlebih dahulu
	for (i=0; i<NMax; i++)
		CKata.TabKata[i]='\0';
	CKata.Length=0;
	while (!EOP() && (CC!=blank)) {
		if (CKata.Length<NMax) {
			CKata.Length+=1;
			CKata.TabKata[CKata.Length-1] = CC;
		}
		ADV();
	}
	if (EOP())
		EndKata = true;
}

//operasi lain
boolean IsKataSama(Kata K1, Kata K2) {
/*	Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
	urutan karakter yang menyusun kata juga sama. Sensitif terhadap uppercase dan lowercase
*/
	//KAMUS LOKAL
	int i;
	//ALGORITMA
	if (K1.Length==K2.Length) {
		i=0;
		while ((i<K1.Length) && (K1.TabKata[i]==K2.TabKata[i])) {
			i++;
		}
		if (i==K1.Length) return true;
		else return false;
	}
	else return false;
}

boolean IsBilangan(Kata CKata) {
/* Mengembalikan true bila CKata adalah bilangan, false bila CKata bukan merupakan bilangan (berarti merupakan tanda operasi aritmatika)
*/
	if (CKata.Length==0)
		return false;
	else if (CKata.Length==1) 
	{
		if (CKata.TabKata[0]=='^' || CKata.TabKata[0]=='+' || CKata.TabKata[0]=='-' || CKata.TabKata[0]=='*' || CKata.TabKata[0]=='/')
			return false;
		else 
			return true;
	}
	else //pasti merupakan bilangan bila panjangnya lebih dari 1
		return true;
}

int ConvertToBilangan(Kata CKata) {
/*	Mengembalikan nilai bilangan dari CKata
*/
	int i;
	int total = 0;
	for (i=0; i<CKata.Length; i++)
	{
		if (i>0)
			total *= 10;
		total = total + (CKata.TabKata[i]-'0');
	}
	return total;

}

char GetOperatorAritmatika(Kata CKata) {
/*	Mengembalikan operator aritmatika
	I.S. : Ckata bukan merupakan bilangan
*/
	return CKata.TabKata[0];
}