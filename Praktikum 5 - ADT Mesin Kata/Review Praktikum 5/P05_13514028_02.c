/*
*	NIM/Nama 	: 13514028/ Dharma Kurnia Septialoka
*	Nama file 	: msoal2.c
*	Topik 		: Mesin Karakter & Mesin Kata
*	Tanggal 	: 8 Oktober 2015
*	Deskripsi 	: Mesin Token
*/

#include "mesinkata.h"
#include <math.h>

int power(int a, int b);
int charToInt(Kata CKata);
int cToInt(char x);

typedef struct {
	char tkn;
	int val;
} TOKEN;

TOKEN CT;

int main()
{	
	/* KAMUS */

	/* ALGORITMA */
	
	//Inisialisasi nKReg, nKPjg, dan biaya
	
	STARTKATA();
	if (EndKata)
		printf("Ekspresi Kosong\n");
	else
	{
		do
		{
			if (CKata.TabKata[0] == '*')
			{
				CT.tkn = '*';
				CT.val = -1;
			}
			else if (CKata.TabKata[0] == '+')
			{
				CT.tkn = '+';
				CT.val = -1;
			}
			else if (CKata.TabKata[0] == '-')
			{
				CT.tkn = '-';
				CT.val = -1;
			}
			else if (CKata.TabKata[0] == '/')
			{
				CT.tkn = '/';
				CT.val = -1;
			}
			else if (CKata.TabKata[0] == '^')
			{
				CT.tkn = '^';
				CT.val = -1;
			}
			else
			{
				CT.tkn = 'b';
				CT.val = charToInt(CKata);
			}
			printf("<'%c', %d>\n", CT.tkn, CT.val);
			ADVKATA();
			if (EndKata)
			{
				if (CKata.TabKata[0] == '*')
				{
					CT.tkn = '*';
					CT.val = -1;
				}
				else if (CKata.TabKata[0] == '+')
				{
					CT.tkn = '+';
					CT.val = -1;
				}
				else if (CKata.TabKata[0] == '-')
				{
					CT.tkn = '-';
					CT.val = -1;
				}
				else if (CKata.TabKata[0] == '/')
				{
					CT.tkn = '/';
					CT.val = -1;
				}
				else if (CKata.TabKata[0] == '^')
				{
					CT.tkn = '^';
					CT.val = -1;
				}
				else
				{
					CT.tkn = 'b';
					CT.val = charToInt(CKata);
				}
				printf("<'%c', %d>\n", CT.tkn, CT.val);
			}
		} while (!EndKata);
	}
	
	return 0;
}

int charToInt(Kata CKata)
{
	/* KAMUS LOKAL */
	int i;
	int result;
	
	/* ALGORITMA */
	result = 0;
	for (i = CKata.Length -1; i >= 0; i--)
	{
		result += pow(10, (CKata.Length-1)-i) * cToInt(CKata.TabKata[i]);
	}
	return result;
}

int cToInt(char x)
{
	if (x == '1')
		return 1;
	else if (x ==  '2')
		return 2;
	else if (x ==  '3')
		return 3;
	else if (x ==  '4')
		return 4;
	else if (x ==  '5')
		return 5;
	else if (x ==  '6')
		return 6;
	else if (x ==  '7')
		return 7;
	else if (x ==  '8')
		return 8;
	else if (x ==  '9')
		return 9;
	else if (x ==  '0')
		return 0;
	else
		return -1;
}
