/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_02.c
	Topik: Batas nilai tipe dasar
	Tanggal: 28 Agustus 2015
	Deskripsi: melakukan pengetesan terhadap batas maksimum dan minimum nilai-nilai beberapa tipe dasar yang disediakan bahasa C dengan menggunakan beberapa konstanta yang didefinisikan dalam library limit.h
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

/*program batasNilai;
 {melakukan pengetesan terhadap batas maksimum dan minimum nilai-nilai beberapa tipe dasar yang disediakan bahasa C dengan menggunakan beberapa konstanta yang didefinisikan dalam library limit.h}
 */


int main ()
{
    //pengecekan integer
    printf("Maximum integer: %d\n", INT_MAX);
    printf("Minimum integer: %d\n", INT_MIN);
    //pengecekan short integer
    printf("Maximum short integer: %i\n", SHRT_MAX);
    printf("Minimum short integer: %i\n", SHRT_MIN);
    //pengecekan long integer
    printf("Maximum long integer: %ld\n", LONG_MAX);
    printf("Minimum long integer: %ld\n", LONG_MIN);
    //pengecekan unsigned
    printf("Maximum unsigned integer: %u\n", UINT_MAX);
    printf("Maximum unsigned short integer: %u\n", USHRT_MAX);
    printf("Maximum unsigned long integer: %lu\n", ULONG_MAX);
    //pengecekan karakter
    printf("Maximum character: %d\n", CHAR_MAX);
    printf("Minimum character: %d\n", CHAR_MIN);
    printf("Maximum signed character: %d\n", SCHAR_MAX);
    printf("Minimum signed character: %d\n", SCHAR_MIN);
    printf("Maximum unsigned character: %d\n", UCHAR_MAX);
    //pengecekan float
    printf("Maximum float: %e\n", FLT_MAX);
    printf("Minimum float: %e\n", FLT_MIN);
    printf("Maximum double float: %le\n", DBL_MAX);
    printf("Minimum double float: %le\n", DBL_MIN);
    printf("Maximum long double float: %Le\n", LDBL_MAX);
    printf("Minimum long double float: %Le\n", LDBL_MIN);
    return 0;
}