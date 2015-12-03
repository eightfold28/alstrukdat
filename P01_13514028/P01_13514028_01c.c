/*
	NIM/ Nama : 13514028/ Dharma Kurnia Septialoka
	Nama File : P01_13514028_01c.c
	Topik: Type Bentukan
	Tanggal: 28 Agustus 2015
	Deskripsi: Input : JamAwal, JamAKhir bertype Jam (HH:MM:DD); dan JamAkhir SELALU >= JamAwal
                Output : Selisih waktu dalam detik antara JamAwal dan JamAkhir
 */

/* Program DURASI
{ Input : JamAwal, JamAKhir bertype Jam (HH:MM:DD); dan JamAkhir SELALU >=  JamAwal
    Output : Selisih waktu dalam detik antara JamAwal dan JamAkhir } */

#include <stdio.h>

typedef struct {
	int hh, mm, dd;
} jam; //tipe bentukan

jam jamAwal, jamAkhir; //variabel jam

int main ()
{
	printf("Masukkan jam awal= \njam= "); //input jam awal
	scanf("%d", &jamAwal.hh);
	printf("menit= ");
	scanf("%d", &jamAwal.mm);
	printf("detik= ");
	scanf("%d", &jamAwal.dd);
	printf("Masukkan jam akhir= \njam= "); //input jam akhir
	scanf("%d", &jamAkhir.hh);
	printf("menit= ");
	scanf("%d", &jamAkhir.mm);
	printf("detik= ");
	scanf("%d", &jamAkhir.dd);
	printf("Maka durasinya= %d detik", (jamAkhir.hh * 3600 + jamAkhir.mm * 60 + jamAkhir.dd) - (jamAwal.hh * 3600 + jamAwal.mm * 60 + jamAwal.dd)); //output durasi
	return 0;
}